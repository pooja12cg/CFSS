/*******************************************************************
 ** FILE_NAME      :   user.c
 **
 ** DESCRIPTION    :   this file is used to execute user related function
 **                        
 **
 ** Revision History :
 ** Date		Name 		Reference 		Reason
 **
 ** 25-11-2022          Group04          New                  user related function
 **
 ** Copyright 2022,Altran Group All Rights Reserved
 **
 *************************************************************
 ** RETURN_TYPE    :   returns success or failure
 ************************************************************/

/***************************************************************
 *                      HEADER FILE
 * ************************************************************/

#include <common.h>


/*******************************************************************
 ** FUNCTION_NAME  :  cfsActivation
 **
 ** DESCRIPTION    :   It helps to active the system
 **                        
 ** RETURN_TYPE    :   returns success or failure
 ************************************************************/
void cfsActivation(CFSS *cfss, UPD *upd, int refID)/*fuction*/
{
	int cfsActive=0;/*cfsActive is a interger, variable declaration*/
	int cfsNumber=0;/*cfsNumber is a interger, variable declaration*/
	int flag = 0;/*flag  a interger, variable declaration*/
	int cfs =0;/*cfs is a interger type variable used to in swirch case*/

	while(upd != NULL)
	{
		if(upd->_id == refID)/*refID value will be stored in this id*/
		{
			flag++;/*flag value will increase*/
			upd->regFlag = 1;
			break;/*break statement*/
		}
		upd = upd->next;
	}

	


	while(cfss != NULL)
	{
		if(cfss->_id == refID)/*refID value will be stored in this id*/
		{
			flag++;/*flag value will increase*/
			cfss->regFlag = 1;
			break;/*break statement*/
		}
		cfss = cfss->next;
	}

	printf("\n\tDo you want to activate Call Forwarding services(0/1) : ");/*asking about activation*/
	scanf("%d",&cfsActive);/*read that value*/
	if(cfsActive)/*value will go through this if statement*/
	{
		flag=1;
		cfss->cfsActive = 1;
		printf("\n\tEnter the call forwarding number :");/*in which number call will be forwarded*/
		scanf("%d",&cfsNumber);/*call forwarding number will be stored*/
		cfss->cfsNumber = cfsNumber;
		printf("\n\tPress \n\t1.Unconditional \n\t2.No Reply \n\t3.Busy ");/*types of call forwarding*/
		printf("\n\tChoice :");/*choose the option*/
		scanf("%d",&cfs);/*read the option*/
		switch(cfs)/*switch case*/
		{
			case 1:
				/*for uncontional type*/
			/*	printf("\n\tYour Call has been forwarded to Unconditional type");*/
				strcpy(cfss->status, "Unconditional");
				printf("\n\tYour Call has been forwarded to Unconditional type");
				break;
			case 2:
                               /*for No reply type*/
				strcpy(cfss->status, "No Reply");
				printf("\n\tYour Call has been forwarded to No Reply type");
				
				break;

			case 3:
				/*for Busy type*/
				strcpy(cfss->status, "Busy");
				printf("\n\tYour Call has been forwarded to Busy type");
				break;
			default:
				printf("\n\tEnter a Correct Choice");
		}
	}
	
	else
	{
		printf("\n\tCall forwarding has not been activated");
	}

}
/*******************************************************************
 **  FUNCTION_NAME  :   cfsDeactivation
 ** 
 **  DESCRIPTION    :   It helps to the system is deactive or not
 **                        
 **  RETURN_TYPE    :   returns success or failure
 ************************************************************/
void cfsDeactivation(CFSS *cfss)/*function */
{
	int cfsActive=0;

	printf("\n\tDo you want to deactivate the call(0/1): ");/*for deactivation*/
	scanf("%d",&cfsActive);
	if(cfsActive==1)
	{
		printf("\tDeactivated Call forwarding services ");
	}
	else
	{
		printf("\tUser has not activated Call forwrding services");
		cfsActive = 0;
	}
	//head = head->next;

}

/*******************************************************************
 ** FUNCTION_NAME  :  makecall 
 **
 ** DESCRIPTION    :  it help to enable the system
 **                        
 **  RETURN_TYPE    :   returns success or failure
 ************************************************************/
void makeCall(UPD *hupd, CFSS *hcfss, int phno)/*make call function*/
{
	int refID = 0, flag =0;

	while(hupd != NULL)
	{
		if((hupd->_phNo == phno)&&(hupd->regFlag == 1))
		{
			flag++;
			refID = hupd->_id;
			break;

		}
		hupd = hupd->next;
	}

	if(flag == 1)
	{
		while(hcfss != NULL)
		{
			if((hcfss->_id == refID)&&(hcfss->cfsActive == 1))
			{
				flag++;
				break;
			}
			hcfss = hcfss->next;
		}

		
		
	}
	if(flag>=2){
		printf("\n\tUser has reg for %s", hcfss->status);
		printf("\n\tCall has been forwarded to %d \n\n", hcfss->cfsNumber);
	}
	else{
		printf("\n\tCall has been established\n\n");
	}
}
