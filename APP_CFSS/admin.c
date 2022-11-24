#include<common.h>


void AdminLogin()
{
	char aName[20];
	char Apwd[20];
	printf("\n\tEnter User Name :");
	scanf("%[^\n]s",aName);
	printf("\n\tPassword :");
	scanf("%s",Apwd);
	if((strcmp(aName,"Admin")==0)&&(strcmp(Apwd,"Admin123")==0))
	{
		printf("Login Successful");
	}
	else
	{
		printf("\n\tEnter valid UsernName/Password");
	}


}
int UpdateDetails(UPD *head)
{
	UPD _upd;
	int flag =0;
	printf("\n\tEnter you id to update : ");
	getchar();
	scanf("%d",&_upd._id);
	while(head !=NULL)
	{
		if(head->_id==_upd._id)
		{
			printf("\n\tEnter Name to Update :");
			getchar();
			scanf("%[^\n]s",_upd._uName);
			strcpy(head->_uName,_upd._uName);
			writeUPD(head);
			break;
		}
		head = head->next;
	}
	if(flag == 1)
		return 1;
	return 0;

}



