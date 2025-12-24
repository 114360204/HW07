#include <stdio.h>
#include <stdlib.h>

struct clientData
{
    int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void)
{
    FILE* pRead, * pWrite;
    FILE* cfPtr;
    int cnt = 0;
    struct clientData client = { 0, "", "", 0.0 };

    // 1. 開啟原始文字檔進行讀取
    pRead = fopen("./credit.txt", "r");
    if (NULL == pRead)
    {
        return 0;
    }

    // 2. 開啟二進位檔進行寫入 ("wb" 模式)
    pWrite = fopen("./credit_bin.txt", "wb");
    if (NULL == pWrite)
    {
        fclose(pRead);
        return 0;
    }

    // 3. 從文字檔讀取資料，並同時寫入二進位檔
    while (!feof(pRead))
    {
        fscanf(pRead, "%d%s%s%lf", &client.acctNum, client.lastName,
            client.firstName, &client.balance);

        // 使用 fwrite 將結構資料以二進位格式存檔
        fwrite(&client, sizeof(struct clientData), 1, pWrite);

        printf("%-6d%-16s%-11s%10.2f\n", client.acctNum,
            client.lastName, client.firstName, client.balance);
    }

    fclose(pRead);
    fclose(pWrite);

    printf("已讀取文字檔的ASCII資料，並轉存成二進位資料檔案\n\n");
    system("pause");

    // 4. 讀取剛才建立的二進位檔 ("rb" 模式)
    printf("\n讀取二進位資料檔案，並格式化輸出如下：\n");
    if ((cfPtr = fopen("./credit_bin.txt", "rb")) == NULL)
    {
        printf("File could not be opened.\n");
    }
    else
    {
        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        // 使用 fread 讀取二進位結構
        cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);

        while (cnt > 0)
        {
            printf("%-6d%-16s%-11s%10.2f\n", client.acctNum,
                client.lastName, client.firstName, client.balance);

            cnt = fread(&client, sizeof(struct clientData), 1, cfPtr);
        }

        fclose(cfPtr);
    }

    system("pause");
    return 0;
}