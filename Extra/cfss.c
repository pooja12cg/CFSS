
/************************
 *  *  ***********************
 *   *  ****FILE NAME:cfss.c ***************
 *    *  *************************/
#include <common.h>



void Welcome()
{
	printf("\n\t===========================================WELCOME TO OUR CFSS PROJECT===============================================\n");
}
UD* signUp(UD *ud)
{
	ud=(UD *)malloc(sizeof(UD));
	printf("\n\tEnter your mobile number:");
	scanf("%d",&ud->_uphnno);
	/*phonevalidate(_uphnno);*/
	printf("\n\tEnter your name:");
	getchar();
	scanf("%[^\n]s",ud->_uname);
	/*fgets(ud->_uname,1024,stdin);
	ud->_uname[strlen(ud->_uname)-1]='\0';
	getchar();
	printf("\n\n");*/
	return ud;
}
/*int validate(UD *ud,int _uphnno)
{

}*/
void dispUD(UD *ud)
{
	printf("\n\tDisplaying all Details\n");
	printf("\n\tMobile number: ");
	printf("%d",ud->_uphnno);
	printf("\n\tName: ");
	printf("%s",ud->_uname);
}

LD* Login(LD *ld)
{
	ld=(LD *)malloc(sizeof(LD));
	printf("\n\tEnter your User Name:");
	getchar();
	scanf("%[^\n]s",ld->_uname);
	/*phonevalidate(_uphnno);*/
	printf("\n\tEnter your Password:");
	scanf("%d",&ld->_uphnno);
	/*pos = findUser(ud,NoOfUsers,_uphnno);
	if(pos==-1)
		printf("Invalid username or password");
	else
	{	printf("Logging in ");

	}
	fgets(ud->_uname,1024,stdin);
	ud->_uname[strlen(ud->_uname)-1]='\0';
	getchar();
	printf("\n\n");*/
	return ld;
}
//void findUser()
int writeUD(UD *ud)
{
	FILE *fp=NULL;

	fp=fopen("UD.dat","r");
	if(fp==NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp,0L,SEEK_END);
	fprintf(fp,"%d, %s\n",ud->_uphnno,ud->_uname);

	fclose(fp);
}
int readUD(UD *ud)
{
	FILE *fp=NULL;
	char tmpBuff[256]={'\0',};
	UD tmpud;

	fp=fopen("UD.dat","r");
	if(fp==NULL)
	{
		perror("\n\tfopen()");
		return -1;
	}
	fseek(fp,0L,SEEK_SET);
	memset(tmpBuff,'\0',256);
	while(fgets(tmpBuff,256,fp))
	{
		printf("\n\tRead Buff:%s",tmpBuff);
	}
	fclose(fp);

}
