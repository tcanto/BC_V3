
#include "general.h"

/******************************************************/
/* main driver */
int main(void) {
   /* Open the input data file and process its contents */
  // if ((in_fp = fopen("front.in", "r")) == NULL)
    //  printf("ERROR - cannot open front.in \n");
   //else {
      getChar();
      do {
        lex();
        stmt_list();
      } while (nextToken != EOF);
 
   //}
}
