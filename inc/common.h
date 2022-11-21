/*******************************************************************************
**	FILE NAME       :	common.h
**
**	DESCRIPTION	:	this file includes standard header files, macros definition,
**				structure prototype, global variables, function prototypes
**				which are utilized in main1.c and common.c	
** 						
**	 NAME		  DATE			   REFERENCE		REASON
**	Group04		21-11-2022              Initial Version          
*********************************************************************************/

/********************************************************************************
* *					USER DEFINED HEADER NAME
*********************************************************************************/
#ifndef COMMON_H
#define COMMON_H
/***************************************************************************
*                        STANDARD HEADER FILES
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/***************************************************************************
*                        GLOBAL DECLARATIONS
****************************************************************************/


/***************************************************************************
*                        STRUCTURE 1
****************************************************************************/
typedef struct userDetails
{
	int _uphnno;/*hold a phone number of an user while registering*/
	char _uname[30];/*hold a name  of an user while registering*/
	struct userDetails *next; /*next pointer pointing to userDetails structure*/
}UD;/*declared a name for userDetails structure using typedef*/
/***************************************************************************
*                        STRUCTURE 2
****************************************************************************/

typedef struct  loginDetails
{
	int _uphnno;/*hold a phone number of an user during registration*/
	char _uname[30];/*hold a name  of an user during registration*/
	char _passwd[30];/*contain password of an user during registration*/
	struct loginDetails *next; /*next pointer pointing to loginDetails structure*/
}LD;/*declared a name for loginDetails structure using typedef*/
/***************************************************************************
*                        FUNCTION PROTOTYPES
****************************************************************************/
void Welcome();/*Declaring Welcome function*/
int dispMainMenu();/*Declaring dispMainMenu function*/
//int dispSubMenu();
UD *loadUD();
LD *loadLD();
UD * signUp(UD *, int*);
LD * signInDetails(LD *, int*);
int Login(LD *);/*Declaring login with struct-loginDetails pointer as a parameter passing inside function*/
int readUD(UD *);/*Declaring readUD with struct-userDetails pointer as a parameter passing inside function*/
int readLD(LD *);/*Declaring readLD with struct-loginDetails pointer as a parameter passing inside function*/
int writeUD(UD *);/*Declaring writeUD with struct-userDetails pointer as a parameter passing inside function*/
int writeLD(LD *);/*Declaring writeLD with struct-loginDetails pointer as a parameter passing inside function*/

void dispUD(UD *);/*Declaring dispUD with struct-userDetails pointer as a parameter passing inside function*/
void dispLD(LD *);/*Declaring dispLD with struct-loginDetails pointer as a parameter passing inside function*/

int tokenizeUD(UD *, char *);/*Declaring tokenizeUD with struct-userDetails pointer and a pointer pointing to char data type as parameters passing inside function*/
int tokenizeLD(LD *, char *);/*Declaring tokenizeLD with struct-loginDetails pointer and a pointer pointing to char data type as parameters passing inside function*/

void removeLeading(char *, char*);/*Declaring  removeLeading with two pointers pointing to char data type as parameters passing inside function*/
void removeTrailing(char *);/*Declaring  removeTrailing with  a pointer pointing to char data type as parameter passing inside function*/


#endif
