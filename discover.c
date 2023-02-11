#include "headers.h"
#include "macros.h"
void disc(char *cd, ll p, ll nav, ll file, char *fls)
{
    DIR *dir;
    struct dirent *D;
    char store[length];

    ll i = 0;
    dir = opendir(cd);
    char bef_dir[length];
    char *h;
    h = "/";
    if (dir != NULL)
    {
        D = readdir(dir);
        while (D != NULL)
        {
            char A;
            A = D->d_name[0];
            if (A != '.')
            {
                strcpy(bef_dir, cd);
                strcat(bef_dir, h);
                strcat(bef_dir, D->d_name);
                if (opendir(bef_dir) == NULL)
                {
                    i = 1;
                }
                if (file == 1)
                {
                    if (strcmp(D->d_name, fls) == 0)
                    {
                        printf("%s\n", &bef_dir[nav]);
                    }
                }
                else
                {
                    if (p == 0)
                    {

                        if (nav != 0)
                        {
                            printf("~");
                        }
                        printf("%s\n", &bef_dir[nav]);
                    }
                    if ((p == 1 && i == 0))
                    {

                        if (nav != 0)
                        {
                            printf("~");
                        }
                        printf("%s\n", &bef_dir[nav]);
                    }
                    if ((p == 2 && i == 1))
                    {

                        if (nav != 0)
                        {
                            printf("~");
                        }
                        printf("%s\n", &bef_dir[nav]);
                    }
                }

                disc(bef_dir, p, nav, file, fls);
                i = 0;
            }
            D = readdir(dir);
        }
    }

    else
    {
        // printf("\033[0;35m");
        // perror("Error: ");
        // printf("\033[0m");
    }
}
void discover(char *cmd[], int t)
{
    ll d_comand = 0, f_comand = 0;
    ll h_f = 0, f_f = 0, d_f = 0;
    char bef_dir[length];
    ll a = 1;
    for (; a < t; a++)
    {
        if (strcmp(cmd[a], "-d") == 0)
        {
            d_comand = 1;
        }
        else if (strcmp(cmd[a], "-f") == 0)
        {
            f_comand = 1;
        }
        else if (strcmp(cmd[a], ".") == 0)
        {
        }
        else if (strcmp(cmd[a], "..") == 0)
        {
        }
        else if (strcmp(cmd[a], "~") == 0)
        {
        }
        else
        {
            if (cmd[a][0] != '.')
            {
                f_f = 1;
                strcpy(bef_dir, cmd[a]);
            }
            else
            {
                d_f = 1;
            }
        }
    }

    if ((d_comand == 0 && f_comand == 0) || (d_comand == 1 && f_comand == 1))
    {
        h_f = 0;
    }
    else if (f_comand == 1 && d_comand == 0)
    {
        h_f = 2;
    }

    else if (f_comand == 0 && d_comand == 1)
    {
        h_f = 1;
    }

    if (t == 1)
    {
        printf(".\n");
        disc(".", h_f, 0, f_f, bef_dir);
    }

    else
    {
        if ((strcmp(cmd[1], "~") == 0) && f_f != 1)
        {
            printf("~\n");
            disc(hm, h_f, strlen(hm), f_f, bef_dir);
        }
        else if ((strcmp(cmd[1], "..") == 0 && f_f != 1))
        {
            printf("%s\n", cmd[1]);
            disc(cmd[1], h_f, 0, f_f, bef_dir);
        }
        else if ((strcmp(cmd[1], ".") == 0) && f_f != 1)
        {
            printf("%s\n", cmd[1]);
            disc(cmd[1], h_f, 0, f_f, bef_dir);
        }
        else if ((strcmp(cmd[1], "-f") == 0) && f_f != 1)
        {
            printf(".\n");
            disc(".", h_f, 0, f_f, bef_dir);
        }
        else if ((strcmp(cmd[1], "-d") == 0 && f_f != 1))
        {
            printf(".\n");
            disc(".", h_f, 0, f_f, bef_dir);
        }
        else
        {
            if (d_f == 1 && f_f != 1)
            {
                disc(cmd[1], h_f, 0, f_f, bef_dir);
            }
            if (d_f != 1 && f_f == 1)
            {

                char string[strlen(bef_dir) - 1];
                int i;
                i = 0;
                for (; i < strlen(bef_dir) - 2; i++)
                {
                    string[i] = bef_dir[i + 1];
                }
                if (strcmp(cmd[1], ".") == 0)
                {
                    disc(cmd[1], h_f, 0, f_f, string);
                }
                if (strcmp(cmd[1], "..") == 0)
                {
                    disc(cmd[1], h_f, 0, f_f, string);
                }
                if (strcmp(cmd[1], "~") == 0)
                {
                    disc(hm, h_f, 0, f_f, string);
                }
            }
            if (f_f == 1 && d_f == 1)
            {
                char string[strlen(bef_dir) - 1];
                int i;
                i = 0;
                for (; i < strlen(bef_dir) - 2; i++)
                {
                    string[i] = bef_dir[i + 1];
                }
                disc(cmd[1], h_f, 0, f_f, string);
            }
        }
    }
}