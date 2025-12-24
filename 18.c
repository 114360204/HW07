#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* in, * out;    // 宣告指向檔案的指標 in 與 out
    int cnt;           // 用於存放讀取到的欄位數
    char str[100];     // 宣告字元陣列用來暫存讀取的字串

    in = fopen("welcome.txt", "r");    // 以唯讀模式開啟來源檔
    out = fopen("output.txt", "w");    // 以寫入模式開啟輸出檔

    while (!feof(in))  // 判斷是否到達來源檔的檔尾
    {
        // 使用 fscanf 讀取一個字串，它會以空格、標點符號或換行作為分隔
        cnt = fscanf(in, "%s", str); // 讀取檔案

        if (cnt > 0)
        {
            // 使用 fprintf 將字串寫入檔案，並在每個單字後換行 (\n)
            fprintf(out, "%s\n", str); // 寫入檔案
        }
    }

    fclose(in);        // 關閉來源檔
    fclose(out);       // 關閉輸出檔

    system("pause");
    return 0;
}