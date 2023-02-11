#include "headers.h"
#include "macros.h"

ll pinfo_command(char **cd, ll p)
{
    ll k = 0;
    ll mem = 0;
    ll pId = getpid();
    char pid[length];
    char gb[length];
    char test[length];
    char pt1[length];
    char pt2[length];
    char ss;

    char *process = "/proc/";
    char *ex = "/exe/";
    char *sta = "/stat";

    if (p == 1)
    {
        sprintf(pid, "%lld", pId);
    }
    else
    {
        strcpy(pid, cd[1]);
    }

    strcpy(pt1, process);
    strcat(pt1, pid);
    strcat(pt1, sta);

    FILE *file1 = fopen(pt1, "r");

    if (file1 != NULL)
    {

        fscanf(file1, "%lld", &k);
        fscanf(file1, "%s", gb);
        fscanf(file1, " %c", &ss);

        printf("pid : %s\n", pid);
        printf("process status : %c", ss);

        ll plus;
        ll minus;
        fscanf(file1, "%*d %lld %*d %*d %lld", &plus, &minus);

        if (plus == minus)
        {
            printf("+\n");
        }
        else
        {
            printf("\n");
        }

        fclose(file1);

        strcpy(pt1, process);
        strcat(pt1, pid);
        char *stam = "/statm";
        strcat(pt1, stam);

        FILE *file2 = fopen(pt1, "r");

        fscanf(file2, "%lld", &mem);
        printf("memory : %lld\n", mem);

        fclose(file2);

        strcpy(pt2, process);
        strcat(pt2, pid);
        strcat(pt2, "/exe");
        // printf("%s\n",test);
        readlink(pt2, test, length);
        // printf("%s\n", test);
        ll len;
        len = strlen(hm);
        char *relpath;
        relpath = strstr(test, hm);
        if (relpath == NULL)
        {
            printf("executable path : %s\n", test);
        }
        else
        {
            relpath += len;
            char temp[length];
            char *telda;
            telda = "~";
            strcpy(temp, telda);
            strcat(temp, relpath);
            printf("executable path : %s\n", temp);
        }
    }
    else
    {
        perror("\033[0;31mError\033[0m");
    }
}