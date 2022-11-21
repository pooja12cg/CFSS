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

<<<<<<< HEAD
	int ch =0;
	int opt=0;
=======
	int ch =0;/*holds the choice variable*/
	int opt=0;/*holds the option to be selected*/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6
	headud = loadUD(ud);
	ud =headud;/*base address and head of list is pointing to same in userDetails structure*/
	headld = loadLD(ld);
	ld = headld;/*base address and head of list is pointing to same in loginDetails structure*/

	while(1)
	{
<<<<<<< HEAD

		system("clear");
		Welcome();
		printf("\n\tMAIN MENU***********\n");
		char Main_menu[]="\n\tChoose you option\n\n\t 1.New User Registration\n\t 2.Login\n\t 3.Display \n\t 4.Exit\n\t Choice:";
		printf("%s", Main_menu);
		scanf("%d",&ch);
=======
		Welcome();/*Welcome function calling*/
		char Main_menu[]="\n\tChoose you option\n\t 1.SingUp\n\t 2.SignIn\n\t 3.Exit\n\t Choice:";
		printf("%s", Main_menu);/*printing in a formatted output*/
		scanf("%d",&ch);/*Reading the input*/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6
		//ch = dispMainMenu();

		switch(ch)
		{
			case 1:
<<<<<<< HEAD
				headud = signUp(headud, &_uphnno);
				headld = signInDetails(headld, _uphnno);
				printf("\n\t SUCCESSFULLY REGISTERED\n");
				dispUD(headud);
				sleep(2);
=======
				headud = signUp(headud, &_uphnno);/*pointing the pointer to signUp*/
				headld = signInDetails(headld, &_uphnno);/*pointing the pointer to signInDetails*/ 
				printf("\n\t SUCCESSFULLY REGISTERED\n");/*printing formatted output*/
				dispUD(headud);/*function calling by passing a pointer*/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6
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
				
<<<<<<< HEAD
				char Sub_menu[]="\n\t Choose your Option \n\n\t 1. Opt for Call forwarding service \n\t 2. Deregister \n\n\t Choice : ";
				printf("%s", Sub_menu);
				scanf("%d",&opt);
=======
				char Sub_menu[]="\n\t Choose your Option \n\t 1. Opt for Call forwarding service \n\t 2. Deregister \n\t Choice : ";
				printf("%s", Sub_menu);/*printing formatted output*/
				scanf("%d",&opt);/*reads input*/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6
				//opt = dispSubMenu();
				switch(opt)
				{
					case 1:
						printf("\n\t Call forwarding services are available");/*printing formatted output*/
						printf("\n\t Which type of call forwarding service you want?\n");/*printing formatted output*/
						printf("\n\t Press 1: If you want unconditional type \n\t Press 2: If you want for no reply service \n\t Press 3: If you want service for Busy");/*printing formatted output*/
						printf("\n\tEnter your choice:");/*printing formatted output*/
						scanf("%d",&opt);/*reads input*/
						switch(opt)
						{		
							case 1:
								printf("\n\tUnconditional Call Forwarding \n "0);/*printing formatted output*/
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

						//break;


					case 2:
						printf("\n\tDo you want to stay active(0/1) :");/*printing formatted output*/
						scanf("%d",&act);/*read input*/
						if(act==0)/*condition checks if the user is inactive*/
						{
							printf("\n\tDeactivation Successful\n");/*printing formatted output*/
							break;

						}
						else/*condition checks if the user is active*/
						{
<<<<<<< HEAD
							printf("\n\tActive\n");
=======
							printf("\n\tActive\n");/*printing formatted output*/
							break;
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6

						}

					default:
						printf("\n\tEnter a correct choice\n ");/*printing formatted output*/
						

				}
				sleep(2);

				break;
			case 3:
				dispUD(headud);
				dispLD(headld);
				sleep(2);
				break;



<<<<<<< HEAD
			case 4:
				//write(headud);
				//write(headld);
				printf("\n\tThankyou for visiting our Call Forwarding System Simulator\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\n\t Enter a correct choice \n");
=======
			case 3:
				printf("\n\tThankyou for visiting our Call Forwarding System Simulator\n");/*printing formatted output*/
				exit(EXIT_SUCCESS);/*printing formatted output*/
			default:
				printf("\n\t Enter a correct choice among 1,2,3\n");/*printing formatted output*/
>>>>>>> c374c1ff3591cc90dbc5305a4b54a70e19f02cf6
		}	
	}
	printf("\n\n");/*printing two new lines*/
	return 0;/*returns an integer datatype*/
}
