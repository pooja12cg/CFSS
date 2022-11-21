
#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct userDetails
{
	int _uphnno;
	char _uname[30];
	struct userDetails *next;
}UD;


typedef struct  loginDetails
{
	int _uphnno;
	char _uname[30];
	char _passwd[30];
	struct loginDetails *next;
}LD;

void Welcome();
int dispMainMenu();
//int dispSubMenu();
UD *loadUD();
LD *loadLD();
UD * signUp(UD *, int*);
LD * signInDetails(LD *, int);
int Login(LD *);
int readUD(UD *);
int readLD(LD *);
int writeUD(UD *);
int writeLD(LD *);

void dispUD(UD *);
void dispLD(LD *);

int tokenizeUD(UD *, char *);
int tokenizeLD(LD *, char *);

void removeLeading(char *, char*);
void removeTrailing(char *);


#endif
