/*************************************************************************
* *
* *  FILE NAME    : main1.c
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
int main()
{
	UD *ud=NULL;/*pointer ud pointing to structure userDetails initialized to NULL value*/
	UD *headud = NULL;/*pointer headud pointing to structure userDetails initialized to NULL value*/
	LD *ld=NULL;/*pointer ld pointing to structure loginDetails initialized to NULL value*/
	LD *headld = NULL;/*pointer headld pointing to structure loginDetails initialized to NULL value*/

	int _uphnno =0;/*holds phone number */
	int act =0;/*active=1 when user is active ,active=0 when user is inactive */

	int ch =0;/*holds the choice to choose*/
	int opt=0;/*holds the option to choose*/
	headud = loadUD(ud);/*pointer headud heading towards loadUD function*/
	ud =headud;/*base address and head of list is pointing to same in userDetails structure*/
	headld = loadLD(ld);/*pointer headud heading towards loadLD function*/
	ld = headld;/*base address and head of list is pointing to same in loginDetails structure*/

	while(1)
	{

		system("clear");
		Welcome();/*function calling*/
		printf("\n\tMAIN MENU***********\n");/*printing formatted output*/
		char Main_menu[]="\n\tChoose you option\n\n\t 1.New User Registration\n\t 2.Login\n\t 3.Display\n\t n\t 5.Exit \n\t Choice:";
		printf("%s", Main_menu);/*displaying formatted output*/
		scanf("%d",&ch);/*reads input*/
		//ch = dispMainMenu();

		switch(ch)
		{
			case 1:
				headud = signUp(headud, &_uphnno);/*pointer headud heading towards signUp function*/
				headld = signInDetails(headld, _uphnno);/*pointer headud heading towards signInDetails function*/
				printf("\n\t SUCCESSFULLY REGISTERED\n");/*printing formatted output*/
				dispUD(headud);/*function calling*/
				sleep(2);/*sleep is implemented to display after 2 seconds*/
				break;

				/*ud=signUp(ud);
				dispUD(ud);
				writeUD(ud);
				readUD(ud);*/
			case 2:
				if(Login(headld) == 0)
				{
					printf("\n\t User/Password does not match with database\n");/*printing formatted output*/
					break;
				}
				else
				{
					printf("\n\tLOGIN SUCCESSFULL\n");/*printing formatted output*/
				}
		
				/*ld=Login(ld);
				printf("\n\t********************* LOGIN SUCCESSFULL************************\n\n");
				if(strcmp(ud->_uname,ld->_uname)!=0)
				{
					printf("Invalid User Name ");
					ld=Login(ld);*/
				
				char Sub_menu[]="\n\t Choose your Option \n\n\t 1. Opt for Call forwarding service \n\t 2. Deregister \n\n\t Choice : ";
				printf("%s", Sub_menu);/*printing formatted output*/
				scanf("%d",&opt);/*reads input*/
				//opt = dispSubMenu();
				int flag =0;
				switch(opt)
				{
					case 1:
						printf("\n\t Call forwarding services are available");/*printing formatted output*/
						printf("\n\t Do you want to activate call forwarding service(0/1) :");
						scanf("%d",&flag);
						if(flag==0)
						{
							printf("\n\nUser is not Active");
							break;
						}
						else
						{
							if(flag==1)
							{
								printf("\n\t Which type of call forwarding service you want?\n");/*printing formatted output*/
								printf("\n\t Press 1: If you want unconditional type \n\t"); 
								printf("\n\t Press 2: If you want for no reply service \n\t");
								printf("\n\t Press 3: If you want service for Busy");/*printing formatted output*/
								printf("\n\tEnter your choice:");/*printing formatted output*/
								scanf("%d",&opt);/*reads input*/
								switch(opt)
								{
									case 1:
										printf("\n\tUnconditional Call Forwarding \n ");/*printing formatted output*/
										break;
									case 2:
										printf("\n\tCall is forwaded as No Reply\n ");/*printing formatted output*/
										break;
									case 3:
										printf("\n\tCall is forwaded as Busy\n ");/*printing formatted output*/
										break;
									default:
										printf("\n\tEnter a correct choice\n ");/*printing formatted output*/
								}
							}
							else
							{
								printf("\n\tPlease enter a valid input ");
							}
						}

						//break;


					case 2:
						//printf("\n\tDo you want to stay active(0/1) :");/*printing formatted output*/
						//scanf("%d",&act);/*read input*/
						if(flag==1)/*condition checks if the user is inactive*/
						{
							printf("\n\tDeactivation Successful\n");/*printing formatted output*/
							break;

						}
						else/*condition checks if the user is active*/
						{
							printf("\n\tActivate call forwarding first\n");/*printing formatted output*/
							break;

						}

					default:
						printf("\n\tEnter a correct choice\n ");/*printing formatted output*/
						

				}
				sleep(2);

				break;
			case 3:
				dispUD(headud);/*function calling*/
				dispLD(headld);/*function calling*/
				sleep(2);
				break;
			case 4:
				if(Login(headld) == 0)
				{
					printf("\n\t User does not match with database\n");/*printing formatted output*/
					break;
				}
				else
				{
					printf("\n\tPress 1 to Update \n\tPress 2 to Add \n\tPress 3 to Delete \n");/*printing formatted output*/
					printf("\n\tEnter your Choice : ");/*printing formatted output*/
					scanf("%d",&opt);/*reads input*/
					switch(opt)
					{
						case 1:
							printf("\n\tUpdated \n ");/*printing formatted output*/
							break;
						case 2:
							printf("\n\tUser Added\n ");/*printing formatted output*/
							break;
						case 3:
							printf("\n\tUser Deleted\n ");/*printing formatted output*/
							break;
						default:
							printf("\n\tEnter a correct choice\n ");/*printing formatted output*/
					}

				}



			case 5:
				//write(headud);
				//write(headld);
				printf("\n\tThankyou for visiting our Call Forwarding System Simulator\n");/*printing formatted output*/
				exit(EXIT_SUCCESS);/*printing formatted output*/
			default:
				printf("\n\t Enter a correct choice \n");/*printing formatted output*/
		}	
	}
	printf("\n\n");/*printing two new lines*/
	return 0;/*returns an integer datatype*/
}
