#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i, n, j = 0;
int a[20];
int fd1[2], fd2[2];
pid_t p1, p2;
char str[20], rev[20];

int main()
{
    printf("\n Enter the string: ");
    scanf("%s", str);
    p1 = fork();
    if (p1 > 0)
    {
        close(fd1[0]);
        close(fd2[1]);
        // PROCESS 1: Writing to Pipe 1
        write(fd1[1], str, strlen(str));
        p2 = fork();
        if (p2 > 0)
        {
            // PROCESS 2: Reading from Pipe 1
            read(fd1[0], str, strlen(str));
            for (int i = strlen(str) - 1; i >= 0; i--)
            {
                rev[j] = str[i];
                j++;
            }
            // PROCESS 2: Writing to Pipe 2
            write(fd2[1], rev, strlen(rev));
        }
        // PROCESS 1: Reading from Pipe 1
        read(fd2[0], rev, strlen(rev));
        printf("\n Reversed string is: %s", rev);
    }
    return 0;
}