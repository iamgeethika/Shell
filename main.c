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
#include "pipes.h"
#include "jobs.h"
#include "sig.h"
#include "fgbg.h"

int frkinp = -1;

void control_C(int s)
{
   if (frkinp != -1)
   {
      ll k;
      k = kill(frkinp, SIGINT);
   }
   printf("\n");

   char bef_dir[length];

   // char user[user_length], host[user_length];
   // char hm[length];
   char *p;
   // char user[user_length], host[user_length];
   getlogin_r(user, user_length + 1);
   gethostname(host, host_length + 1);
   getcwd(hm, length);
   ll l;
   l = strlen(hm);
   ll bl;
   bl = strlen(bef_dir);
   ll len;
   len = sizeof(bef_dir);
   strcpy(prev, bef_dir);
   if (getcwd(bef_dir, len) == NULL)
   {
     perror("\033[0;31mError\033[0m");
      return;
   }
   else
   {
      p = strstr(bef_dir, hm);

      if (p)
      {
         p = p + l;
         printf("\033[0;35m");
         printf("<%s@%s:~%s>", user, host, p);
         printf("\033[0m");
      }
      else
      {
         printf("\033[0;35m");
         printf("<%s@%s:%s>", user, host, bef_dir);
         printf("\033[0m");
      }
   }

   fflush(stdout);
   return;
}

void control_Z(int s)
{
   printf("\n");
   char bef_dir[length];

   // char user[user_length], host[user_length];
   // char hm[length];
   char *p;
   // char user[user_length], host[user_length];
   getlogin_r(user, user_length + 1);
   gethostname(host, host_length + 1);
   getcwd(hm, length);
   ll l;
   l = strlen(hm);
   ll bl;
   bl = strlen(bef_dir);
   ll len;
   len = sizeof(bef_dir);
   strcpy(prev, bef_dir);
   if (getcwd(bef_dir, len) == NULL)
   {
      perror("\033[0;31mError\033[0m");
      return;
   }
   else
   {
      p = strstr(bef_dir, hm);

      if (p)
      {
         p = p + l;
         printf("\033[0;35m");
         printf("<%s@%s:~%s>", user, host, p);
         printf("\033[0m");
      }
      else
      {
         printf("\033[0;35m");
         printf("<%s@%s:%s>", user, host, bef_dir);
         printf("\033[0m");
      }
   }

   // printf("\n");
   fflush(stdout);
   return;
}

int main()
{
   char bef_dir[length];

   // char user[user_length], host[user_length];
   // char hm[length];
   char *p;
   // char user[user_length], host[user_length];
   getlogin_r(user, user_length + 1);
   gethostname(host, host_length + 1);
   getcwd(hm, length);
   ll l;
   l = strlen(hm);
   ll bl;
   bl = strlen(bef_dir);

   ll his_count = 0;
   ll count = 0;

   // ctrl c and ctrl z

   signal(SIGINT, control_C);
   signal(SIGTSTP, control_Z);

   char temp[length];
   char path[length];
   strcpy(path, hm);
   strcat(path, "/history.txt");
   FILE *fp1 = fopen(path, "a+");
   fclose(fp1);
   fp1 = fopen(path, "r");
   while ((fscanf(fp1, "%[^\n]%*c", temp) != EOF))
   {
      strcpy(his_arr[count], temp);
      // printf("%s\n", temp);
      count++;
   }
   his_count = count;
   fclose(fp1);
   ll variabl = 1;
   while (1)
   {
      int b;
      pid_t pi;
      int st;

      while ((pi = waitpid(-1, &st, WNOHANG)) > 0)
      {
         int a = 0;
         ver[b] = -1;
         for (;; a++)
         {
            if (pid[a] == pi)
            {
               b = a;
               break;
            }
         }

         if (!WIFEXITED(st))
         {
            fprintf(stderr, "%s process with pid %d exited abnormally\n", proc[b], pi);
         }
         else
         {
            fprintf(stderr, "%s process with pid %d exited normally\n", proc[b], pi);
         }
         variabl--;
      }

      ll len;
      len = sizeof(bef_dir);
      strcpy(prev, bef_dir);
      if (getcwd(bef_dir, len) == NULL)
      {
        perror("\033[0;31mError\033[0m");
         return 0;
      }
      else
      {
         p = strstr(bef_dir, hm);

         if (p)
         {
            p = p + l;
            printf("\033[0;35m");
            printf("<%s@%s:~%s>", user, host, p);
            printf("\033[0m");
         }
         else
         {
            printf("\033[0;35m");
            printf("<%s@%s:%s>", user, host, bef_dir);
            printf("\033[0m");
         }
      }

      char inp[length];
      char *c[length];
      // scanf("%[^\n]%*c", inp);

      if (scanf("%[^\n]%*c", inp) == EOF)
      {
         printf("\n");
         exit(0);
      }

      hist(inp, &his_count);
      char s1[] = ";";
      char s2[] = "' ','\t','\n'";
      ll flagggggggg = 0;

      ll i = 0, cmd = 0;

      char *token;
      token = strtok(inp, s1);

      while (token != NULL)
      {
         c[i] = token;
         token = strtok(NULL, s1);
         cmd++;
         i++;
      }

      i = 0;
      while (cmd--)
      {
         //  for pipes

         ll flg;
         flg = 0;
         ll leng;
         leng = strlen(c[cmd]);
         int v;
         v = 0;

         for (; v < leng; v++)
         {
            if (c[i][v] == '|')
            {
               flagggggggg = 1;
            }
         }

         if (flagggggggg != 1)
         {
            v=0;
            for (; v < leng; v++)
            {

               if (c[i][v] == '<')
               {
                  red_command(c[i]);
                  flg++;
                  break;
               }
               if (c[i][v] == '>')
               {
                  red_command(c[i]);
                  flg++;
                  break;
               }

               // if (c[i][v] == '|')
               // {
               //    flagggggggg = 1;
               // }
            }
         }

         if (flg == 1)
         {
            break;
         }

         char string[1000];
         strcpy(string, c[i]);
         ll j = 0;
         char *c1[length];
         char *token1;
         token1 = strtok(c[i], s2);
         while (token1 != NULL)
         {
            c1[j] = token1;
            token1 = strtok(NULL, s2);
            j++;
         }
         if (flagggggggg == 0 && flg == 0)
         {
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
            ll jbs;
            jbs = strcmp(c1[0], "jobs");
            ll sig;
            sig = strcmp(c1[0], "sig");
            ll fg;
            fg = strcmp(c1[0], "fg");
            ll bg;
            bg = strcmp(c1[0], "bg");
            // ll rjbs;
            // rjbs = strcmp(c1[1], "-r");
            // ll sjbs;
            // sjbs = strcmp(c1[1], "-s");

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
               ll f1 = 0, f2 = 0;
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
                        f1 = 1;
                     }
                     else if (strcmp("-a", c1[i]) == 0)
                     {
                        f = 2;
                        f2 = 1;
                     }
                     else if (strcmp("-al", c1[i]) == 0 || strcmp("-la", c1[i]) == 0)
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
            else if (jbs == 0)
            {
               ll flggg = 0;
               if (j == 1)
               {
                  flggg = 0;
               }
               if (j == 2 && strcmp(c1[1], "-r") == 0)
               {
                  flggg = 1;
               }
               if (j == 2 && strcmp(c1[1], "-s") == 0)
               {
                  flggg = -1;
               }
               jobs_command(flggg);
            }
            else if (sig == 0)
            {
               if (j != 3)
               {
                  printf("\033[0;31m");
                  printf("Invalid Arguments\n");
                  printf("\033[0m");
               }
               else
               {
                  sig_command(c1, j);
               }
            }
            else if (fg == 0)
            {
               if (j != 2)
               {
                  printf("\033[0;31m");
                  printf("Invalid Arguments\n");
                  printf("\033[0m");
               }
               else
               {
                  fg_command(c1, j);
               }
            }
            else if (bg == 0)
            {
               if (j != 2)
               {
                  printf("\033[0;31m");
                  printf("Invalid Arguments\n");
                  printf("\033[0m");
               }
               else
               {
                  bg_command(c1, j);
               }
            }
            else
            {
               fbg_command(string, j, &variabl);
            }

            i++;
         }
         else if (flg == 1 && flagggggggg == 0)
         {
            red_command(string);
         }
         else if (flagggggggg == 1)
         {
            pipes_command(string);
         }
      }
   }
   return 0;
}