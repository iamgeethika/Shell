#include "headers.h"
#include "macros.h"

void hist(char *H_C, int *hcnt)
{
    if (*hcnt < 20)
    {
        if (strcmp(his_arr[*hcnt - 1], H_C) != 0)
        {
            strcpy(his_arr[*hcnt], H_C);
            *hcnt +=1;
        }
    }
    else
    {
        if (strcmp(his_arr[*hcnt - 1], H_C) != 0)
        {
            int i=0;
            for (; i < 19; i++)
            {
                strcpy(his_arr[i], his_arr[i + 1]);
            }
            strcpy(his_arr[19], H_C);
            *hcnt = 20;
        }
    }
    char pth[length];
    strcpy(pth, hm);
    strcat(pth, "/history.txt");
    FILE *f1 = fopen(pth, "w");
    int i=0;
    for (; i < *hcnt; i++)
    {
        char tmp[length];
        strcpy(tmp, his_arr[i]);
        fprintf(f1, "%s\n", tmp);
    }
    fclose(f1);
}

void his_command(char **cd, int n)
{
    if (n == 1)
    {
        char pth[length];
        char d[20][length];
        strcpy(pth, hm);
        strcat(pth, "/history.txt");
        FILE *fp1 = fopen(pth, "r");
        int i = 0;
        char tmp[length];
        while ((fscanf(fp1, "%[^\n]%*c", tmp) != EOF))
        {
            strcpy(d[i], tmp);
            i++;
        }
        if (i <= 10)
        {
            int j=0;
            for (; j < i; j++)
            {
                printf("%s\n", d[j]);
            }
        }
        else
        {
            int j;
            for (j = i - 10; j < i; j++)
            {
                printf("%s\n", d[j]);
            }
        }
        fclose(fp1);
    }

    else
    {
        perror("\033[0;31mError\033[0m");
    }
}