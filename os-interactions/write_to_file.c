// Write text to a file using write() system call, usage: ./program filename
// creates the file if it doesn't exist with permissions -rw-r--r-- (0644)
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fp = open(argv[1], O_WRONLY | O_CREAT, 0644);

    if(fp == -1) {
        perror("open");
        exit(1);
    }

    write(fp, "I like studing OS\n", 18);

    close(fp);

    return 0;
}