/* Page. 95, Exercise 4-8-03.c */
#include <stdio.h>

void (*execute_func)(int *, int);

void bubblesort(int *data, int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}


void insert_sort(int a[],int n)//n为数组a的元素个数
{
    //进行N-1轮插入过程
    for(int i=1; i<n; i++)
    {
        //首先找到元素a[i]需要插入的位置
        int j=0;
        while( (a[j]<a[i]) && (j<i))
        {
            j++;
        }
        //将元素插入到正确的位置
        if(i != j)  //如果i==j，说明a[i]刚好在正确的位置
        {
            int temp = a[i];
            for(int k = i; k > j; k--)
            {
                a[k] = a[k-1];
            }
            a[j] = temp;
        }
    }
}


int main()
{
    int i, n, data[10];
    printf("請輸入資料筆數 n(<= 10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("請輸入第 %d 筆資料: ", i + 1);
        scanf("%d", &data[i]);
    }

    // 執行氣泡排序法
//    bubblesort(data, n);
    execute_func = bubblesort;
    execute_func(data, n);
    printf("\nbubble sort 排序後的結果: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    // execute insert sort.
//    insert_sort(data, n);
    execute_func = insert_sort;
    execute_func(data, n);
    printf("\ninsert sort 排序後的結果: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
}

