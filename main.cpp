
#include "general.h"

/******************************************************/
/* main driver */
int main(void)
{
   /* Open the input data file and process its contents */
   getChar();
   do
   {
      lex();
      stmt_list();
      getChar();
   } while (nextToken != EOF);
}