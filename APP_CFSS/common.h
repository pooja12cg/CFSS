#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef struct userPersonalDetails
{
	int _id;
	int _phNo;
	char _uName[30];
	char _gender;
	int regFlag;
	struct userPersonalDetails *next;

}UPD;

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
UPD *signUp(UPD *, int*);
LD *signInDetails(LD*, int);
int  signInUser(LD *);

UPD * loadUPD();
LD * loadLD();
CFSS * loadCFSS();

int tokenizeUPD(UPD *, char*);
int tokenizeLD(LD *, char*);
int tokenizeCFSS(CFSS *, char*);

int writeUPD(UPD *);
int writeLD(LD *);
int writeCFSS(CFSS *);

int readUPD(UPD *);
int readLD(LD *);
int readCFSS(CFSS *);

void removeLeading(char *, char*);
void removeTrailing(char *);

void AdminLogin();
int UpdateDetails(UPD *);
void cfsActivation(CFSS *);
void cfsDeactivation(CFSS *);


#endif
