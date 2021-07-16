#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    int j;
    int l;
    int k;

    do
    {    
        k = get_int("Height(1~8):");
    }
    while( k < 1 || k > 8); 
    
    for (i = 1; i <= k; i++) //最外层循环次数(即打印行数)
    {
        for (j = 0 ;j < k-i ; j++) //打印空格
        {
            printf(" ");
        }
        for (l = 0 ; l < i ; l++) //打印#
        {   
            printf("#");
        }
        printf("\n");
    }
}
