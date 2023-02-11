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

void red_command(char *cmnd)
{
    // char s2[] = "' ','\t'";
    // char s1[] = ";";
    char sl[] = "' ','\t'";

    char *null;
    null = '\0';
    char great, less;
    great = '>';
    less = '<';

    char *gr, *sm;
    gr = ">";
    sm = "<";

    ll flag1, flag2, flag3;

    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    ll i;
    i = 0;
    for (; i < strlen(cmnd); i++)
    {
        if (cmnd[i] == great && cmnd[i + 1] == great)
        {
            flag1 = 1;
        }

        else if (cmnd[i] == less)
        {
            flag2 = 1;
        }
        else if (cmnd[i] == great)
        {
            flag3 = 1;
        }
    }

    ll std_in, std_out;
    std_out = dup(1);
    std_in = dup(0);

    char *inp_file, *out_file;
    char *out_token[2], *in[2];
    char *c1[length];
    ll j;
    j = 0;
    if (flag2 == 0 && flag3 == 1)
    {

        char tmp[length];
        strcpy(tmp, cmnd);
        out_token[0] = strtok(tmp, gr);
        out_token[1] = strtok(NULL, gr);
        char *token;
        token = strtok(out_token[0], sl);
        j = 0;
        for (; token != NULL; j++)
        {
            c1[j] = token;
            token = strtok(NULL, sl);
        }
        c1[j] = null;
        out_file = strtok(out_token[1], sl);
    }
    else if (flag3 == 0 && flag2 == 1)
    {

        char tmp[length];
        strcpy(tmp, cmnd);
        in[0] = strtok(tmp, sm);
        in[1] = strtok(NULL, sm);
        char *token;
        token = strtok(in[0], sl);
        j = 0;
        for (; token != NULL; j++)
        {
            c1[j] = token;
            token = strtok(NULL, sl);
        }
        inp_file = strtok(in[1], sl);
        c1[j] = null;
    }
    else
    {
        char tmp[length];
        strcpy(tmp, cmnd);
        out_token[0] = strtok(tmp, gr);
        out_token[1] = strtok(NULL, gr);
        in[0] = strtok(out_token[0], sm);
        in[1] = strtok(NULL, sm);
        char *token = strtok(in[0], sl);
        j = 0;
        for (; token != NULL; j++)
        {
            c1[j] = token;
            token = strtok(NULL, sl);
        }
        inp_file = strtok(in[1], sl);
        out_file = strtok(out_token[1], sl);
        c1[j] = null;
    }
    if (flag2 == 1)
    {
        ll fd_in;
        fd_in = open(inp_file, O_RDONLY);
        if (fd_in < 0)
        {
            perror("\033[0;31mError in opening Output File\033[0m");
            return;
        }
        dup2(fd_in, 0);
        close(fd_in);
    }

    if (flag1 == 1)
    {
        ll fd_out;
        fd_out = open(out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd_out < 0)
        {
            perror("\033[0;31mError in opening Output File\033[0m");
            return;
        }
        dup2(fd_out, 1);
        close(fd_out);
    }

    else if (flag1 == 0 && flag3 == 1)
    {
        ll fd_out;
        fd_out = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_out < 0)
        {
            perror("\033[0;31mError in opening Output File\033[0m");
            return;
        }
        dup2(fd_out, 1);
        close(fd_out);
    }

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

    dup2(std_in, 0);
    dup2(std_out, 1);
    close(std_in);
    close(std_out);
}