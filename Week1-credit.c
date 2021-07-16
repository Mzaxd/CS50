#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i;
    int j;              //余数
    long n;
    int count = 0;      //numeber的位数
    int sum1 = 0;       //倒数第二位开始运算后的和
    int sum2 = 0;       //倒数第一位开始
    int sum3 = 0;
    

    long number = get_long("Number:");
    n = number;

    for (count = 0; number > 0; count++)       //获取number的位数
    {
        number /= 10;
    }
    number = n;     //恢复number的数值


    number /= 10;                //倒数第二位数字
    j = 2 * (number % 10);
    if (j < 10)         //判断乘以2的数是否为2位数
    {
        sum1 += j;
    }
    else
    {
        sum1 += j % 10;
        sum1 += (j / 10) % 10;
    }


    while (number > 0)        //对每隔2位求和
    {
        number /= 100;
        j = 2 * (number % 10);      //乘2
        
        if (j < 10)         //判断乘以2的数是否为2位数
        {
            sum1 += j;
        }
        else
        {
            sum1 += j % 10;
            sum1 += (j / 10) % 10;
        }
    }
    number = n;     //恢复number的数值


    j = n % 10;
    sum2 += j;
    while (number > 0)        //对每隔2位求和
    {
        number /= 100;
        j = number % 10;
        sum2 += j;      
    }
    number = n;

    
    if ((sum1 + sum2) % 10 == 0)      //输出结果
    {
        while (number > 10)              //Visa
        {
            number /= 10;
            j = number % 10;
        }
        if (j == 4)
        {
            printf("Visa\n");
        }
        else
        {
            number = n;                      //如果卡号由奇数个数字组成 则无法使用下面的算法 所以需要将奇数个转化为偶数个
            if (count % 2 != 0)
            {
                number /= 10;
            }
            
            while (number > 100)
            {
                number /= 100;
            }
            if (number == 34 || number == 37)       //AMEX
            {
                printf("AMEX\n");
            }
            if (number >= 51 && number <= 55)       //MasterCard
            {
                printf("MasterCard\n");
            }
            else
            {
                printf("Other Bank\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
