#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
 
int main(void) 
{ 
    int i = 0; 
    struct stat st; 

    for (i=0; i<10; i++)
    {
        printf("fstat [%d]\n",i);
        errno = 0;
        fstat(i, &st);
        printf(" -> %s\n",strerror(errno));
    }
}
