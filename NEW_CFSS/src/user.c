#include <common.h>
/*
void cfsRegistrtion(CFSS *head)
{


}
void cfsUnregister(CFSS *head)
{

}*/
int cfsActive=0;
void cfsActivation(CFSS *cfss)
{
	//int cfsActive=0;
	//CFSS _cfss;


	int cfsNumber=0;
	int flag =0;
	int cfs =0;

	/*struct CFSS *cfss =(struct CFSS*)malloc(sizeof(struct CFSS));
	cfss->_id=_id;
	strcpy(CFSS->regFlag, regFlag);
	cfss->nextNode=NULL;
	if(*/



	/*FILE *fp = NULL;
	fp = fopen("CFSS.dat","w+");
	fseek(fp, 0L, SEEK_END);
	if(_id!= NULL)*/


	printf("\n\tDo you want to activate Call Forwarding services(0/1) : ");
	scanf("%d",&cfsActive);
	if(cfsActive)
	{
		flag=1;
		printf("\n\tEnter the call forwarding number :");
		scanf("%d",&cfsNumber);
		printf("\n\tPress \n\t1.Unconditional \n\t2.No Reply \n\t3.Busy ");
		printf("\n\tChoice :");
		scanf("%d",&cfs);
		switch(cfs)
		{
			case 1:
				printf("\n\tCall has been forwarded to ");
				printf("%d Unconditional type",cfsNumber);
				break;
			case 2:
				printf("\n\tCall has been forwarded to ");
				printf("%d No Reply type",cfsNumber);
				break;

			case 3:
				printf("\n\tCall has been forwarded to ");
				printf("%d Busy type",cfsNumber);
				break;
			default:
				printf("\n\tEnter a Correct Choice");
		}
		//head = head->next;
	}
	
	else
	{
		printf("\n\tCall forwarding has not been activated");
	}

}



void cfsDeactivation(CFSS *cfss)
{
	if(cfsActive==0)
	{
		printf("\n\t User has not activated Call forwarding services ");
	}
	else
	{
		printf("\n\tDeactivation Successful");
		cfsActive = 0;
	}
	//head = head->next;

}

