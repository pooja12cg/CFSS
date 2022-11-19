

/************************
 *  *  ***********************
 *   *  *******FILE NAME: CFSS_MAIN.C*********
 *    *  *************************/
#include <common.h>



int main()
{
	UD *ud=NULL;
	LD *ld=NULL;
	int ch =0;
	int opt=0;
	int option=0;
	while(1)
	{
		Welcome();
		char Main_menu[]="\n\tChoose you option\n\t 1.SingUp\n\t 2.SignIn\n\t 3.Exit\n\t Choice:";
		printf("%s", Main_menu);
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				ud=signUp(ud);
				dispUD(ud);
				writeUD(ud);
				readUD(ud);
			case 2:
				ld=Login(ld);
				printf("\n\t********************* LOGIN PAGE************************\n\n");
				/*if(strcmp(ud->_uname,ld->_uname)!=0)
				{
					printf("Invalid User Name ");
					ld=Login(ld);
				}*/
				char Sub_menu[]="\n\t Choose your Option \n\t 1. Opt for Call forwarding service \n\t 2. Deregister \n\t Choice : ";
				printf("%s", Sub_menu);
				scanf("%d",&opt);

				switch(opt)
				{
					case 1:
						printf("\n\t Call forwarding services are available\n\n");
						printf("\n\t Which type of call forwarding service you want?\n");
						printf("\n\t Press 1: If you want unconditional type \n\t Press 2: If you want for no reply service \n\t Press 3: If you want service for Busy");
						printf("\n\tEnter your choice:");
						scanf("%d",&option);
						switch(option)
						{		
							case 1:
								printf("\n\tUnconditional Call Forwarding \n ");
								break;
							case 2:
								printf("\n\tCall is forwaded as No Reply\n ");
								break;
							case 3:
								printf("\n\tCall is forwaded as Busy\n ");
								break;
							default:
								printf("\n\tEnter a correct choice\n ");
						}

						break;


					/*case 2:*/

					default:
						printf("\n\tEnter a correct choice\n ");
						

				}



			case 3:
				exit(EXIT_SUCCESS);
			default:
				printf("\n\t Enter a correct choice among 1,2,3\n");
		}	
	}
	printf("\n\n");
	return 0;
}
