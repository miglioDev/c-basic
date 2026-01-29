// Verifies whether an indefinite number of command-line arguments are valid integers 
// and ordered in increasing order, practicing input validation 

/*
4. 
Scrivere un programma dove la funzione main 
- riceve (da terminale) dei numeri (quantità indefinita); 
- restituisce al terminale:
	- 0 se i numeri sono ordinati in modo crescente;
	- 1 se i numeri non sono ordinati;
	- 2 se almeno uno degli argomenti non è un numero;
	- 3 se nessun argomento è stato ricevuto.

*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    int j,x,y;

    if(argc < 2) {
        printf("No argument have been entered\n");
        exit(3); }
    

    for(j = 1; j < argc-1; j++)
    {
        if(sscanf(argv[j], "%d", &x) == 0) {
            printf("Error invalid string\n");
            exit(2); }
    }

    
    for(j = 1; j < argc-1; j++)
    {
        if(sscanf(argv[j], "%d", &x) == 0) {
            printf("Error invalid string\n");
            exit(2); }
        
        if(sscanf(argv[j+1], "%d", &y) == 0) {
            printf("Error invalid string\n");
            exit(2); }

        if (x > y)
	    {
	    printf("Error value non in order\n");
            exit(EXIT_FAILURE); 
        }
    }

    return 0;
}