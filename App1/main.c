#include <common.h>
#include <configMenu.h>

int main()
{
	PD *pd = NULL;
	PD *headpd = NULL;
	LD *ld = NULL;
	LD *headld = NULL;
	CFSS *cfss = NULL;
	CFSS *headcfss= NULL;

	int login=0;
	int user=0;
	int ch1=0;
	int cfs=0;
	int ch = 0, _id=0;
	int regFlag=0;
	int cfsNumber=0;
	headpd = loadPD(pd);
	/*if(headpd == NULL)
	{
		//headpd = (PD *)malloc(sizeof(PD));
		//headpd->next = NULL;
		
		printf("\n\tNULLPD\n");
	}*/
	pd = headpd;
	headcfss = loadCFSS(cfss);
	cfss = headcfss;
	
	headld = loadLD(ld);
	/*if(headld == NULL)
	{
		//headld = (LD *)malloc(sizeof(LD));
		//headld->next = NULL;
		printf("\n\tNULLLD\n");
	}*/
	ld = headld;
	int flag;
	int act;

	while(1){

		system("clear");
		printf("%s", WelCome);
		printf("%s", MainMenu);
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				headpd = signUp(headpd,&_id);
				headld = signInDetails(headld, _id);
				//dispPD(headpd);
				//dispLD(headld);
				// writePD(headpd);
				// writeLD(headld);
				//headpd = pd;
				//headld = ld;
				printf("\n\tSuccessfully Registered\n");
				sleep(2);
				break;

			case 2:
				//readPD(headpd);

				printf("\n\t******************LOGIN PAGE ****************");
				printf("\n\nPress \n\t1.Login as Admin \n\t2.Login as User \n\tChoose :");
				scanf("%d",&login);
				switch (login)
				{
					case 1:
						//AdminLogin();
						break;
					case 2:
						if(signIn(headld) == 0)
						{
							printf("\n\tUser/password does not match db\n");
						}
						else
						{

							printf("\n\tSUCCESSFULLY LOGGED IN\n");
							int regFlag=1;
						}

						printf("\n\tPress \n\t1.Register for CFSS \n\t2.Unregister for CFSS \n\t3.Make	a call \n\t4.Exit ");
						printf("\n\tEnter your Choice : ");
						scanf("%d",&user);
						int PhoneNo;
						switch(user)
						{
							case 1 :
								printf("\n\t************CFSS REGISTRATION PAGE***********");
								printf("\n\tPress \n\t1.Activate Call Forwarding");
								printf("\n\t2.Deactivate Call Forwarding ");
								printf("\n\t3.Return to previous menu");
								printf("\n\tEnter your Choice : ");
								scanf("%d",&ch1);
								switch(ch1)
								{
									case 1 :
										printf("\n\tCALL FORWARDING ACTIVATION PAGE");
										cfsActivation(headcfss);
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
										//printf("\n\t3.Return to deactive menu");
										cfsDeactivation(headcfss);
										break;
									case 3 :
										printf("\n\tReturning to previous menu");
										break;

									default :
										printf("\n\tEnter a correct Choice");
								}
								break;

							case 2 :

								printf("\n\t****CFSS DEREGISTRATION PAGE*******");
								if(regFlag==1)
								{
									printf("\n\tDeregistered Successfully");
									break;
								}
								else
								{
									printf("\n\tYou are not registred");
								}
								break;





							case 3:
								//int PhoneNo;
								printf("Enter the number You want to make a call: ");
								scanf("%d",&PhoneNo);

							case 4 :
								exit(EXIT_SUCCESS);
							default :
								printf("\n\tPlease Enter a Correct Choice ");
						}

					default:
						printf("\n\tEnter a Correct Choice");
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
				writePD(headpd);
				writeLD(headld);
				exit(EXIT_SUCCESS);
			default:
				printf("\n\tEnter the correct choice\n");

		}

	}


	printf("\n\n");

	return 0;
}

