/*
 * C言語のサンプルプログラム - Webkaru
 * - 2進数の10進数の変換 -
 * 参考：https://webkaru.net/clang/binary-to-decimal/
 */
#include <stdio.h>
// #include <math.h>
#include <stdlib.h>
// #include <conio.h>
#include <string.h>
// #include <time.h>
#include <unistd.h>

 void dispTopWindow(void);
 int selectMode(void);
 void mode1(void);
 void mode2(void);
 void wait(void);
 int beki(int, int);
 
int main(void)
{
    int mode = 0;

    while(1)
    {
        dispTopWindow();
        mode = selectMode();

        if(mode==0) // プログラムの終了
        {
            exit(1);
        }
        else if(mode==1) // 2進数→10進数
        {
            system("cls");
            mode1();
        }
        else if(mode==2) // 10進数→2進数
        {
            system("cls");
            mode2();
        }

        // 画面のリセット
        system("cls");
    }
 
    return 0;
}

// トップ画面の表示
void dispTopWindow(void)
{
    printf("==============================================================\n");
    printf("This program can convert binary numbers and decimal numbers.\n");
    printf("==============================================================\n");
    printf("Please select mode.\n");
    printf("1. Convert binary number to decimal number\n");
    printf("2. Convert decimal number to binary number\n");
    printf("0. Exit program\n");
    printf("\n");
}

// モード選択
// 注意：文字は0に変換される
int selectMode(void)
{
    int mode = 0;
    printf(">> ");
	scanf("%d", &mode);
	return mode;
}

// 2進数→10進数
void mode1(void)
{
    int binary;
    int decimal;
    int base;
    int flag;
    char header1;
    char header2;
    char str[256];
    char emzansi;
    int res;

    printf("Enter binary number.\n");
    printf("If you wanna exit this mode, enter temp.\n");

    while(1)
    {
        // 2進数の入力
        printf("Enter binary number  = ");

        // scanf("%s %c", str, &emzansi);
        // printf("%s\n", str);
        // printf("%c\n", emzansi);

        scanf("%s", str);
        printf("%s\n", str);

        // mode1の終了
        if(strncmp("q", &str[0], 1)==0)
        {
            break;
        }

        // エラーチェック
        // ２文字以下
        if(strlen(str)<=2)
        {
            printf("Check the formats.\n");
            continue;
        }

        // フォーマットに従っているのか？
        if(strncmp("0", &str[0], 1)!=0)
        {
            printf("str[0] Check the formats.\n");
            continue;
        }
        if(strncmp("b", &str[1], 1)!=0)
        {
            printf("str[1] Check the formats.\n");
            continue;
        }
        for (int i=2; i<strlen(str); i++)
        {
            if(strncmp("0", &str[i], 1)!=0 && strncmp("1", &str[i], 1)!=0)
            {
                printf("Check the formats.\n");
                continue;
            }
        }

        // 2進数から10進数への変換
        res = 0;
        for (int i=2; i<strlen(str); i++)
        {
            res = res + beki(2, strlen(str)-i-1);
        }

        printf("%d\n", res);

    }
}

// 10進数→2進数
void mode2(void)
{
    int binary;
    int decimal = 0;
    int base = 1;

    /* 2進数の入力 */
    // printf("If you wanna exit this mode, enter 2.\n");
    printf("Enter binary number  = ");
    scanf("%d", &binary);

    /* 2進数を10進数に変換 */
    while(binary>0){
        decimal = decimal + ( binary % 10 ) * base;
        binary = binary / 10;
        base = base * 2;
    }

    /* 変換した2進数の出力 */
    printf("Decimal number = %d\n", decimal);
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
