#include "general.h"
#include "symTable.h"

int lex();
int charClass;
int token;
int nextToken;

Symbol_table table;
VALUE val;


 
 /* expr
   Parses strings in the language generated by the rule:
   <expr> -> <term> {(+ | -) <term>}
 */
 void expr() 
{
   printf("Enter <expr>\n");

   /* Parse the first term */
   term();

   /* As long as the next token is + or -, get
      the next token and parse the next term */
   while (nextToken == ADD_OP || nextToken == SUB_OP) {
      lex();
      term();
   }
   printf("Exit <expr>\n");

} /* End of function expr */

/* term
 *  Parses strings in the language generated by the rule:
 *  <term> -> <factor> {(* | /) <factor>)
 */
void term() 
{
   printf("Enter <term>\n");
   /* Parse the first factor */
   factor();
   /* As long as the next token is * or /, get the
      next token and parse the next factor */
   while (nextToken == MULT_OP || nextToken == DIV_OP) {
      lex();
      factor();
   }
   printf("Exit <term>\n");

} /* End of function term */


/* factor
 * Parses strings in the language generated by the rule:
 * 
 *   <factor> -> id | int_constant | ( <expr  )
 *
 */
void factor() 
{
   printf("Enter <factor>\n");
   /* Determine which RHS */
   if (nextToken == IDENT || nextToken == INT_LIT)
      /* Get the next token */
      lex();

   /* If the RHS is ( <expr> ), call lex to pass over the left 
      parenthesis, call expr and check for the right parenthesis */
   else if (nextToken == LEFT_PAREN) {
         lex();
         expr();
         if (nextToken == RIGHT_PAREN)
            lex();
         else
            error("Right without left paren");
   } else {
   /* It was not an id, an integer literal, or a left
       parenthesis */
       error("expected an id, integer, or a left paren");
   } /* End of else */
   printf("Exit <factor>\n");;
}/* End of function factor */

 void stmt()
{
	printf("Enter stmt\n");	
	if(nextToken==IDENT)
	{
		lex();	
		if (nextToken==ASSIGN_OP)
		{
		lex();
		expr();
		}
}
	 printf("Exit <stmt>\n");
}

 void stmt_list()
 {
	 printf("Enter stmt_list\n");
	 stmt();
	 
	 if (nextToken==NEWLINE)
	 {
	 lex();
	 //stmt(); 
	 }
	 printf("Exit <stmt_list>\n");
 }
 
 


void error(const char *message)
{
   printf("Error: %s\n",message);
}