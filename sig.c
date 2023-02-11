#include "headers.h"
#include "macros.h"

void sig_command(char **cd, ll j)
{
    ll jbnum, sgnum, pd;
    jbnum = atoi(cd[1]);
    sgnum = atoi(cd[2]);

    ll flag = 0;
    ll i;
    i = 0;
    for (; i < length; i++)
    {
        if (pid[i] != 0 && ver[i] != -1)
        {
            if (shravya[i] == jbnum)
            {
                flag++;
                pd = pid[i];
                break;
            }
        }
    }
    if (flag == 0)
    {
        perror("\033[0;31mError\033[0m");
    }
    if (flag == 1)
    {
        ll k;
        k = kill(pd, sgnum);
        if (k < 0)
        {
            perror("\033[0;31mError\033[0m");
        }
    }
}