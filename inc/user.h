#ifdef USER_H
#define USER_H
#include <common.h>

typedef struct userDetails
{
	int uphNo;
	char uName[BUFF];
	char uActivated=1;
	char uUnActivated=0;
	char simType[BUFF];
}UD;


int addUserDetails(UD *);
void dispUserAll(UD *,int,int);

