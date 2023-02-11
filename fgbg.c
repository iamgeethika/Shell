#include "headers.h"
#include "macros.h"
void fg_command(char **cmnd, int j)
{
    ll jbnum;
    jbnum = atoi(cmnd[1]);

    ll flag = 0;
    ll p;
    int de;
    char Arr[length];
    ll i;
    i = 0;
    for (; i < length; i++)
    {
        if (pid[i] != 0 && ver[i] != -1)
        {

            if (shravya[i] == jbnum)
            {
                flag++;
                p = pid[i];
                de = i;
                strcpy(Arr, proc[i]);
                break;
            }
        }
    }
    if (flag != 0)
    {
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTTOU, SIG_IGN);
        tcsetpgrp(0, getpgid(p));

        ll k;
        k = kill(p, SIGCONT);
        int wt;
        waitpid(p, &wt, WUNTRACED);
        ver[de] = -1;
        fflush(stdout);
        
        tcsetpgrp(0, getpid());
        signal(SIGTTOU, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);

        if (WIFSTOPPED(wt))
        {
            printf("Process %s With Pid %lld Stopped\n", Arr, p);
        }
    }

    else
    {
        perror("\033[0;31mError\033[0m");
    }
}

void bg_command(char **cmnd, int j)
{
    ll jbnum;
    jbnum = atoi(cmnd[1]);

    ll flag = 0;
    ll p;
    int de;
    char Arr[length];
    ll i;
    i = 0;
    for (; i < 1000; i++)
    {
        if (pid[i] != 0 && ver[i] != -1)
        {

            if (shravya[i] == jbnum)
            {
                flag++;
                p = pid[i];
                de = i;
                strcpy(Arr, proc[i]);
                break;
            }
        }
    }

    if (flag != 0)
    {
        ll k;
        k = kill(p, SIGCONT);
        if (k < 0)
        {
            perror("\033[0;31mError\033[0m");
        }
    }
    else
    {
        perror("\033[0;31mError\033[0m");
    }
}