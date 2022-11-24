/*************************************************************************
* *
* *  FILE NAME    : main.c
* *
* *  DESCRIPTION  : Demonstrates a call forwarding simulator application  consists of configurable database and users. This provides call forwarding services.			  It validates a user  request, and if requested user has enabled call forwarding service, then it establishes connection between the  				requesting user and intended forwarding user. User can enable/disable service at run time
* *
* *     DATE       NAME       REFERENCE          REASON
* *
* *  21-11-2022   Group04       New          Initial Creation.
* *
* *  Copyright 2010, Aricent Technologies (Holdings) Ltd
* *
* **************************************************************************/

/*************************************************************************
* *				HEADER FILES
* *************************************************************************/
#include <common.h>
#include <configMenu.h>

int main()
{
	PD *pd = NULL;/*pointer pd pointing to structure personalDetails initialized to NULL value*/
	PD *headpd = NULL;/*pointer headpd pointing to structure personalDetails initialized to NULL value*/
	LD *ld = NULL;/*pointer ld pointing to structure loginDetails initialized to NULL value*/
	LD *headld = NULL;/*pointer headld pointing to structure loginDetails initialized to NULL value*/
	CFSS *cfss = NULL;/*pointer cfss pointing to structure CFSS initialized to NULL*/
	CFSS *headcfss= NULL;/*pointer headcfss pointing to structure CFSS initialized to NULL*/

	int login=0;/*holds login data*/
	int user=0;/*holds user data*/
	int ch1=0;/*holds choice*/
	int cfs=0;/*holds call forwarding active or not*/
	int ch = 0;/*holds choice*/
        int _id=0;/*holds id of user*/
	int regFlag=0;/*holds whether user registered active or not*/
	int cfsNumber=0;/*holds whether call forwarding number is active or not*/ 
	headpd = loadPD(pd);/*pointer headpd heading towards loadPD function*/
	/*if(headpd == NULL)
	{
		headpd = (PD *)malloc(sizeof(PD));
		headpd->next = NULL;
		
		printf("\n\tNULLPD\n");
	}*/
	pd = headpd;/*base address and head of list is pointing to same in personalDetails structure*/
	headcfss = loadCFSS(cfss);/*pointer headcfss heading towards loadCFSS function*/
	cfss = headcfss;/*base address and head of list is pointing to same in CFSS structure*/
	
	headld = loadLD(ld);/*pointer headud heading towards loadLD function*/
	/*if(headld == NULL)
	{
		headld = (LD *)malloc(sizeof(LD));
		headld->next = NULL;
		printf("\n\tNULLLD\n");
	}*/
	ld = headld;/*base address and head of list is pointing to same in loginDetails structure*/
	int flag;/*holds whether high or low value*/
	int act;/*holds whether user is active or not*/

	while(1){

		system("clear");
		printf("%s", WelCome);/*displaying formatted output*/
		printf("%s", MainMenu);/*displaying formatted output*/
		scanf("%d",&ch);/*reads input*/
		
		switch(ch)
		{
			case 1:
				headpd = signUp(headpd,&_id);/*pointer headud heading towards signUp function*/
				headld = signInDetails(headld, _id);/*pointer headud heading towards signInDetails function*/
				/*dispPD(headpd);
				dispLD(headld);
				writePD(headpd);
				 writeLD(headld);
				headpd = pd;
				headld = ld;*/
				printf("\n\tSuccessfully Registered\n");/*printing formatted output*/
				sleep(2);/*sleep is implemented to display after 2 seconds*/
				break;

			case 2:
				/*readPD(headpd);*/

				printf("\n\t******************LOGIN PAGE ****************");/*printing formatted output*/
				printf("\n\tPress \n\t1.Login as Admin \n\t2.Login as User \n\tChoose :");/*printing formatted output*/
				scanf("%d",&login);/*reads input*/
				switch (login)
				{
					case 1:
						/*AdminLogin();*/
						break;
					case 2:
						if(signIn(headld) == 0)
						{
							printf("\n\tUser/password does not match database\n");/*printing formatted output*/
						}
						else
						{

							printf("\n\tSUCCESSFULLY LOGGED IN\n");/*printing formatted output*/
							int regFlag=1;/*holds that user is registered*/
						}
					

						printf("\n\tPress \n\t1.Register for CFSS \n\t2.Unregister for CFSS \n\t3.Make	a call \n\t4.Exit ");/*printing formatted output*/
						printf("\n\tEnter your Choice : ");/*printing formatted output*/
						scanf("%d",&user);/*reads input*/
						int PhoneNo;/*holds phone numner of user*/
						switch(user)
						{
							case 1 :
								printf("\n\t************CFSS REGISTRATION PAGE***********");/*printing formatted output*/
								printf("\n\tPress \n\t1.Activate Call Forwarding");/*printing formatted output*/
								printf("\n\t2.Deactivate Call Forwarding ");/*printing formatted output*/
								printf("\n\t3.Return to previous menu");/*printing formatted output*/
								printf("\n\tEnter your Choice : ");/*printing formatted output*/
								scanf("%d",&ch1);/*reads input*/
								switch(ch1)
								{
									case 1 :
										printf("\n\tCALL FORWARDING ACTIVATION PAGE");/*printing formatted output*/
										cfsActivation(headcfss);/*function calling*/
										/*printf("\n\tDo you want to activate Call Forwarding services(0/1) : ");
										scanf("%d",&act);
										if(act)
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
											break;
										}
										else
										{
											printf("\n\tCall forwarding has not been activated");
											break;
										}
										break;*/

									case 2 :
										/*printf("\n\t3.Return to deactive menu");*/
										cfsDeactivation(headcfss);/*function calling*/
										break;
									case 3 :
										printf("\n\tReturning to previous menu");/*printing formatted output*/
										break;

									default :
										printf("\n\tEnter a correct Choice");/*printing formatted output*/
								}
								break;

							case 2 :

								printf("\n\t****CFSS DEREGISTRATION PAGE*******");/*printing formatted output*/
								if(regFlag==1)
								{
									printf("\n\tDeregistered Successfully");/*printing formatted output*/
									break;
								}
								else
								{
									printf("\n\tYou are not registred");/*printing formatted output*/
								}
								break;





							case 3:
								//int PhoneNo;
								printf("Enter the number You want to make a call: ");/*printing formatted output*/
								scanf("%d",&PhoneNo);/*reads input*/


							case 4 :
								exit(EXIT_SUCCESS);
							default :
								printf("\n\tPlease Enter a Correct Choice ");/*printing formatted output*/
						}

					default:
						printf("\n\tEnter a Correct Choice");/*printing formatted output*/
				}
				/*if(signIn(headld) == 0){
					printf("\n\tUser/password does not match db\n");

				}
				else{
					printf("\n\tLogged In\n");
				}
				sleep(2)
				break;

			case 3:
				dispPD(headpd);
				sleep(2);
				break;

			case 4:
				dispLD(headld);
				sleep(2);
				break;*/

			case 3:
				writePD(headpd);/*function calling*/
				writeLD(headld);/*function calling*/
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("\n\tEnter a valid option\n");/*printing formatted output*/

		}

	}


	printf("\n\n");/*printing formatted output*/

	return 0;
}

