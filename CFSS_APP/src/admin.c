/*****************************************************************
 * FILE_NAME    :    main.c
 * DESCRIPTION  :    implementation of the binary search string
 * RETURN_TYPE  :    returns success or failure
 ***************************************************************/

 /******************************************************************
                	HEADER FILE
 ***************************************************************/
#include<common.h>



/*******************************************************************
 * FUNCTION_NAME  :   main
 * DESCRIPTION    :   It takes the strings from user and search
 *                        
 * RETURN_TYPE    :   returns success or failure
 ************************************************************/
void AdminLogin()
{
	char aName[20];
	char aPwd[20];
	printf("\n\tEnter User Name :");
	scanf("%[^\n]s",aName);

	printf("\n\tPassword :");
	scanf("%s",aPwd);

	if((strcmp(aName,"Admin")==0)&&(strcmp(aPwd,"Admin123")==0))
	{
		printf("\n\tLogin Successful");
	}
	else
	{
		printf("\n\tEnter Valid UserName");
	}


}
/*******************************************************************
 * FUNCTION_NAME  :   main
 * DESCRIPTION    :   It takes the strings from user and search
 *                        
 * RETURN_TYPE    :   returns success or failure
 ************************************************************/
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
			printf("\n\tName has been updated");
			writeUPD(head);
		}
		head = head->next;
	}
	if(flag == 1)
		return 1;
	return 0;

}
/*
int DeleteUser(UPD *head)
{
	UPD _upd;
	int flag =0;
	//int firstNode = 0;
	struct UPD *temp, *current;
	printf("\n\nEnter your id to delete :");
	getchar();
	scanf("%d",&_upd._id);
	//temp=head;
	while(head!=NULL)
	{
		if(head->_id==_upd._id)
		{
			//temp=head;
			//head=head->next;
			free(temp);
			printf("\n\tThe user has been Deleted");
			writeUPD(head);
		}
		head=head->next;


	}
	if(flag == 1)
		return 1;
	return 0;

}
*/

