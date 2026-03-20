// Dynamically reads integers until (-1) is entered, storing them in a resizable array using realloc 
// then creates a minimal-sized array containing only the inserted elements and free the memory
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,size,capacity,i;
    int *v = malloc(sizeof(int));
    int *minimal_array;

    x = 0;
    size = 0;
    capacity = 1;

    if(v == NULL) {
        printf("Error memory fail\n");
        exit(EXIT_FAILURE); }

    while(x != -1)
    {
        printf("Enter a value: ");
        scanf("%d", &x);

        if(size == capacity) {
              v = realloc(v, (capacity += 1) * sizeof(int));
              capacity++;
        }

        if(x != -1) {
        v[size] = x;
        size++; }
    }

    minimal_array = malloc(size * sizeof(int));
    if(minimal_array == NULL) {
        printf("Error: memory fail\n");
        exit(EXIT_FAILURE); }

    for(i = 0; i < size; i++)
    {
        minimal_array[i] = v[i];
    }
    free(v);

    printf("Array copied: %d elements\n", size);

    free(minimal_array);

    return 0;
}