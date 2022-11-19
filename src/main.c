#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#define BUFFER 256

itypedef struct personalDetails
{
	        int phNo;
		        char uName[BUFFER];
			        char simType[BUFFER];
}PD;
typedef struct personalDetails
{
	int phNo;
	char uName[BUFFER];
	char simType[BUFFER];
}PD;


int getUserDetails(PD *);
//void dispUserDetails(PD *,int, int);

int getUserDetails(PD *p)
{
	
	printf("\n----------USER REGISTERATION--------------\n");
	
	printf("\n\tEnter User Name: ");
	scanf("%s", p->uName);
	getchar();

	printf("\n\tEnter Sim Type: ");
	scanf("%s", p->simType);
	getchar();

	printf("\nEnter phone number: ");
	scanf("\n%d",&p->phNo);
	return 1;
}
/*void dispUserDetails(PD *p, int Cap, int flag)
{
	int i;
	printf("User data");
	if 
*/
int main()
{
	PD *p;
	/*int choice=1;*/
	getUserDetails(p);
	/*while(1)
	{
		switch(choice)
		{
			case 1:
			       regist(p,_uName,_phNo);	       
			break;			
		}*/
	return 0;
}
/*
int getUserDetails(PD *p)
{
	
	printf("\n----------USER REGISTERATION--------------\n");
	
	printf("\nEnter User Name: ");
	scanf("\n%s", p->uName);
	getchar();	
	printf("\nEnter Sim Type: ");
	scanf("\n%s", p->simType);
	getchar();

	printf("\nEnter phone number: ");
	scanf("\n%d",&p->phNo);
	return 1;
}*/

