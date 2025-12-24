#define _CRT_SECURE_NO_WARNINGS  /* 解決 Visual Studio 安全性警告 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define ENTER 13
#define MAX 80

int main(void)
{
    FILE* fptr;
    char str[MAX], ch; // 宣告字元陣列 str，用來儲存由鍵盤輸入的字串
    int i = 0;

    // 以附加模式 ("a") 開啟檔案，若檔案不存在則會建立新檔
    fptr = fopen("output.txt", "a");

    printf("請輸入字串，按ENTER鍵結束輸入：\n");

    // 當按下的鍵不是 ENTER 且長度小於 MAX 時繼續讀取
    while ((ch = _getche()) != ENTER && i < MAX)
    {
        str[i++] = ch; // 一次增加一個字元到字元陣列 str 中
    }

    putc('\n', fptr); // 寫入換行字元
    fwrite(str, sizeof(char), i, fptr); // 將陣列內容寫入檔案

    fclose(fptr); // 關閉檔案
    printf("\n檔案附加完成!!\n");

    system("pause");
    return 0;
}