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

    printf("Enter binary number.\n");
    printf("If you wanna exit this mode, enter temp.\n");

    while(1)
    {
        // 2進数の入力
        printf("Enter binary number  = ");
        // scanf("%c%c%d", &header1, &header2, &binary);
        scanf("%s", str);

        // エラーチェック
        // flag = 0;
        if(str[0]!='0')
        {
            printf("Check the formats.\n");
            // flag = 1;
        }
        if(str[1]!='b')
        {
            printf("Check the formats.\n");
            // flag = 1;
        }
        for (int i=2; i<strlen(str); i++)
        {
            if(str[i]!='0' || str[i]!='1')
            {
                printf("Check the formats.\n");
                // flag = 1;
            }
        }

        // sleep(10);

        // if(flag==1){ break; }

        

        // if(header1!='0'){ break; }
        // if(header2!='b'){ break; }

        // // 2進数を10進数に変換
        // decimal = 0;
        // base = 1;

        // while(binary>0)
        // {
        //     decimal = decimal + ( binary % 10 ) * base;
        //     binary = binary / 10;
        //     base = base * 2;
        // }

        // // 変換した2進数の出力
        // printf("Decimal number = %d\n", decimal);
        // printf("\n");
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

// //画面を入力があるまでとめる//
// void wait()
// {
// 	while (1)
// 	{
// 		if (kbhit())//キーボードの入力をまつ//
// 		{
// 			break;
// 		}
// 	}
// }
