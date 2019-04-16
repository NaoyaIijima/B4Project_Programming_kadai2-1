/*
 * C言語のサンプルプログラム - Webkaru
 * - 2進数の10進数の変換 -
 * 参考：https://webkaru.net/clang/binary-to-decimal/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void mode1(void);
int beki(int, int);
 
 // main関数
int main(void)
{
    mode1();
 
    return 0;
}

// 2進数→10進数
void mode1(void)
{
    char str[256];
    char emzansi;
    int res;
    int flag;

    printf("Enter binary number.\n");
    printf("The format is 0bxxxx.\n");
    printf("\n");
    printf("Enter q, if you wanna exit this program.\n");

    while(1)
    {
        flag = 0;

        // 2進数の入力
        printf("\n");
        printf("Enter binary number  = ");

        scanf("%s", str);

        // mode1の終了
        if(strncmp("q", &str[0], 1)==0)
        {
            break;
        }

        // エラーチェック
        // ２文字以下
        if(strlen(str)<=2)
        {
            printf("Input binary number is too short.\n");
            continue;
        }

        // フォーマットに従っているのか？
        if(strncmp("0", &str[0], 1)!=0)
        {
            printf("Check the formats.\n");
            continue;
        }
        if(strncmp("b", &str[1], 1)!=0)
        {
            printf("Check the formats.\n");
            continue;
        }
        for (int i=2; i<strlen(str); i++)
        {
            if(strncmp("0", &str[i], 1)!=0 && strncmp("1", &str[i], 1)!=0)
            {
                printf("Check the formats.\n");
                flag = 1;
                break;
            }
        }

        if(flag==1)
        {
            continue;
        }

        // 2進数から10進数への変換
        res = 0;
        for (int i=2; i<strlen(str); i++)
        {
            res = res + (str[i]-'0')*beki(2, strlen(str)-i-1);
        }

        printf("= %d\n", res);

    }
}

// 累乗の計算
// math.hのpowで実装されているが，double型で返されるため作った
int beki(int tei, int sisu)
{
    int res = 1;
    for(int i=0; i<sisu; i++)
    {
        res = res * tei;
    }
    return res;
    
}
