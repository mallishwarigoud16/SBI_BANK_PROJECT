#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    char write_msg[] = "hello from parent";
    char read_msg[50];

    if(pipe(fd) == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }

    if(fork() == 0)
    {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("child received: %s\n", read_msg);
        close(fd[0]);
    }
    else
    {
        close(fd[0]);
        write(fd[1], write_msg, strlen(write_msg) + 1);
        printf("parent sent: %s\n", write_msg);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
