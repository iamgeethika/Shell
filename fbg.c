#include "headers.h"
#include "macros.h"
#include "cd.h"
#include "echo.h"
#include "pwd.h"
#include "ls.h"
#include "pinfo.h"
#include "history.h"
#include "discover.h"
// #include "fbg.h"
#include "sig.h"

void fbg_command(char *cdd, ll n, ll *cnt)
{
    char *cd[length];
    char inp_string[length];
    ll l;
    strcpy(inp_string, cdd);
    l = strlen(inp_string);

    char s1[] = "&";
    char s2[] = "' ','\t'";

    ll i = 0, cmd = 0;

    char *token;
    token = strtok(cdd, s1);

    ll bl = 0, index = 0;

    while (token != NULL)
    {
        cd[i] = token;
        token = strtok(NULL, s1);
        cmd++;
        i++;
    }

    while (cmd >= 1)
    {
        ll j;
        j = 0;
        char *token1;
        char *pav[length];
        token1 = strtok(cd[bl], s2);
        // char *cd[length];
        while (token1 != NULL)
        {
            pav[j] = token1;
            token1 = strtok(NULL, s2);
            j++;
        }

        pav[j] = NULL;

        if (cmd == 1 && inp_string[l - 1] == '&')
        {

            ll frk;
            frk = fork();
            if (frk == 0)
            {
                setpgid(0, 0);
                ll exe;
                exe = execvp(pav[0], pav);
                if (exe == -1)
                {
                    perror("\033[0;31mError\033[0m");
                    exit(0);
                }
            }

            else if (frk > 0)
            {
                ll st;
                setpgid(frk, 0);
                fprintf(stderr, "[%lld] %lld\n", *cnt, frk);
                pid[index] = frk;
                strcpy(proc[index], pav[0]);
                strcpy(name[index], pav[0]);
                ll x;
                x=1;
                for (; x < j; x++)
                {
                    strcat(name[index], " ");
                    strcat(name[index], pav[x]);
                }
                shravya[index] = *cnt;
                index++;
                *cnt += 1;
                setpgid(getpid(), 0);
                tcsetpgrp(0, getpgid(getpid()));
            }
            else
            {
                perror("\033[0;31mError\033[0m");
            }
        }
        else if (cmd > 1)
        {
            ll frk;
            frk = fork();
            if (frk == 0)
            {
                setpgid(0, 0); // for fg bg...
                ll exe;
                exe = execvp(pav[0], pav);
                // if (exe == -1)
                // {
                //     perror("\033[0;31mError\033[0m");
                //     exit(0);
                // }
            }

            else if (frk > 0)
            {
                ll st;
                setpgid(frk, 0);
                fprintf(stderr, "[%lld] %lld\n", *cnt, frk);
                pid[index] = frk;
                strcpy(proc[index], pav[0]);
                strcpy(name[index], pav[0]);
                ll x;
                x =1;
                for (; x < j; x++)
                {
                    strcat(name[index], " ");
                    strcat(name[index], pav[x]);
                }
                shravya[index] = *cnt;
                index++;
                *cnt += 1;
                setpgid(getpid(), 0);
                tcsetpgrp(0, getpgid(getpid()));
            }
            else
            {
                perror("\033[0;31mError\033[0m");
            }
        }
        else if (cmd == 1 && inp_string[l - 1] != '&')
        {
            time_t tim1, tim2;
            tim1 = time(0);

            ll cd;
            cd = strcmp(pav[0], "cd");
            ll echo;
            echo = strcmp(pav[0], "echo");
            ll pwd;
            pwd = strcmp(pav[0], "pwd");
            ll ls;
            ls = strcmp(pav[0], "ls");
            ll pinfo;
            pinfo = strcmp(pav[0], "pinfo");
            ll his;
            his = strcmp(pav[0], "history");
            ll ex;
            ex = strcmp(pav[0], "exit");
            ll disc;
            disc = strcmp(pav[0], "discover");
            ll jbs;
            jbs = strcmp(pav[0], "jobs");
            ll sig;
            sig = strcmp(pav[0], "sig");
            // ll rjbs;
            // rjbs = strcmp(pav[1], "-r");
            // ll sjbs;
            // sjbs = strcmp(pav[1], "-s");

            char *cdd[2];
            cdd[0] = "ls";

            if (cd == 0)
            {
                if (j == 2 || j == 1)
                {
                    cd_command(pav, j);
                }
            }
            else if (echo == 0)
            {
                echo_command(pav, j);
            }
            else if (pwd == 0)
            {
                pwd_command(pav, j);
            }
            else if (ls == 0)
            {

                ll f = 0;
                ll f1 = 0, f2 = 0;
                ll fl = 0;
                ll cnt;
                cnt = j;
                if (j <= 2)
                    ls_command(pav, j, f);
                else if (j == 3 && (((strcmp("-l", pav[1]) == 0) && (strcmp("-a", pav[2]) == 0)) || ((strcmp("-a", pav[1]) == 0) && (strcmp("-l", pav[2]) == 0))))
                {
                    ls_command(pav, j, f);
                }
                else if (j >= 3)
                {
                    ll i = 1;
                    for (; i < j; i++)
                    {
                        if (strcmp("-l", pav[i]) == 0 || strcmp("-a", pav[i]) == 0 || strcmp("-la", pav[i]) == 0 || strcmp("-al", pav[i]) == 0)
                        {
                            fl = 1;
                            cnt -= 1;
                        }
                    }
                }
                if (j > 2 && fl == 1)
                {
                    ll i = 1;
                    for (; i < j; i++)
                    {
                        if (strcmp("-l", pav[i]) == 0)
                        {
                            f = 1;
                            f1 = 1;
                        }
                        else if (strcmp("-a", pav[i]) == 0)
                        {
                            f = 2;
                            f2 = 1;
                        }
                        else if (strcmp("-al", pav[i]) == 0 || strcmp("-la", pav[i]) == 0)
                        {
                            f = 3;
                        }
                    }
                    if (f1 == 1 && f2 == 1)
                    {
                        f = 3;
                    }
                    i = 1;
                    for (; i < j; i++)
                    {
                        if (strcmp("-l", pav[i]) != 0 && strcmp("-a", pav[i]) != 0 && strcmp("-la", pav[i]) != 0 && strcmp("-al", pav[i]) != 0)
                        {
                            cdd[1] = pav[i];
                            if (cnt > 2)
                            {
                            }
                            ls_command(cdd, 2, f);
                            // printf("\n");
                        }
                    }
                }

                if (j > 2 && fl != 1)
                {
                    ll i = 1;
                    for (; i < j; i++)
                    {
                        if (strcmp("-l", pav[i]) != 0 && strcmp("-a", pav[i]) != 0 && strcmp("-la", pav[i]) != 0 && strcmp("-al", pav[i]) != 0)
                        {
                            cdd[1] = pav[i];
                            // printf("%s:\n", pav[i]);
                            ls_command(cdd, 2, f);
                            // printf("\n");
                        }
                    }
                }
            }
            else if (pinfo == 0)
            {
                pinfo_command(pav, j);
            }

            else if (his == 0)
            {
                his_command(pav, j);
            }
            else if (disc == 0)
            {
                discover(pav, j);
            }
            else if (ex == 0)
            {
                exit(0);
            }
            else if (sig == 0)
            {
                if (j != 3)
                {
                    printf("Incorrect Arguments\n");
                    exit(0);
                }
                else
                {
                    sig_command(pav, j);
                }
            }

            else
            {

                ll frk;
                frk = fork();
                if (frk == 0)
                {
                    setpgid(0, 0);
                    ll exe;
                    exe = execvp(pav[0], pav);
                    if (exe == -1)
                    {
                        perror("\033[0;31mError\033[0m");
                    }
                }

                else if (frk > 0)
                {
                    setpgid(frk, 0);
                    signal(SIGTTIN, SIG_IGN);
                    signal(SIGTTOU, SIG_IGN);
                    tcsetpgrp(0, frk);
                    frkinp = frk;
                    // ll time_taken;
                    // fprintf(stderr,"[%d"] %d,*cnt,frk);
                    // wait(NULL);
                    // fprintf(stderr,"[%d"] %d,*cnt,frk);
                    int wt;
                    waitpid(frk, &wt, WAIT_MYPGRP);
                    if (WIFSTOPPED(wt))
                    {

                        shravya[index] = *cnt;
                        pid[index] = frk;
                        strcpy(proc[index], pav[0]);
                        strcpy(name[index], pav[0]);
                        ll x;
                        x = 1;
                        for (; x < j; x++)
                        {
                            strcat(name[index], " ");
                            strcat(name[index], pav[x]);
                        }
                        shravya[index] = *cnt;
                        index++;
                        *cnt += 1;
                        kill(frk, SIGSTOP);
                    }
                }
                else
                {
                    setpgid(frk, 0);
                    signal(SIGTTIN, SIG_IGN);
                    signal(SIGTTOU, SIG_IGN);
                    tcsetpgrp(0, frk);
                    frkinp = frk;
                    // ll time_taken;
                    // fprintf(stderr,"[%d"] %d,*cnt,frk);
                    // wait(NULL);
                    // fprintf(stderr,"[%d"] %d,*cnt,frk);
                    int wt;
                    waitpid(frk, &wt, WAIT_MYPGRP);
                    if (WIFSTOPPED(wt))
                    {

                        shravya[index] = *cnt;
                        pid[index] = frk;
                        strcpy(proc[index], pav[0]);
                        strcpy(name[index], pav[0]);
                        ll x;
                        x = 1;
                        for (; x < j; x++)
                        {
                            strcat(name[index], " ");
                            strcat(name[index], pav[x]);
                        }
                        shravya[index] = *cnt;
                        index++;
                        *cnt += 1;
                        kill(frk, SIGSTOP);
                    }
                }
            }
            ll time_taken;
            tim2 = time(0);
            frkinp = -1;
            // pid[index] = frk;
            // strcpy(proc[index], pav[0]);
            time_taken = tim2 - tim1;
            if (time_taken >= 1)
            {
                fprintf(stderr, "%s took %lld seconds to execute\n", pav[0], time_taken);
            }
            index++;
            tcsetpgrp(0, getpgid(getpid()));
            signal(SIGTTIN, SIG_DFL);
            signal(SIGTTOU, SIG_DFL);

            // index++;
            // *cnt += 1;
        }
        
        bl++;
        cmd--;
    }
    // bl++;
    // cmd--;
}
