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

#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct userDetails
{
	int id;
	int uphnno;
	char uname[30];
	int regFlag;
	struct userDetails *next;
}UD;


typedef struct  loginDetails
{
	int id;
	char uname[30];
	char passwd[30];
	struct loginDetails *next;
}LD;

typedef struct Cfss
{
	int id;
	int regFlag;
	int cfs_num;
	int cfs_active;
	char status[20];
	struct Cfss *next;

}CFSS;

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

void tokenizeUD(UD *, char *);
void tokenizeLD(LD *, char *);

void removeLeading(char *, char*);
void removeTrailing(char *);


#endif
