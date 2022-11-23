#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

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


PD *loadPD();
LD *loadLD();
CFSS *loadCFFS();
PD* signUp(PD *, int*);
LD* signInDetails(LD *, int);

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

void removeLeading(char *, char*);
void removeTrailing(char *);

#endif
