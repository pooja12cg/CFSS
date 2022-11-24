#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

void main()
{
	char username[20];
	char password[20];
	printf("Enter the admin username: ");
	scanf("%[^\n]s",username);
	getchar();
	/*fgets(username,sizeof(username),stdin);
	username=(char *)malloc(100 * sizeof(char));*/
	printf("\nEnter the admin password: ");
	scanf("%[^\n]s",password);

	/*fgets(password,sizeof(password),stdin);*/
	/*password=(char *)malloc(100 * sizeof(char));*/
	if(strcmp(username, "Admin") == 0)
	{
		if(strcmp(password, "Admin123") == 0)
		{
			printf("\nAdmin successfully logged in...");
		}
		else
		{
			printf("\nPassword entered is invalid");
		}	
	}
	else
	{
		printf("\nUsername entered is invalid");
	}
	
	

}
