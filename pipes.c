#include "headers.h"
#include "macros.h"
#include "cd.h"
#include "echo.h"
#include "pwd.h"
#include "ls.h"
#include "pinfo.h"
#include "history.h"
#include "discover.h"
#include "fbg.h"
#include "redirection.h"

void execute_commands(char *cmnd)
{

    char *c1[length];
    char sl[] = "' ','\t'";

    char *null;
    null = '\0';
    char great, less;
    great = '>';
    less = '<';

    char *gr, *sm;
    gr = ">";
    sm = "<";

    ll leng;
    leng = strlen(cmnd);
    int v;
    v = 0;
    for (; v < leng; v++)
    {
        if (cmnd[v] == '<')
        {
            red_command(cmnd);
            // flg++;
            // break;
            return;
        }
        if (cmnd[v] == '>')
        {
            red_command(cmnd);
            // flg++;
            // break;
            return;
        }
    }

    ll i;
    i = 0;
    for (; i < strlen(cmnd); i++)
    {
        if (cmnd[i] == great || cmnd[i] == less)
        {
            red_command(cmnd);
            return;
        }
    }

    char *token = strtok(cmnd, sl);
    ll j;
    j = 0;
    for (j = 0; token != NULL; j++)
    {
        c1[j] = token;
        token = strtok(NULL, sl);
    }
    c1[j] = null;
    // from main....................................................................

    ll cd;
    cd = strcmp(c1[0], "cd");
    ll echo;
    echo = strcmp(c1[0], "echo");
    ll pwd;
    pwd = strcmp(c1[0], "pwd");
    ll ls;
    ls = strcmp(c1[0], "ls");
    ll pinfo;
    pinfo = strcmp(c1[0], "pinfo");
    ll his;
    his = strcmp(c1[0], "history");
    ll ex;
    ex = strcmp(c1[0], "exit");
    ll disc;
    disc = strcmp(c1[0], "discover");

    char *cdd[2];
    cdd[0] = "ls";

    if (cd == 0)
    {
        if (j == 2 || j == 1)
        {
            cd_command(c1, j);
        }
    }
    else if (echo == 0)
    {
        echo_command(c1, j);
    }
    else if (pwd == 0)
    {
        pwd_command(c1, j);
    }
    else if (ls == 0)
    {

        ll f = 0;
        ll flag1 = 0, flag3 = 0;
        ll fl = 0;
        ll cnt;
        cnt = j;
        if (j <= 2)
            ls_command(c1, j, f);
        else if (j == 3 && (((strcmp("-l", c1[1]) == 0) && (strcmp("-a", c1[2]) == 0)) || ((strcmp("-a", c1[1]) == 0) && (strcmp("-l", c1[2]) == 0))))
        {
            ls_command(c1, j, f);
        }
        else if (j >= 3)
        {
            ll i = 1;
            for (; i < j; i++)
            {
                if (strcmp("-l", c1[i]) == 0 || strcmp("-a", c1[i]) == 0 || strcmp("-la", c1[i]) == 0 || strcmp("-al", c1[i]) == 0)
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
                if (strcmp("-l", c1[i]) == 0)
                {
                    f = 1;
                    flag1 = 1;
                }
                else if (strcmp("-a", c1[i]) == 0)
                {
                    f = 2;
                    flag3 = 1;
                }
                else if (strcmp("-al", c1[i]) == 0 || strcmp("-la", c1[i]) == 0)
                {
                    f = 3;
                }
            }
            if (flag1 == 1 && flag3 == 1)
            {
                f = 3;
            }
            i = 1;
            for (; i < j; i++)
            {
                if (strcmp("-l", c1[i]) != 0 && strcmp("-a", c1[i]) != 0 && strcmp("-la", c1[i]) != 0 && strcmp("-al", c1[i]) != 0)
                {
                    cdd[1] = c1[i];
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
                if (strcmp("-l", c1[i]) != 0 && strcmp("-a", c1[i]) != 0 && strcmp("-la", c1[i]) != 0 && strcmp("-al", c1[i]) != 0)
                {
                    cdd[1] = c1[i];
                    // printf("%s:\n", c1[i]);
                    ls_command(cdd, 2, f);
                    // printf("\n");
                }
            }
        }
    }
    else if (pinfo == 0)
    {
        pinfo_command(c1, j);
    }

    else if (his == 0)
    {
        his_command(c1, j);
    }
    else if (disc == 0)
    {
        discover(c1, j);
    }
    else if (ex == 0)
    {
        exit(0);
    }
    else
    {
        ll frk;
        frk = fork();

        if (frk > 0)
        {
            wait(NULL);
        }

        if (frk == 0)
        {
            ll exe;
            exe = execvp(c1[0], c1);
            if (exe == -1)
            {
                perror("\033[0;31mError\033[0m");
            }
        }
        if (frk < 0)
        {
            perror("\033[0;31mError\033[0m");
        }
    }
}

ll pipes_command(char *cod)
{
    char *null;
    null = '\0';
    ll std_in, std_out;
    std_out = dup(1);
    std_in = dup(0);

    char sl1[] = "|";
    char inpstr[length];
    char *commd[length];
    strcpy(inpstr, cod);
    char *token1;
    token1 = strtok(inpstr, sl1);
    ll i;
    i = 0;
    for (; token1 != NULL; i++)
    {
        commd[i] = token1;
        token1 = strtok(NULL, sl1);
    }
    commd[i] = null;
    ll a = i - 1;
    int pps[a][2];
    pipe(pps[0]);
    int p1 = pps[0][1];
    dup2(p1, 1);
    execute_commands(commd[0]);
    close(p1);
    ll j;
    j = 1;
    for (; j < a; j++)
    {
        pipe(pps[j]);
        int p2 = pps[j - 1][0];
        dup2(p2, 0);
        int p3 = pps[j][1];
        dup2(p3, 1);
        execute_commands(commd[j]);
        close(p2);
        close(p3);
    }
    int p4 = pps[j - 1][0];
    dup2(p4, 0);
    dup2(std_out, 1);
    execute_commands(commd[j]);
    dup2(std_in, 0);
    close(p4);
    close(std_in);
    close(std_out);
}