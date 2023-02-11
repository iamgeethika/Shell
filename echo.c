#include "headers.h"
#include "macros.h"

ll echo_command(char **cd, ll p)
{
   for (ll i = 1; i < p; i++)
   {
      printf("%s ", cd[i]);
   }
   printf("\n");
   return 0;
}
