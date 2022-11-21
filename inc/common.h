<<<<<<< HEAD
=======
/*******************************************************************************
**	FILE NAME       :	common.h
**
**	DESCRIPTION	:	this file includes standard header files, macros definition,
**				structure prototype, global variables, function prototypes
**				which are utilized in main1.c and common.c	
** 						
** DATE		 NAME		     REFERENCE		REASON
**
**21-11-2022    Group04	                New	    Initial Version          
**
**
**  Copyright 2010, Aricent Technologies (Holdings) Ltd
*********************************************************************************/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6

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
//int dispMainMenu();
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
