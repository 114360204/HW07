#define _CRT_SECURE_NO_WARNINGS  /* 解決 Visual Studio fopen 安全性警告 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr1, * fptr2; // 宣告指向檔案的指標 fptr1 與 fptr2
    char ch;

    fptr1 = fopen("welcome.txt", "r");  // 開啟可讀取的檔案
    fptr2 = fopen("output.txt", "w");   // 開啟可寫入的檔案

    if ((fptr1 != NULL) && (fptr2 != NULL)) // 如果開檔成功
    {
        while ((ch = getc(fptr1)) != EOF)   // 判斷是否到達檔尾
        {
            putc(ch, fptr2); // 將字元 ch 寫到 fptr2 所指向的檔案
        }

        fclose(fptr1); // 關閉 fptr1 所指向的檔案
        fclose(fptr2); // 關閉 fptr2 所指向的檔案
        printf("檔案拷貝完成!!\n");
    }
    else
    {
        printf("檔案開啟失敗!!\n");
    }

    system("pause");
    return 0;
}