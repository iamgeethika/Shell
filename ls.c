#include "headers.h"
#include "macros.h"

void ls_command(char **cd, ll p, ll f)
{
    char *fls[100];
    char *h;
    h = "/";
    char null;
    null = '\0';
    char slash;
    slash = '/';

    if (f == 0 && p == 1)
    {
        struct stat dir = {0};
        char pt[length];

        struct dirent *direct;
        DIR *dr;
        dr = opendir(".");
        ll a = 0;
        if (dr == NULL)
        {
            perror("\033[0;31mError\033[0m");
        }
        else
        {

            while ((direct = readdir(dr)) != NULL)
            {
                char A = direct->d_name[0];
                if (A != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
            closedir(dr);
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        for (ll i = 0; i < a; i++)
        {
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);
            ll k;
            k = stat(pt, &dir);
            if (k == 0 && S_ISDIR(dir.st_mode))
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if (k == 0 && (dir.st_mode & S_IXUSR))
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
    if (((p == 2 && strcmp(".", cd[1]) == 0)) && f == 0)
    {

        char pt[length];
        struct stat dir = {0};
        struct dirent *direct;
        DIR *dr;
        dr = opendir(".");
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                char A = direct->d_name[0];
                if (A != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
            closedir(dr);
        }
        else
        {
            perror("\033[0;31mError\033[0m");
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        for (ll i = 0; i < a; i++)
        {
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);
            ll k;
            k = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && k == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && k == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }

    else if (p == 2 && strcmp("-a", cd[1]) == 0 && f == 0)
    {
        struct stat dir = {0};
        char pt[length];
        struct dirent *direct;
        DIR *dr;
        dr = opendir(".");
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                fls[a] = direct->d_name;
                a++;
            }
            closedir(dr);
        }
        else
        {
            perror("\033[0;31mError\033[0m");
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        for (ll i = 0; i < a; i++)
        {
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);
            ll k;
            k = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && k == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && k == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
    else if (p == 2 && strcmp("..", cd[1]) == 0 && f == 0)
    {

        char pt[500];
        struct stat dir = {0};
        struct dirent *direct;
        DIR *dr;

        dr = opendir("./..");
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                char A = direct->d_name[0];
                if (A != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
            closedir(dr);
        }
        else
        {
            perror("\033[0;31mError\033[0m");
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        char c_d[length];
        char pd[length];
        getcwd(c_d, sizeof(c_d));
        char *ptr = strrchr(c_d, slash);
        char *s = c_d;

        if (ptr != NULL)
        {
            ll i = 0;
            for (s; s <= ptr; s++)
            {
                pd[i] = c_d[i];
                i++;
            }
            pd[i] = null;
        }

        for (ll i = 0; i < a; i++)
        {
            strcpy(pt, pd);
            strcat(pt, fls[i]);
            // printf("%s\n", pt);
            ll k;
            k = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && k == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && k == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
    else if (p == 2 && strcmp("~", cd[1]) == 0 && f == 0)
    {
        struct dirent *direct;
        DIR *dr;

        struct stat dir = {0};
        char pt[500];

        dr = opendir(hm);
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                char A = direct->d_name[0];
                if (A != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
            closedir(dr);
        }
        else
        {
            perror("\033[0;31mError\033[0m");
        }

        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }
        // printf("After sorting\n");
        for (ll i = 0; i < a; i++)
        {
            strcpy(pt, hm);
            strcat(pt, h);
            strcat(pt, fls[i]);
            // printf("%s\n",pt);
            ll b;
            b = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && b == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && b == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
    else if (p == 2 && strcmp("-l", cd[1]) == 0 && f == 0)
    {
        struct dirent *direct;
        DIR *dr;
        dr = opendir(".");

        ll bytes = 0;
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                char A = direct->d_name[0];
                if (A != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }
        ll bit;
        for (ll i = 0; i < a; i++)
        {

            char pt[length];
            struct stat dir = {0};
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);
            ll b = stat(pt, &dir);

            // for printing total bytes
            if (b == 0)
            {
                bytes += dir.st_blocks;
            }
        }
        bit = bytes / 2;

        if (bit > 0)
        {
            printf("total %lld\n", bit);
        }
        for (ll i = 0; i < a; i++)
        {

            char pt[500];
            struct stat dir = {0};
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);
            char perm[11];
            ll b = stat(pt, &dir);
            // for directory
            ll isdir = S_ISDIR(dir.st_mode);
            // for Owner Permissions
            ll irusr = (dir.st_mode & S_IRUSR);
            ll iwusr = (dir.st_mode & S_IWUSR);
            ll ixusr = (dir.st_mode & S_IXUSR);
            // for Group Permissions
            ll irgrp = (dir.st_mode & S_IRGRP);
            ll iwgrp = (dir.st_mode & S_IWGRP);
            ll ixgrp = (dir.st_mode & S_IXGRP);
            // for Others Permissions
            ll iroth = (dir.st_mode & S_IROTH);
            ll iwoth = (dir.st_mode & S_IWOTH);
            ll ixoth = (dir.st_mode & S_IXOTH);
            if (b == 0)
            {
                perm[0] = isdir ? 'd' : '-';

                perm[1] = irusr ? 'r' : '-';

                perm[2] = iwusr ? 'w' : '-';

                perm[3] = ixusr ? 'x' : '-';

                perm[4] = irgrp ? 'r' : '-';

                perm[5] = iwgrp ? 'w' : '-';

                perm[6] = ixgrp ? 'x' : '-';

                perm[7] = iroth ? 'r' : '-';

                perm[8] = iwoth ? 'w' : '-';

                perm[9] = ixoth ? 'x' : '-';

                perm[10] = null;

                ll lk = dir.st_nlink;
                char time[length];
                struct passwd *pass = getpwuid(dir.st_uid);
                struct group *grp = getgrgid(dir.st_gid);
                char *owner = pass->pw_name;
                char *group = grp->gr_name;
                ll size = dir.st_size;
                time_t t = dir.st_mtime;
                struct tm Tim;
                localtime_r(&t, &Tim);
                strftime(time, sizeof(time), "%b %d %Y %H:%M", &Tim);
                char *f = fls[i];

                printf("%s  %lld\t%s\t%s\t%lld\t%s  ", perm, lk, owner, group, size, time);
                if (S_ISDIR(dir.st_mode) && b == 0)
                {
                    printf("\033[1;34m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else if ((dir.st_mode & S_IXUSR) && b == 0)
                {
                    printf("\033[1;32m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else
                {
                    printf("%s\n", fls[i]);
                }
            }
        }
        closedir(dr);
    }

    else if ((p == 2 && ((strcmp("-al", cd[1]) == 0) || (strcmp("-la", cd[1]) == 0))) || (p == 3 && (((strcmp("-l", cd[1]) == 0) && (strcmp("-a", cd[2]) == 0)) || ((strcmp("-a", cd[1]) == 0) && (strcmp("-l", cd[2]) == 0)))) && f == 0)
    {
        struct dirent *direct;
        DIR *dr;
        dr = opendir(".");

        ll bytes = 0;
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                fls[a] = direct->d_name;
                a++;
            }
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }
        ll bit;
        for (ll i = 0; i < a; i++)
        {

            char pt[length];
            struct stat dir = {0};
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);

            // for printing total bytes
            if (stat(pt, &dir) == 0)
            {
                bytes += dir.st_blocks;
            }
        }
        bit = bytes / 2;
        if (bit > 0)
        {
            printf("total %lld\n", bit);
        }
        for (ll i = 0; i < a; i++)
        {
            struct stat dir = {0};
            char pt[length];
            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, fls[i]);

            char perm[11];
            ll b = stat(pt, &dir);
            // for directory
            ll isdir = S_ISDIR(dir.st_mode);
            // for Owner Permissions
            ll irusr = (dir.st_mode & S_IRUSR);
            ll iwusr = (dir.st_mode & S_IWUSR);
            ll ixusr = (dir.st_mode & S_IXUSR);
            // for Group Permissions
            ll irgrp = (dir.st_mode & S_IRGRP);
            ll iwgrp = (dir.st_mode & S_IWGRP);
            ll ixgrp = (dir.st_mode & S_IXGRP);
            // for Others Permissions
            ll iroth = (dir.st_mode & S_IROTH);
            ll iwoth = (dir.st_mode & S_IWOTH);
            ll ixoth = (dir.st_mode & S_IXOTH);
            if (b == 0)
            {
                perm[0] = isdir ? 'd' : '-';

                perm[1] = irusr ? 'r' : '-';

                perm[2] = iwusr ? 'w' : '-';

                perm[3] = ixusr ? 'x' : '-';

                perm[4] = irgrp ? 'r' : '-';

                perm[5] = iwgrp ? 'w' : '-';

                perm[6] = ixgrp ? 'x' : '-';

                perm[7] = iroth ? 'r' : '-';

                perm[8] = iwoth ? 'w' : '-';

                perm[9] = ixoth ? 'x' : '-';

                perm[10] = null;

                ll lk = dir.st_nlink;
                char time[length];
                struct passwd *pass = getpwuid(dir.st_uid);
                struct group *grp = getgrgid(dir.st_gid);
                char *owner = pass->pw_name;
                char *group = grp->gr_name;
                ll size = dir.st_size;
                time_t t = dir.st_mtime;
                struct tm Tim;
                localtime_r(&t, &Tim);
                strftime(time, sizeof(time), "%b %d %Y %H:%M", &Tim);
                char *f = fls[i];

                printf("%s  %lld\t%s\t%s\t%lld\t%s  ", perm, lk, owner, group, size, time);
                if (S_ISDIR(dir.st_mode) && b == 0)
                {
                    printf("\033[1;34m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else if ((dir.st_mode & S_IXUSR) && b == 0)
                {
                    printf("\033[1;32m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else
                {
                    printf("%s\n", fls[i]);
                }
            }
        }
        closedir(dr);
    }
    else if (p == 2 && f == 0)
    {
        struct dirent *direct;
        DIR *dr;

        struct stat dir = {0};
        char cur_dir[length];
        getcwd(cur_dir, sizeof(cur_dir));
        strcat(cur_dir, h);
        strcat(cur_dir, cd[1]);
        ll bc = stat(cur_dir, &dir);
        dr = opendir(cd[1]);

        ll a = 0;

        if (S_ISREG(dir.st_mode))
        {
            printf("%s\n", cd[1]);
        }
        else if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                if (direct->d_name[0] != '.')
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
            closedir(dr);
        }
        else
        {
            perror("\033[0;31mError\033[0m");
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        for (ll i = 0; i < a; i++)
        {
            struct stat dir = {0};
            char pt[length];

            getcwd(pt, sizeof(pt));
            strcat(pt, h);
            strcat(pt, cd[1]);
            strcat(pt, h);
            strcat(pt, fls[i]);
            ll b = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && b == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && b == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
    else if (p == 2 && ((f == 1 || f == 3)))
    {
        struct dirent *direct;
        DIR *dr;
        if (strcmp("~", cd[1]) == 0)
        {
            dr = opendir(hm);
        }
        else
        {
            dr = opendir(cd[1]);
        }
        ll bytes = 0;
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                if (f == 1)
                {
                    if (direct->d_name[0] != '.')
                    {
                        fls[a] = direct->d_name;
                        a++;
                    }
                }
                else if (f == 3)
                {
                    fls[a] = direct->d_name;
                    a++;
                }
            }
        }
        if (dr == NULL)
        {
            fls[0] = cd[1];
            a = 1;
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }
        ll bit;
        for (ll i = 0; i < a; i++)
        {
            struct stat dir = {0};
            char pt[length];

            if (cd[1][0] == slash)
            {
                strcpy(pt, cd[1]);
            }
            else
            {
                getcwd(pt, sizeof(pt));

                if (strcmp("~", cd[1]) != 0 && strcmp(".", cd[1]) != 0)
                {
                    strcat(pt, h);
                    strcat(pt, cd[1]);
                }
            }
            strcat(pt, h);
            strcat(pt, fls[i]);

            // printf("%s\n",pt);
            if (stat(pt, &dir) == 0)
            {
                bytes += dir.st_blocks;
            }
        }
        bit = bytes / 2;
        if (bit > 0)
        {
            printf("total %lld\n", bit);
        }

        for (ll i = 0; i < a; i++)
        {
            struct stat dir = {0};
            char pt[length];
            if (cd[1][0] == slash)
            {
                strcpy(pt, cd[1]);
            }
            else
            {
                getcwd(pt, sizeof(pt));

                if (strcmp("~", cd[1]) != 0 && strcmp(".", cd[1]) != 0)
                {
                    strcat(pt, h);
                    strcat(pt, cd[1]);
                }
            }
            if (dr != NULL)
            {
                strcat(pt, h);
                strcat(pt, fls[i]);
            }
            char perm[11];
            ll b = stat(pt, &dir);
            // for directory
            ll isdir = S_ISDIR(dir.st_mode);
            // for Owner Permissions
            ll irusr = (dir.st_mode & S_IRUSR);
            ll iwusr = (dir.st_mode & S_IWUSR);
            ll ixusr = (dir.st_mode & S_IXUSR);
            // for Group Permissions
            ll irgrp = (dir.st_mode & S_IRGRP);
            ll iwgrp = (dir.st_mode & S_IWGRP);
            ll ixgrp = (dir.st_mode & S_IXGRP);
            // for Others Permissions
            ll iroth = (dir.st_mode & S_IROTH);
            ll iwoth = (dir.st_mode & S_IWOTH);
            ll ixoth = (dir.st_mode & S_IXOTH);
            if (b == 0)
            {
                perm[0] = isdir ? 'd' : '-';

                perm[1] = irusr ? 'r' : '-';

                perm[2] = iwusr ? 'w' : '-';

                perm[3] = ixusr ? 'x' : '-';

                perm[4] = irgrp ? 'r' : '-';

                perm[5] = iwgrp ? 'w' : '-';

                perm[6] = ixgrp ? 'x' : '-';

                perm[7] = iroth ? 'r' : '-';

                perm[8] = iwoth ? 'w' : '-';

                perm[9] = ixoth ? 'x' : '-';

                perm[10] = null;

                ll lk = dir.st_nlink;
                char time[100];
                struct passwd *pass = getpwuid(dir.st_uid);
                struct group *grp = getgrgid(dir.st_gid);
                char *owner = pass->pw_name;
                char *group = grp->gr_name;
                ll size = dir.st_size;
                time_t t = dir.st_mtime;
                struct tm Tim;
                localtime_r(&t, &Tim);
                strftime(time, sizeof(time), "%b %d %Y %H:%M", &Tim);
                char *f = fls[i];

                printf("%s  %lld\t%s\t%s\t%lld\t%s  ", perm, lk, owner, group, size, time);
                if (S_ISDIR(dir.st_mode) && b == 0)
                {
                    printf("\033[1;34m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else if ((dir.st_mode & S_IXUSR) && b == 0)
                {
                    printf("\033[1;32m");
                    printf("%s\n", fls[i]);
                    printf("\033[0m");
                }
                else
                {
                    printf("%s\n", fls[i]);
                }
            }
        }
        closedir(dr);
    }
    else if (p == 2 && f == 2)
    {
        struct dirent *direct;
        DIR *dr;
        if (strcmp("~", cd[1]) == 0)
        {
            dr = opendir(hm);
        }
        else
        {
            dr = opendir(cd[1]);
        }
        ll a = 0;
        if (dr != NULL)
        {
            while ((direct = readdir(dr)) != NULL)
            {
                fls[a] = direct->d_name;
                a++;
            }
            closedir(dr);
        }
        if (dr == NULL)
        {
            fls[0] = cd[1];
            a = 1;
        }
        // SORTING...........

        ll i;
        ll j;
        for (i = 0; i < a - 1; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                ll result;
                result = strcasecmp(fls[j + 1], fls[j]);
                char *tmp;
                if (result < 0)
                {
                    tmp = fls[j];
                    fls[j] = fls[j + 1];
                    fls[j + 1] = tmp;
                }
            }
        }

        for (ll i = 0; i < a; i++)
        {
            struct stat dir = {0};
            char pt[length];
            if (cd[1][0] == slash)
            {
                strcpy(pt, cd[1]);
            }
            else
            {
                getcwd(pt, sizeof(pt));

                if (strcmp("~", cd[1]) != 0 && strcmp(".", cd[1]) != 0)
                {
                    strcat(pt, h);
                    strcat(pt, cd[1]);
                }
            }
            ll k;
            strcat(pt, h);
            strcat(pt, fls[i]);
            k = stat(pt, &dir);
            if (S_ISDIR(dir.st_mode) && k == 0)
            {
                printf("\033[1;34m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else if ((dir.st_mode & S_IXUSR) && k == 0)
            {
                printf("\033[1;32m");
                printf("%s\n", fls[i]);
                printf("\033[0m");
            }
            else
            {
                printf("%s\n", fls[i]);
            }
        }
    }
}