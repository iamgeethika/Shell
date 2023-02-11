#include "headers.h"
#include "macros.h"

ll cd_command(char **cd, ll p)
{
   // char t[length];

   // IMPLEMENTING THE FLAGS

   if (p == 1)
   {
      chdir(hm);
      return 0;
   }

   ll cd_len;
   cd_len = strlen(cd[1]);

   ll a, b, c, d;
   char t1[] = ".";
   a = strcmp(cd[1], t1);

   char t2[] = "..";
   b = strcmp(cd[1], t2);

   char t3[] = "~";
   c = strcmp(cd[1], t3);

   char t4[] = "-";
   d = strcmp(cd[1], t4);

   char dir[length];
   ll leng;
   leng = sizeof(dir);

   if (p == 2 && !a) // for "." after cd
   {
      getcwd(dir, leng);

      chdir(dir);
   }

   else if ((p == 2 && !b)) // for ".." after cd
   {
      getcwd(dir, leng);
      char *p;
      p = strrchr(dir, '/');

      char null = '\0';
      char ip[length];
      if (p)
      {
         ll i = 0;
         ll j = 0;
         ll diff = p - dir;
         diff -= 1;
         for (; i <= diff; i++, j++)
         {
            ip[j] = dir[i];
         }
         ip[j] = null;
         if (j == 0)
         {
            ip[j] = '/';
            ip[j + 1] = null;
         }
      }
      chdir(ip);
   }
   else if ((p == 2 && !c)) // for "~" after cd
   {
      chdir(hm);
   }

   else if ((p == 2 && !d)) // for "-" after cd
   {
      char home_str[length] = "/home/";
      chdir(prev);
      ll l;
      l = strlen(hm);
      char *p;
      p = strstr(prev, hm);
      if (!p)
      {
         printf("%s\n", prev);
      }
      else
      {
         p = p + l;
         strcat(home_str, user);
         strcat(home_str, p);
         printf("%s\n", home_str);
      }
   }

   else if (cd[1][0] == '~')
   {
      char home_str[length] = "/home/";
      char null = '\0';
      char t[length];

      ll i = 0;
      ll cd_len1;
      cd_len1 = cd_len - 1;
      for (; i < cd_len1; i++)
      {
         t[i] = cd[1][i + 1];
      }
      t[cd_len1] = null;
      strcat(home_str, user);
      strcat(home_str, t);
      chdir(home_str);
   }

   else if (cd[1][0] == '.' && cd[1][1] == '.')
   {
      char dir[length], prev[length];
      getcwd(dir, length);
      char *p;
      p = strrchr(dir, '/');

      char null = '\0';
      char ip[length];
      ll l2;
      l2 = strlen(dir);
      if (p)
      {
         ll l3;
         l3 = strlen(p);
         l3 = l2 - l3;
         for (ll i = 0; i <= l3; i++)
         {
            prev[i] = dir[i];
         }
         ll l5;
         l5 = l3 + 1;
         prev[l5] = null;
      }
      char t[length];
      ll i = 0;
      ll cd_len2;
      cd_len2 = cd_len - 2;
      for (; i < cd_len2; i++)
      {
         t[i] = cd[1][i + 2];
      }
      t[cd_len2] = null;

      strcat(prev, t);
      if (chdir(prev) == 0)
      {
      }
      else
      {
         perror("\033[0;31mError\033[0m");
      }
   }

   else if (cd[1][0] == '.')
   {
      char home_str[length];
      char null = '\0';
      char t[length];

      ll i = 0;
      ll cd_len1;
      cd_len1 = cd_len - 1;
      for (; i < cd_len1; i++)
      {
         t[i] = cd[1][i + 1];
      }
      t[cd_len1] = null;
      getcwd(home_str, length);
      strcat(home_str, t);
      chdir(home_str);
   }

   else if (chdir(cd[1]) != 0) // other than these 4 arguments
   {
      perror("\033[0;31mError\033[0m");
   }
   else
   {
      chdir(cd[1]);
   }
   return 1;
}
