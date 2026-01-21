/*
1. 
Scrivere un programma dove la funzione main 
- riceve (da terminale) dei valori interi strettamente positivi (quantità indefinita); 
- restituisce al terminale:
	- 0 se gli argomenti sono tutti valori interi strettamente positivi (>0);
	- 1 se gli argomenti non sono tutti valori interi strettamente positivi (>0);
	- 2 se nessun valore intero è ricevuto.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    for(i = 0; argv[i] != 0; i++)
    {
        printf("entrata %d\n",atoi(argv[i]));
    }


    return 0;
}