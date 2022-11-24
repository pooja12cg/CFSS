#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

void main()
{
	char *username;
	char *password;
	printf("Enter the admin username: ");
	fgets(username,sizeof(username),stdin);
	username=(char *)malloc(100 * sizeof(char));
	printf("\nEnter the admin password: ");
	fgets(password,sizeof(password),stdin);
	password=(char *)malloc(100 * sizeof(char));
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
