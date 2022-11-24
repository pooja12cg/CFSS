#include <common.h>

void cfsActivation(CFSS *cfss, UPD *upd, int refID)
{
	int cfsActive=0;
	int cfsNumber=0;
	int cfs=0;
	int flag=0;

	while(upd != NULL)
	{
		if(upd->_id == refID)
		{
			flag++;
			upd->regFlag = 1;
			break;
		}
		upd = upd->next;
	}

	
	while(cfss != NULL)
	{
		if(cfss->_id == refID)
		{
			flag++;
			cfss->regFlag = 1;
			break;
		}
		cfss = cfss->next;
	}

	printf("\n\tDo you want to activate Call Forwarding services(0/1) : ");
	scanf("%d",&cfsActive);
	if(cfsActive)
	{
		flag=1;
		cfss->cfsActive = 1;
		printf("\n\tEnter the call forwarding number :");
		scanf("%d",&cfsNumber);
		cfss->cfsNumber = cfsNumber;
		printf("\n\tPress \n\t1.Unconditional \n\t2.No Reply \n\t3.Busy ");
		printf("\n\tChoice :");
		scanf("%d",&cfs);
		switch(cfs)
		{
			case 1:
				strcpy(cfss->status, "Unconditional");
				/*printf("\n\tCall has been forwarded to ");
				printf("%d Unconditional type",cfsNumber);*/
				break;
			case 2:
				strcpy(cfss->status, "No Reply");
				
				/*printf("\n\tCall has been forwarded to ");
				printf("%d No Reply type",cfsNumber);*/
				break;

			case 3:
				strcpy(cfss->status, "Busy");
				/*printf("\n\tCall has been forwarded to ");
				printf("%d Busy type",cfsNumber);*/
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
	/*if(cfsActive==0)
	{
		printf("\n\t User has not activated Call forwarding services ");
	}
	else
	{
		printf("\n\tDeactivation Successful");
		cfsActive = 0;
	}*/
	//head = head->next;

}

void makeCall(UPD *hupd, CFSS *hcfss, int phno)
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
