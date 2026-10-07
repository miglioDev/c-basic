// Read bytes from a file using the read() system call
// then reads data into a buffer and writes it to standard output.
// Includes error checking for all system calls and use ./program filename
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int check(int res,char *msg);

int main (int argc, char *argv[])
{
    char buffer[512];
    ssize_t n;

    if(argc != 2) {
        exit(EXIT_FAILURE);
    }

    int fd = check(open(argv[1],O_RDONLY), argv[1]);

    while((n = check(read(fd, buffer, sizeof buffer), "read")) > 0)
    {
        write(1, buffer, n);
    }

    close(fd);

    return 0;
}

int check(int res,char *msg)
{
    if(res == -1) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return res;
}