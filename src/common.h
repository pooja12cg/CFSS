
#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct userDetails
{
	int _uphnno;
	char _uname[30];
}UD;


typedef struct  loginDetails
{
	int _uphnno;
	char _uname[30];
	int  _password;
}LD;
void Welcome();
UD * signUp(UD *);
UD * Login(UD *);
int sinIn(LD *);
int readUD(UD *);
int readLD(LD *);
int writeUD(UD *);
int writeLD(LD *);

void dispUD(UD *);

#endif
