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

void dispTopWindow(void);
int retBinary(char[]);
int beki(int, int);
void mode1(void);

int main(void)
{

    dispTopWindow();
    mode1();

    return 0;
}


// トップ画面の表示
void dispTopWindow(void)
{
    printf("==============================================================\n");
    printf("This program binary number calculator.\n");
    printf("==============================================================\n");
    printf("\n");
    printf("This can be binary addition, subtraction, multiplication and division.\n");
    printf("e.g. 0b11+0b01\n");
    printf("\n");
    printf("Enter q, if you wanna exit program.\n");
    // printf("\n");
    // printf("Please enter the formula.\n");
    // printf("\n");
}


// 2進数→10進数
void mode1(void)
{
    char str[256];
    char emzansi;
    int res;
    int num1, num2;
    int c;
    int flag;

    while(1)
    {
        emzansi = 'a';
        flag = 0;

        // 2進数の入力
        printf("\n");
        printf("Please enter the formula.\n");
        printf("-> ");
        scanf("%s", str);

        // mode1の終了
        if(strncmp("q", &str[0], 1)==0)
        {
            break;
        }

        // エラーチェック
        // strについて
        // ２文字以下
        if(strlen(str)<=2)
        {
            printf("Check the formats.\n");
            continue;
        }

        // オペランド1
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

        c = 2;
        for (int i=2; i<strlen(str); i++)
        {
            if(strncmp("0", &str[i], 1)!=0 && strncmp("1", &str[i], 1)!=0)
            {
                emzansi = str[i];
                break;
            }
            c++;
        }

        // printf("emzansi=%c\n", emzansi);

        if(strncmp("+", &emzansi, 1)!=0 &&
           strncmp("-", &emzansi, 1)!=0 &&
           strncmp("*", &emzansi, 1)!=0 &&
           strncmp("/", &emzansi, 1)!=0)
        {
             printf("Error of operator!!\n");
            continue;
        }

        // 2進数から10進数への変換
        num1 = 0;
        for (int i=2; i<c; i++)
        {
            num1 = num1 + (str[i]-'0')*beki(2, c-i-1);
        }
        // printf("num1=%d\n", num1);

        // オペランド2
        // フォーマットに従っているのか？
        if(strncmp("0", &str[c+1], 1)!=0)
        {
            printf("Check the formats.\n");
            continue;
        }
        if(strncmp("b", &str[c+2], 1)!=0)
        {
            printf("Check the formats.\n");
            continue;
        }

        for (int i=c+3; i<strlen(str); i++)
        {
            if(strncmp("0", &str[i], 1)!=0 && strncmp("1", &str[i], 1)!=0)
            {
                printf("Check the formats.\n");
                flag = 1;
                continue;
            }
        }
        if(flag==1)
        {
            break;
        }

        // 2進数から10進数への変換
        // printf("c=%d\n", c);
        num2 = 0;
        for (int i=c+3; i<strlen(str); i++)
        {
            // printf("%c\n", str[i]);
            num2 = num2 + (str[i]-'0')*beki(2, strlen(str)-i-1);
        }
        // printf("num2=%d\n", num2);

        switch (emzansi)//演算記号の違いにより数式をつくる//
		{
		case '+': res = num1 + num2; break;
		case '-': res = num1 - num2; break;
		case '*': res = num1 * num2; break;
		case '/': if (num2 == 0.0)//ゼロ割の防止//
		{
            printf("Error of 1 division!!\n");
            continue;
		}
			res = num1 / num2; break;
		default: 
            printf("Error of operator!!\n");//演算記号がおかしいときにエラーを返す//
			continue;
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
