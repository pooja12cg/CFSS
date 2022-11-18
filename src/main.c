#include<stdio.h>
#include<stdlib.h>
#define BUFFER 25
typedef struct personalDetails
{
	int phNo[BUFFER];
	char uName[BUFFER];
	char simType[BUFFER];
}PD;

void getUserDetails(PD *);
int dispUserDetails(PD *);
int register1();
int activate();
int deactivate();
int unregister();

int register1(PD *p,char uName,int phNo)
{
	printf("\n----------USER REGISTERATION--------------\n");
	
	printf("\nEnter User Name: ");
	fgets(uName,BUFFER,stdin);
	
	printf("\nEnter Sim Type: ");
	scanf("\n%s",p->simType);
	
	printf("\nEnter phone number: ");
	scanf("\n%d",&p->phNo);

}

int main()
{
	int choice=1;
	while(1)
	{
		switch(choice)
		{
			case 1:
			       register1(p,uName,phNo);	       
					/*REGISTER*/
			case 2: 

			break;

			case 3:
		}
	}
}

