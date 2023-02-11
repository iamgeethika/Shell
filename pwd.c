#include "headers.h"
#include "macros.h"


ll pwd_command(char **cd, ll p)
{
   char dir[length];
   ll leng;
   leng = sizeof(dir);

   getcwd(dir, leng);
   printf("%s\n", dir);
   return 0;
}
