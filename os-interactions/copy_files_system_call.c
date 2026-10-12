//leggi un file e copia il suo contenuto di 512 byte in un secondo file input.txt e output.txt 
// sono forniti come argomenti di riga di comando, i file esistono gia, il file di output dovra essere svuotato prima della copiatura
// vincolo lavorare tramite system call, controllare la validità delle operazioni  
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define DIM 512

int check(int res, const char *msg);

int main (int argc, char *argv[])
{
    if(argc != 3) {
        printf("Must enter input, output to execute\n");
        exit(1);
    }

    char buffer[DIM];
    int n;

    int in = check(open(argv[1], O_RDONLY), argv[1]);

    int out = check(open(argv[2], O_WRONLY | O_TRUNC), argv[2]);
    while((n = check(read(in,buffer,sizeof(buffer)), "read")) > 0)
    {
        check(write(out, buffer, n), "write");
    }

    check(close(in), argv[1]);
    check(close(out), argv[2]);

    return 0;
}

int check(int res, const char *msg)
{
    if(res == -1) {
        perror("msg");
        exit(EXIT_FAILURE);
    }
    else return res;
}