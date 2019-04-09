#ifndef gen_h
#define gen_h
#define TABLE_SIZE 211
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef union {
   int ivalue;
   char cvalue;
   double dvalue;
} VALUE;

/* Global declarations */
/* Variables */
extern char lexeme[100];
extern char nextChar;
extern int lexLen;
extern FILE *in_fp, *fopen();

/* Function declarations */

void addChar();
void getChar();
void getNonBlank();
extern int lex();

int expr();
int term();
int unary();
int expo();
int factor();
void error(const char *);

int stmt_list();
int stmt();

/* Character classes */
extern int charClass;
#define LETTER 2
#define DIGIT 3
#define OPERATOR 99

/* Token codes */
extern int token;
extern int nextToken;
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define MOD_OP 25
#define LEFT_PAREN 26
#define RIGHT_PAREN 27
#define EXPO_OP 28
#define UNARY_MINUS 29
#define NEWLINE 96
#define DUMP 900
#define QUIT 8

#define DEBUG

#endif