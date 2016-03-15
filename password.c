#include <stdio.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd* getpwnam(const char *name) {
    struct passwd *ptr;
    setpwent();
    while((ptr=getpwent())!=NULL) {
        printf("%s\n", ptr->pw_name);
        if(strcmp(name,ptr->pw_name)==0)
            break;
    }
    endpwent();
    return(ptr);
}

int main(int argc,char *argv[]) {
    struct passwd *res=getpwnam(argv[1]);
    if(res==NULL)
        printf("\ninvalid user");
    else
        printf("\nvalid user");
    return 0;
}
