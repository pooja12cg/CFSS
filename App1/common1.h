/*******************************************************************************
			USER DEFINED MACROS
*********************************************************************************/
#ifndef COMMON_H
#define COMMON_H
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/*******************************************************************************
			STRUCTURES
*********************************************************************************/
typedef struct personalDetails
{
	int _id;
	int _phNo;
	char _name[30];
	char _gender;
	int regFlag;
	struct personalDetails *next;

}PD;

typedef struct loginDetails
{
	int _id;
	char _uName[30];
	char _passwd[30];
	struct loginDetails *next;
}LD;
typedef struct callForwarding
{
	int _id;
	int regFlag;
	int cfsNumber;
	int cfsActive;
	char status[20];
	struct callForwarding *next;
}CFSS;

/*******************************************************************************
				FUNCTION DECLARATIONS
*********************************************************************************/
PD *loadPD();
LD *loadLD();
CFSS *loadCFFS();
PD* signUp(PD *, int*);
LD* signInDetails(LD *, int);

/*******************************************************************************
				FUNCTION DECLARATIONS
*********************************************************************************/
int signIn(LD *);
int readPD(PD *);
int writePD(PD *);
int readLD(LD *);
int writeLD(LD *);
int readCFSS(CFSS *);
int writeCFSS(CFSS *);

void cfsActivation(CFSS *);
void cfsDeactivation(CFSS *);

void dispPD(PD *);
void dispLD(LD *);
int tokenizePD(PD *, char *);
int tokenizeLD(LD *, char *);
int tokenizeCFSS(CFSS *,char *);
void removeLeading(char *, char*);
void removeTrailing(char *);

#endif
