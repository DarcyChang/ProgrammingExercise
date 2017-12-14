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


    /* Release table */
    sqlite3_free_table(result);    
    sqlite3_free(errMsg);   
    /* Close database */
    sqlite3_close(hostname_db);

	printf("\n");
}

int main(void)
{
	sqlite3 *hostname_db;
    sqlite3_stmt *stmt = NULL;
	int rc;
	char sqlcmd[512] = "";
    char *errMsg = NULL;
    
	char ip[128]="192.168.1.200";
	char hostname[128]="cy";
	int timeout = 100;
	char time[128] = "none";

	/* Open database */
    if(sqlite3_open_v2(HOSTNAME_DB_PATH, &hostname_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL)) {
        return -1;
    }

    /* Create table */
    sqlite3_exec(hostname_db, resultTB, 0, 0, &errMsg);
	
	snprintf(sqlcmd,512,"INSERT INTO result (ipv4, hostname, timeout, date) VALUES('%s', '%s', %d, '%s');", ip, hostname, timeout, time);
	
	sqlite3_prepare_v2(hostname_db,sqlcmd,strlen(sqlcmd), &stmt, NULL);

    sqlite3_step(stmt);
   	sqlite3_memory_used();
	sqlite3_reset(stmt);
	sqlite3_finalize(stmt);

    /* Close database */
    sqlite3_close(hostname_db);
		
	time_count();

	printf("\n");
	return 0;
}
