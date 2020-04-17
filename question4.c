#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	{
	int n,fd;
	char buff[50];
	
	printf("Enter text to write in the file:\n");
	n= read(0, buff, 50);
	fd=open("file",O_CREAT | O_RDWR, 0777); 
	write(fd, buff, n);
	write(1, buff, n);
    int close(int fd);
    }


    {
        char buf;
        int sourcefile,destfile,n;
        sourcefile=open("file",O_RDONLY);
        if(sourcefile==-1)
        {
            perror("SOURCE FILE ERROR");
            exit(0);
        }
        else
        {
            destfile=open("file2",O_WRONLY | O_CREAT , 0641);
            if(destfile==-1)
            {
                perror("DESTINATION FILE ERROR");
                exit(0);
            }
            else
            {
                while((n=read(sourcefile,&buf,1)) != -1)
                {
                    write( destfile, &buf, 1 );
                }  
                close(sourcefile);
                close(destfile);
            }
        }
    }
   	return 0;	
}
