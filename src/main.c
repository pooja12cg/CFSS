#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER 25
typedef struct personalDetails
{
	int phNo;
	char uName[BUFFER];
	char simType[BUFFER];
}PD;


int getUserDetails(PD *);



int getUserDetails(PD *p)
{
	
	printf("\n----------USER REGISTERATION--------------\n");
	
	printf("\nEnter User Name: ");
	scanf("\n%s",p->uName);
	getchar();	
	printf("\nEnter Sim Type: ");
	scanf("\n%s",p->simType);

	printf("\nEnter phone number: ");
	scanf("\n%d",&p->phNo);
	return 1;
}

int main()
{
	PD *p=NULL;
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

