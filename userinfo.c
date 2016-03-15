#include <stdio.h>
#include <pwd.h>

int main(int argv, char ** argc)
{
	struct passwd *p;

	if(argv==2)
	{
		if((p = getpwnam(argc[1]))!=NULL)
		{
			printf("\nname: %s",p->pw_name);
			printf("\npassword: %s",p->pw_passwd);
			printf("\nuid: %d",p->pw_uid);
			printf("\ngid: %d",p->pw_gid);
			printf("\ngecos: %s",p->pw_gecos);
			printf("\ndir: %s",p->pw_dir);
			printf("\nshell: %s",p->pw_shell);

		}
		else
			printf("invlid user");
	}
	else
		printf("usage error");
}
