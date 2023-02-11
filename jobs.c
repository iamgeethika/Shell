#include "headers.h"
#include "macros.h"

ll jobs_command(ll fl)
{
    int n, tmpa, tmpb, tmpc;
    n = 100;
    char Arr[length];
    char Arr1[length];

    ll i;
    i = 0;
    ll j;
    j = 0;
    for (; i < n - 1; i++)
    {
        ll swapcnt;
        swapcnt = 0;
        for (; j < n - 1; j++)
        {
            ll j1;
            j1 = j + 1;
            ll result;
            result = strcasecmp(proc[j1], proc[j]);

            if (result < 0)
            {
                strcpy(Arr, proc[j]);
                strcpy(proc[j], proc[j1]);
                strcpy(proc[j1], Arr);

                tmpa = pid[j];
                pid[j] = pid[j1];
                pid[j1] = tmpa;
                tmpb = ver[j];
                ver[j] = ver[j1];
                ver[j1] = tmpb;
                tmpc = shravya[j];
                shravya[j] = shravya[j1];
                shravya[j1] = tmpc;

                strcpy(Arr1, name[j]);
                strcpy(name[j], name[j1]);
                strcpy(name[j1], Arr1);
                swapcnt++;
            }
        }
        if (swapcnt == 0)
        {
            break;
        }
    }
    i = 0;

    for (; i < 1000; i++)
    {
        if (pid[i] != 0 && ver[i] != -1)
        {
            {
                char *process = "/proc/";
                char *sta = "/stat";
                char p[100];
                char file[100];
                char state;
                strcpy(file, process);
                sprintf(p, "%lld", pid[i]);
                strcat(file, p);
                strcat(file, sta);

                FILE *fileptr;
                fileptr = fopen(file, "r");

                fscanf(fileptr, "%*d %*s %c", &state);
                fclose(fileptr);
                char StatofProc[length];

                if (state == 'T')
                {
                    strcpy(StatofProc, "Stopped");
                }
                else
                {
                    strcpy(StatofProc, "Running");
                }

                ll Run;
                Run = strcmp(StatofProc, "Running");
                ll Stop;
                Stop = strcmp(StatofProc, "Stopped");

                // if (fl == 0)
                // {
                //     printf("[%lld] %s %s [%lld]\n", shravya[i], StatofProc, name[i], pid[i]);
                // }
                if (fl == 1 && Run == 0)
                {
                    printf("[%lld] %s %s [%lld]\n", shravya[i], StatofProc, name[i], pid[i]);
                }
                if (fl == 0)
                {
                    printf("[%lld] %s %s [%lld]\n", shravya[i], StatofProc, name[i], pid[i]);
                }
                if (fl == -1 && Stop == 0)
                {
                    printf("[%lld] %s %s [%lld]\n", shravya[i], StatofProc, name[i], pid[i]);
                }
            }
        }
    }
    return 0;
}