#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i;
    int j;
    if (argc != 2)                                 //判断输入的数量
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    int n = strlen(argv[1]);                      //key字符串长度
    for (i = 0; i < n; i++)                       //判断输入的是否是英文
    {
        if (argv[1][i] < 'A')
        {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
        if ((argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
        {
            printf("Usage: ./vigenere key\n");
            return 1;    
        }
    }


    char plaintext[50] = {0};
    char ciphertext[50] = {0};
    printf("plaintext: ");
    scanf("%[^\n]", plaintext);             //保证scanf能够收入空格

    for (i = 0; i < n; i++)
    {
        if (argv[1][i] >= 'a')
        {
            argv[1][i] = argv[1][i] - 'a';
        }
        else
        {   
            argv[1][i] = argv[1][i] - 'A';
        }
    }


    for (i = 0, j = 0; i < strlen(plaintext); i++)
    {
        if (j == n)
        {
            j = 0;
        }
        if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z'))
        {
            ciphertext[i] = 'A' + (plaintext[i] - 'A' + argv[1][j]) % 26;
            j++;
        }
        else if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z'))
        {
            ciphertext[i] = 'a' + (plaintext[i] - 'a' + argv[1][j]) % 26;
            j++;
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    

    printf("ciphertext:%s\n", ciphertext);
    return 0;
}
