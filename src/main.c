#include<stdio.h>
#include<stdlib.h>
#define BUFFER 25
typedef struct personalDetails
{
	int phNo[10];
	char uName[BUFFER];
	char simType[BUFFER];
}PD;

void getUserDetails(PD *);
int dispUserDetails(PD *);
int regist(PD *, char, int);
int activate();
int deactivate();
int unregister();

int regist(PD *p,char uName,int phNo)
{
	printf("\n----------USER REGISTERATION--------------\n");
	
	printf("\nEnter User Name: ");
	scanf("\n%s",p->uName);
	getchar();
	printf("\nEnter Sim Type: ");
	scanf("\n%s",p->simType);
	
	printf("\nEnter phone number: ");
	scanf("\n%d",&p->phNo);
	return 0;

}

int main()
{
	PD *p=NULL;
	char _uName;
	int _phNo;
	int choice=1;
	regist(p,_uName,_phNo);
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

