#include <stdio.h>
#include <unistd.h>

int     main(int argc, char **argv)
{    
   int id =  fork();

   if (id != 0)
        fork();
    
   
    printf("\nHola caracola: %d\n",  id);
     return(0);
}


/*
int main (int argc, char **argv)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("error");
        return 1;
    }
    int id = fork();
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("input number\n");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);


    }
    else
    {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("got from child proces %d\n", y);
    }
    return 0;
}*/
