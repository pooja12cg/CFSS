
/*************************************************************************
* *
* *  FILE NAME    : common.c
* *
* *  DESCRIPTION  : This program demonstrated how all function definitions are implemented
* *		  
* *
* *    DATE        NAME    REFERENCE          REASON
* *
* * 21-11-2022   Group04     New          Initial Creation.
* *
* *  Copyright 2010, Aricent Technologies (Holdings) Ltd
* *
* * **************************************************************************/

/*************************************************************************
* *				HEADER FILES
* *************************************************************************/
#include <common.h>

/******************************************************************************
* *
* *       Function Name   : Welcome
* *       Description     : It prints formatted output
* *       Returns         : Nothing 
* *
* *******************************************************************************/
void Welcome()
{
	/*reads a single character from the standard input stream stdin*/
	printf("\n\t********************************************************************************************************************\n");
	printf("\n\t*************************************************WELCOME TO CFSS****************************************************\n");
	printf("\n\t********************************************************************************************************************\n");
}

/******************************************************************************
* *
* *       Function Name   : signUp
* *       Description     : It demonstrates user registration with application  to request for call forwarding service
* *       Returns         : Success or Failure
* *
* *******************************************************************************/
UD* signUp(UD *ud, int *id)
{
	UD *newNode =NULL;
	UD *head = NULL;
	head = ud;

	newNode = (UD *)malloc(sizeof(UD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		//no records
		head = newNode;
		ud = newNode;
		printf("\n");
	}
	else
	{
		//records are present
		while(ud->next != NULL)
			ud = ud->next;

		ud->next = newNode;
		ud = ud->next;
		printf("\n");
	}

	//pd = newNode;


	
	printf("\n\tEnter User Id: ");/*printing formatted output*/
	scanf("%d",&newNode->id);/*reads input*/
	printf("\n\tEnter User Phone Number: ");/*printing formatted output*/
	scanf("%d",&newNode->uphnno);/*reads input*/
	printf("\n\tEnter Name: ");/*printing formatted output*/
	getchar();/*reads a single character from the standard input stream stdin*/
	
	// fgets(pd->_name, 256,stdin);
	// removeTrailing(pd->_name);
	
	scanf("%[^\n]s",newNode->uname);/*reads input*/
	/*printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);*/
	*id = newNode->id;
	
	return head;
}


/******************************************************************************
 * *
 * *       Function Name   : signInDetails
 * *       Description     : Demonstrates user login after registration
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/

LD* signInDetails(LD *ld, int id)
{
	LD *newNode =NULL;
	LD *head = NULL;
	head = ld;

	newNode = (LD *)malloc(sizeof(LD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		/*no records*/
		head = newNode;
		ld = newNode;
	}
	else
	{
		/*records are present*/
		while(ld->next != NULL)
			ld = ld->next;

		ld->next = newNode;
		ld = ld->next;
	}

	

	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->id);
	//newNode->id = id;
	printf("\n\tEnter User Name: ");/*printing formatted output*/
	getchar();/*reads a single character from the standard input stream stdin*/
	
	/* fgets(pd->_name, 256,stdin);*/
	/* removeTrailing(pd->_name);*/
	
	scanf("%[^\n]s",newNode->uname);/*reads input*/
	printf("\n\tEnter Password: ");/*printing formatted output*/
	getchar();/*reads a single character from the standard input stream stdin*/
	scanf("%s",newNode->passwd);/*reads input*/
	id = newNode->id;
	
	return head;
}
/******************************************************************************
 * *
 * *       Function Name   : dispUD
 * *       Description     : It displays User Details based on user registration
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
void dispUD(UD *ud)
{
	while(ud != NULL){

		
		printf("\n\tID: ");/*printing formatted output*/
		printf("%d",ud->id);/*display formatted output*/
		printf("\n\tPhone Number: ");/*printing formatted output*/
		printf("%d",ud->uphnno);/*display formatted output*/
		printf("\tName: ");/*printing formatted output*/
		printf("%s",ud->uname);/*display formatted output*/
		//printf("\tGender (M/F/O): ");
		//printf("%c",pd->_gender);
		ud = ud->next;
	}
}

/******************************************************************************
 * *
 * *       Function Name   : dispLD
 * *       Description     : It displays login details based on user login information
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
void dispLD(LD *ld)
{
	while(ld != NULL){
		printf("\n\tID: ");
		printf("%d",ld->id);
		printf("\tUser Name: ");
		printf("%s",ld->uname);
		printf("\tPassword: ");
		printf("%s",ld->passwd);
		ld = ld->next;
	}
}
/******************************************************************************
 * *
 * *       Function Name   : writeUD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
int writeUD(UD *ud)
{
	FILE *fp = NULL;

	fp = fopen("UD.data","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);

	if(ud == NULL)
		printf("\n\t NULL Write ud");/*printing formatted output*/
	while(ud != NULL){
		fprintf(fp,"%d, %d, %s\n",ud->id,ud->uphnno,ud->uname);
		ud = ud->next;
	}

	fclose(fp);
	return 0;

	
}
/******************************************************************************
 * *
 * *       Function Name   : writeLD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
int writeLD(LD *ld)
{
	FILE *fp = NULL;

	fp = fopen("LD.data","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(ld == NULL)
		printf("\n\t NULL Write pd");/*printing formatted output*/
	while(ld != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%d, %s, %s\n",ld->id,ld->uname,ld->passwd);
		ld = ld->next;
	}

	fclose(fp);
	return 0;

	
}

/******************************************************************************
 * *
 * *       Function Name   : loadUD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
UD* loadUD()
{
	FILE *fp = NULL;
	UD *newNode = NULL;
	UD *head = NULL;
	UD *ud; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("UD.data","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	// printf("\n\tFile Size: %d\n",_fSize);

	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		// head = newNode;
		while(fgets(tmpBuff, 256, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (UD *)malloc(sizeof(UD));
				newNode->next = NULL;
				head = newNode;
				ud = newNode;
				tokenizeUD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (UD *)malloc(sizeof(UD));
				newNode->next = NULL;
				ud->next = newNode;
				tokenizeUD(newNode, tmpBuff);
				ud = ud->next;	
			}
			

		}

	}

	fclose(fp);
	// printf("\n\tHead : %u\nlast node: %u\n", head, pd);
	return head;

}

/******************************************************************************
 * *
 * *       Function Name   : loadLD
 * *       Description     : Demonstration of Filehandling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
LD* loadLD()
{
	FILE *fp = NULL;
	LD *newNode = NULL;
	LD *head = NULL;
	LD *ld; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("LD.data","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	// printf("\n\tFile Size: %d\n",_fSize);

	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 1024);
		// head = newNode;
		while(fgets(tmpBuff, 1024, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (LD *)malloc(sizeof(LD));
				newNode->next = NULL;
				head = newNode;
				ld = newNode;
				tokenizeLD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (LD *)malloc(sizeof(LD));
				newNode->next = NULL;
				ld->next = newNode;
				tokenizeLD(newNode, tmpBuff);
				ld = ld->next;	
			}
			

		}

	}

	fclose(fp);
	// printf("\n\tHead : %u\nlast node: %u\n", head, pd);
	return head;

}

/******************************************************************************
 * *
 * *       Function Name   : readPD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/

int readUD(UD *ud)

{
	FILE *fp = NULL;
	char tmpBuff[256] = {'\0', };
	UD tmpud;

	fp = fopen("UD.data","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_SET);
	memset(tmpBuff,'\0', 256);
	while(fgets(tmpBuff, 256, fp)){
	
		// printf("\n\tRead Buff: %s", tmpBuff);
		tokenizeUD(&tmpud, tmpBuff);
		memset(tmpBuff,'\0', 256);
	}

	fclose(fp);
	return -1;


}
/******************************************************************************
 * *
 * *       Function Name   : tokenizeUD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
int readLD(LD *ld)
{
	FILE *fp = NULL;
	char tmpBuff[256] = {'\0', };
	LD tmpld;

	fp = fopen("LD.data","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_SET);
	memset(tmpBuff,'\0', 256);
	while(fgets(tmpBuff, 256, fp)){
	
		// printf("\n\tRead Buff: %s", tmpBuff);
		tokenizeLD(&tmpld, tmpBuff);
		memset(tmpBuff,'\0', 256);
	}

	fclose(fp);
	return -1;
}


void tokenizeUD(UD *ud, char *tmpBuff)
{
	char *tokens;
	/*int i;
	int count;
	char *tmpBuff1;*/

	tokens = strtok(tmpBuff, ",");
	ud->id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,ud->uname);
	
	tokens = strtok(NULL, ",");
	removeLeading(tokens,tokens);
	removeTrailing(tokens);
	//ud->_gender = tokens[0];

	//dispPD(pd);
}

/******************************************************************************
 * *
 * *       Function Name   : tokenizeLD
 * *       Description     : Demonstration of File Handling Operations
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
void tokenizeLD(LD *ld, char *tmpBuff)
{
	char *tokens;
	/*int i, count;
	char *tmpBuff1;*/

	tokens = strtok(tmpBuff, ",");
	ld->id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,ld->uname);
	
	tokens = strtok(NULL, ",");
	removeLeading(tokens,ld->passwd);
	removeTrailing(ld->passwd);
	//dispPD(pd);
}
/******************************************************************************
 * *
 * *       Function Name   : removeLeading
 * *       Description     : 
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';
 
    // Print the string with no whitespaces
    //printf("%s", str1);
}
/******************************************************************************
 * *
 * *       Function Name   : removeTrailing
 * *       Description     : 
 * *       Returns         : Success or Failure
 * *
 * *******************************************************************************/
void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
    {
    	str[strlen(str)-1] = '\0';
    }

}
/******************************************************************************
* *
* *       Function Name   : Login
* *       Description     : Application shall allow users to register or unregister for call forwarding service initially before enabling or disabling the				   service.  
* *       Returns         : Success or Failure
* *
* *******************************************************************************/
int Login(LD *head)
{
	LD _ld;/*variable declared for the loginDetails structure*/
	int flag = 0;/*initially flag is low*/
	//char adName="Admin";
	//char adPasswd="Admin123";
	
	printf("\n\tEnter User Name: ");/*printing formatted output*/
	getchar();
	scanf("%[^\n]",_ld.uname);

	//scanf("%s", _ld.uname);
	printf("\n\tEnter Password: ");/*printing formatted output*/
	scanf("%s",_ld.passwd);
	/*if((strcmp(head->uname,adName)==0)&&(strcmp(head->passwd,adPasswd)==0))
	{
		Admin_Login();

	}
	else
	{*/
	while(head != NULL)
	{
		if((strcmp(head->uname, _ld.uname)==0)&&(strcmp(head->passwd, _ld.passwd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}
	if(flag == 1)
		return 1;
	return 0;
}
int Admin_Login()
{
	int ch=0;
	printf("\n\tPress \n\t1. Add User by Id \n\t2. Update user by Id \n\t3. Delete User by Id \n\t4. Exit \n\tChoice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n\tAdded User");
		case 2:
			printf("\n\tUpdated User");
		case 3:
			printf("\n\tDeleted User");
		case 4:
			exit(EXIT_SUCCESS);
		default:
			printf("\n\tEnter the Correct Choice");
	}
	
}


