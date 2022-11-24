/****************************************************************************************************
 * FILE NAME    : common.c
 *
 * DESCRIPTION  : Program to to extract Customer and cab driver details and perform login operation
 *                
 *
 * Revision History:
 *
 * DATE         NAME                REFERENCE          REASON
 ********************************************************************************************************
 * 24-11-22    GROUP 04                New           Changes Committed
 *********************************************************************************************************
 * Copyright 2022, Altran Group All Rights Reserved
 *
 *******************************************************************************************************/

/***************************************************************************
*                           HEADER FILES
*****************************************************************************/

#include <common.h>

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
UPD* signUp(UPD *upd,int *_id)
{
	UPD *newNode =NULL;
	UPD *head = NULL;
	
	head = upd;
	
	
	newNode = (UPD *)malloc(sizeof(UPD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		//no records
		head = newNode;
		upd = newNode;
	}
	else
	{
		//records are present
		while(upd->next != NULL)
			upd = upd->next;

		upd->next = newNode;
		upd = upd->next;
	}

	//pd = newNode;

	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->_id);

	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_uName);
	printf("\n\tEnter Phone Number: ");
	scanf("%d",&newNode->_phNo);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	*_id = newNode->_id;
	
	return head;
}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
CFSS *initCFSS(CFSS *head, int id)
{
	CFSS *tmpHead = head;
	CFSS *newNode = NULL;

	newNode = (CFSS *)malloc(sizeof(CFSS));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		tmpHead = newNode;
	}
	else
	{
		while(tmpHead->next != NULL)
			tmpHead = tmpHead->next;

		tmpHead->next = newNode;
		tmpHead = tmpHead->next;
	}

	newNode->cfsNumber=-1; 
	newNode->cfsActive=0;
	strcpy(newNode->status,"A");
	newNode->regFlag=0;
    	newNode->_id=id;

    return head;
}


/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
LD* signInDetails(LD *ld, int _id)
{
	LD *newNode =NULL;
	LD *head = NULL;
	head = ld;

	newNode = (LD *)malloc(sizeof(LD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		//no records
		head = newNode;
		ld = newNode;
	}
	else
	{
		//records are present
		while(ld->next != NULL)
			ld = ld->next;
		ld->next = newNode;
		ld = ld->next;
	}

	

	// printf("\n\tEnter ID: ");
	// scanf("%d",&newNode->_id);
	newNode->_id = _id;
	printf("\n\tEnter User Name: ");
	getchar();
	
	// fgets(pd->_name, 256,stdin);
	// removeTrailing(pd->_name);
	
	scanf("%s",newNode->_uName);
	printf("\n\tEnter Password: ");
	getchar();
	scanf("%s",newNode->_passwd);
	
	
	return head;
}
/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int signInUser(LD *head, int *refID)
{
	LD _ld;
	int flag = 0;
	*refID = -1;
	printf("\n\tEnter User Name: ");
	scanf("%s", _ld._uName);
	printf("\n\tEnter Password: ");
	scanf("%s",_ld._passwd);
	while(head != NULL)
	{
		if((strcmp(head->_uName, _ld._uName)==0)&&(strcmp(head->_passwd, _ld._passwd)==0))
		{
			*refID = head->_id;
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}


/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int writeUPD(UPD *upd)
{
	FILE *fp = NULL;

	fp = fopen("./data/PD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	//fseek(fp, 0L, SEEK_END);
	if(upd == NULL)
		printf("\n\t NULL Write pd");
	while(upd != NULL){
		fprintf(fp,"%d, %d, %s, %c, %d\n",upd->_id,upd->_phNo,upd->_uName,upd->_gender,upd->regFlag);
		//fprintf(stdout,"%d, %s, %c\n",pd->_id,pd->_name,pd->_gender);
		upd = upd->next;
	}

	fclose(fp);
	return 0;

	
}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int writeLD(LD *ld)
{
	FILE *fp = NULL;

	fp = fopen("./data/LD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	//fseek(fp, 0L, SEEK_END);
	if(ld == NULL)
		printf("\n\t NULL Write pd");
	while(ld != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%d, %s, %s\n",ld->_id,ld->_uName,ld->_passwd);
		ld = ld->next;
	}

	fclose(fp);
	return 0;

	
}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int writeCFSS(CFSS *cfss)
{
	FILE *fp = NULL;

	fp = fopen("./data/CFSS.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	//fseek(fp, 0L, SEEK_END);
	if(cfss == NULL)
		printf("\n\t NULL Write CFSS");
	while(cfss != NULL){
		/*printf("\n%d = cfss->_id",cfss->_id);*/
		fprintf(fp,"%d, %d, %d, %d, %s\n",cfss->_id,cfss->regFlag,cfss->cfsNumber,cfss->cfsActive,cfss->status);
		cfss = cfss->next;
	}

	fclose(fp);
	return 0;

	
}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

UPD* loadUPD()
{
	FILE *fp = NULL;
	UPD *newNode = NULL;
	UPD *head = NULL;
	UPD *upd; 
	int _fSize = 0;
	char tmpBuff[512] = {'\0', };
	
	fp = fopen("./data/PD.dat","r");
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
		memset(tmpBuff,'\0', 512);
		// head = newNode;
		while(fgets(tmpBuff, 512, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (UPD *)malloc(sizeof(UPD));
				newNode->next = NULL;
				head = newNode;
				upd = newNode;
				tokenizeUPD(newNode, tmpBuff);
			}
			else /* rest of the records */
			{
				newNode = (UPD *)malloc(sizeof(UPD));
				newNode->next = NULL;
				upd->next = newNode;
				tokenizeUPD(newNode, tmpBuff);
				upd = upd->next;
                                
			}
			memset(tmpBuff,'\0', 512);

		}

	}

	fclose(fp);
	return head;

}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

LD* loadLD()
{
	FILE *fp = NULL;
	LD *newNode = NULL;
	LD *head = NULL;
	LD *ld; 
	int _fSize = 0;
	char tmpBuff[512] = {'\0', };
	
	fp = fopen("./data/LD.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);

	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 512);
		while(fgets(tmpBuff, 512, fp)){
			
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
			memset(tmpBuff,'\0', 512);

		}

	}

	fclose(fp);
	return head;

}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
CFSS* loadCFSS()
{
	FILE *fp = NULL;
	CFSS *newNode = NULL;
	CFSS *head = NULL;
	CFSS *cfss; 
	int _fSize = 0;
	char tmpBuff[512] = {'\0', };
	
	fp = fopen("./data/CFSS.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 512);
		while(fgets(tmpBuff, 512, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CFSS *)malloc(sizeof(CFSS));
				newNode->next = NULL;
				head = newNode;
				cfss = newNode;
				tokenizeCFSS(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CFSS *)malloc(sizeof(CFSS));
				newNode->next = NULL;
				cfss->next = newNode;
				tokenizeCFSS(newNode, tmpBuff);
				cfss = cfss->next;	
			}
			memset(tmpBuff,'\0', 512);
			
		}

	}

	fclose(fp);
	return head;

}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int readCFSS(CFSS *cfss)
{
	FILE *fp = NULL;
	char tmpBuff[512] = {'\0', };
	CFSS tmpcfs;

	fp = fopen("./data/CFSS.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_SET);
	memset(tmpBuff,'\0', 512);
	while(fgets(tmpBuff, 512, fp)){
	
		// printf("\n\tRead Buff: %s", tmpBuff);
		tokenizeCFSS(&tmpcfs, tmpBuff);
		memset(tmpBuff,'\0', 512);
	}

	fclose(fp);
	return 0;

}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int readUPD(UPD *upd)
{
	FILE *fp = NULL;
	char tmpBuff[512] = {'\0', };
	UPD tmpupd;

	fp = fopen("./data/PD.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_SET);
	memset(tmpBuff,'\0', 512);
	while(fgets(tmpBuff, 512, fp))
	{
		tokenizeUPD(&tmpupd, tmpBuff);
		memset(tmpBuff,'\0', 512);
	}

	fclose(fp);
	return 0;


}



/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/

int tokenizeCFSS(CFSS *cfss, char *tmpBuff)
{
	char *tokens;

	if(tmpBuff!=NULL)
	{
	tokens = strtok(tmpBuff, ",");
	cfss->_id = atoi(tokens);
 	
	tokens=strtok(NULL , ",");
	cfss->regFlag = atoi(tokens);

 	tokens=strtok(NULL , ",");
	cfss->cfsNumber=atoi(tokens);


 	tokens=strtok(NULL , ",");
	cfss->cfsActive = atoi(tokens);
	
 
	tokens = strtok(NULL, ",");
	cfss->regFlag = atoi(tokens);

	tokens = strtok(NULL, ",");
	cfss->cfsNumber = atoi(tokens);

	tokens = strtok(NULL, ",");
	cfss->cfsActive = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,cfss->status);
        cfss->status[strlen(cfss->status)-1] = '\0';
	}
	return 0;
}
/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int tokenizeUPD(UPD *upd, char *tmpBuff)
{
	char *tokens;
	
	if(tmpBuff!=NULL)
	{
	tokens = strtok(tmpBuff, ",");
	upd->_id = atoi(tokens);
	
	tokens = strtok(NULL, ",");
	upd->_phNo = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,upd->_uName);
	


	tokens = strtok(NULL, ",");
	removeLeading(tokens,tokens);
	upd->_gender=tokens[0];

	tokens = strtok(NULL, ",");
	upd->regFlag = atoi(tokens);
	}

	return 0;
}


/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
int tokenizeLD(LD *ld, char *tmpBuff)
{
	char *tokens;

	if(tmpBuff!=NULL)
	{
	tokens = strtok(tmpBuff, ",");
	ld->_id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,ld->_uName);
	
	tokens = strtok(NULL, ",");
	removeLeading(tokens,ld->_passwd);
        ld->_passwd[strlen(ld->_passwd)-1] = '\0';

	}
	return 0;
}

/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    str1[k] = '\0';
 
}
/*******************************************************************
 * FUNCTION NAME: get_string
 * DESCRIPTION  : gets the a line from standerd input to the i th
 *        	       element of array
 * ARGUMENTD    :   Array of strings to be stored in 
 * RETURNS      :  returns SUCCESS or FAILURE
 *******************************************************************/
void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
	{
		str[strlen(str)-1] = '\0';
	}
	
}

