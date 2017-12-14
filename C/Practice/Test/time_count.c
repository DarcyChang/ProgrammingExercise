#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sqlite3.h>


static char *resultTB = "CREATE TABLE result ("
            "ipv4 VARCHAR(256),"
            "hostname VARCHAR(256),"
            "timeout INTEGER,"
            "date VARCHAR(256));";

#define HOSTNAME_TIMEOUT "./tmp"
#define HOSTNAME_DB_PATH "./hostname.db"
#define request_time 6

void time_count()
{
    sqlite3 *hostname_db;
    char sqlcmd[512] = "SELECT * FROM result;";
    char *errMsg = NULL;
    int row=0, column=0;
    char **result;
    int i = 0;

    if(sqlite3_open_v2(HOSTNAME_DB_PATH, &hostname_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)) {
        return ;
    }

    sqlite3_exec(hostname_db, resultTB, 0, 0, &errMsg);

	
	/* Get all hostname from result table */
    sqlite3_get_table(hostname_db, sqlcmd, &result, &row, &column, &errMsg);
//	printf( "row:%d column=%d \n" , row , column );
    printf("%-15s | %-35s | %-7s | %s\n", result[0], result[1], result[2], result[3]);
    printf("-------------------------------------------------------------------------------------------\n");
    for( i=4 ; i<( row + 1 ) * column ; i+=4 )
        printf( "%-15s | %-35s | %-7d | %s\n", result[i], result[i+1], atoi(result[i+2]), result[i+3]);

	int *tmp;
	int tmp2=0;
	for( i=4 ; i<( row + 1 ) * column ; i+=4 ){
        printf("TEST before result[%d] = %d\n", i+2, atoi(result[i+2]));
//      (result[i+2])--;
//      printf("TEST for result[%d] = %d\n", i+2, result[i+2]--);
//      printf("TEST for result[%d] = %d\n", i+2, (result[i+2])--);
//      printf("TEST for result[%d] = %d\n", i+2, atoi(result[i+2])--);
        printf("TEST after result[%d] = %d\n", i+2, atoi(result[i+2]));
//        tmp=result[i+2];
		tmp2 = atoi(result[i+2]);
		tmp2--;
//        printf("TEST tmp = %d\n", (*tmp)-1);
//        printf("TEST tmp2 = %d\n", tmp2=tmp2-1);
        sprintf(sqlcmd,"UPDATE result set timeout=%d ,date='%s' where ipv4='%s' and hostname='%s';", tmp2,"aaa",result[i],result[i+1]);
        sqlite3_exec(hostname_db, sqlcmd, 0, 0, &errMsg);

      if(atoi(result[i+2]) % request_time ==0 && atoi(result[i+2]) != 0){
          printf("hostnamelookup_compare(result[i], result[i+1])\n");
		
      }else if(atoi(result[i+2])==0){

//        if(atoi(result[i+2])==0){
            sprintf(sqlcmd, "DELETE FROM result where ipv4='%s' ;", result[i]);
            sqlite3_exec(hostname_db, sqlcmd, 0, 0, &errMsg);
        }
    }

	printf("\n");
}

int main(void)
{


    sqlite3 *hostname_db;
    char sqlcmd[512] = "";
    char *errMsg = NULL;
    
	char ip[128]="192.168.1.101";
	char hostname[128]="darcy";
	int timeout = 10;
	char time[128] = "none";

	sqlite3_stmt *stmt = NULL;

	
	/* Open database */
    if(sqlite3_open_v2(HOSTNAME_DB_PATH, &hostname_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)) {
        return -1;
    }

    /* Create table */
    sqlite3_exec(hostname_db, resultTB, 0, 0, &errMsg);
	
	sqlite3_prepare_v2(hostname_db,"INSERT INTO result (ipv4, hostname, timeout, date) VALUES('%s', '%s', %d, '%s');", ip, hostname, timeout, time);

        sqlite3_step(stmt);
        sqlite3_reset(stmt);

	sqlite3_finalize(stmt);
//	sprintf(sqlcmd, "INSERT INTO result (ipv4, hostname, timeout, date) VALUES('%s', '%s', %d, '%s');", ip, hostname, timeout, time);
//    sqlite3_exec(hostname_db, sqlcmd, 0, 0, &errMsg);


    /* Close database */
    sqlite3_close(hostname_db);
		


	while(1)
	{
		time_count();
		sleep(1);
	}

	printf("\n");
	return 0;
}
