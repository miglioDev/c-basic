/*
EXAM 05 - Programming in C

Design a program composed of several functions that operate on a square matrix of integers. The matrix size is stored in a global variable.

---

### Function 1 — Matrix Initialization

Write a function that:

* Takes as input a square integer matrix and two integer values `minVal` and `maxVal`.
* Fills the matrix with random integers strictly between `minVal` and `maxVal` (endpoints excluded).
* Ensures that the generated values change at every execution.

*Hint:* use `rand()` and initialize the seed with `srand(time(NULL))`.

**Example (one possible run):**
`minVal = 5`, `maxVal = 80`, `size = 4`

Resulting matrix:

```
34  72  19  61
58  27  45  11
66  39  21  53
14  70  32  48
```

This function does not return any value.

---

### Function 2 — Matrix Display

Write a function that:

* Takes as input a square integer matrix.
* Prints all matrix values along with their row and column indices, following the format shown in the example.

**Example output format:**

```
      0   1   2   3
    ----------------
0 |  34  72  19  61
1 |  58  27  45  11
2 |  66  39  21  53
3 |  14  70  32  48
```

This function does not return any value.

---

### Function 3 — Corner Aggregation (Pointer Arithmetic)

Write a function that, using pointer arithmetic:

* Takes as input a square integer matrix and two integer pointer parameters `sumCorners` and `prodCorners`.
* Stores in `sumCorners` the sum of the values located at the four corners of the matrix.
* Stores in `prodCorners` the product of the values located at the four corners of the matrix.

**Example:**
Given the matrix above, the corner elements are:

* Top-left, top-right, bottom-left, bottom-right

Result:

```
sumCorners = 157
prodCorners = 1782144
```

This function does not return any value.

---

### Function 4 — Write Corners to File

Write a function that:

* Takes as input a square integer matrix and the name of a text file.
* Writes to the file only the corner values of the matrix, preserving their relative layout.

**Example:**

Matrix:

```
34  72  19  61
58  27  45  11
66  39  21  53
14  70  32  48
```

File content:

```
34 61
14 48
```

This function does not return any value.

---

### `main` Function Requirements

The `main` function must:

* Read exactly **four command-line arguments**:

  1. The size of the square matrix
  2. The minimum value
  3. The maximum value
  4. The name of a text file

  If the number of arguments is incorrect, print:
  **`ERROR: invalid number of parameters`**
  and terminate returning `1`.

* Check that the matrix size is at least `2`.
  If not, print:
  **`ERROR: invalid matrix size`**
  and terminate returning `2`.

* Check that the minimum value is positive and strictly less than the maximum value.
  If not, print:
  **`ERROR: invalid range values`**
  and terminate returning `3`.

* Assign the matrix size to a global variable and declare a square matrix of that size.

* Call the function that fills the matrix, then the function that displays it.

* Call the function that computes the sum and product of the corner elements, then print:
  **`The sum is ... The product is ...`**

* Call the function that writes the corner values to the specified file.

* Terminate the program returning `0`.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dim;

void load_matrix(int dim, int mat[][dim], int min_value, int max_value)
{
    int i,j,min, max;
    srand(time(NULL));

    min = min_value + 1;
    max = max_value - 1;

    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
        {
            mat[i][j] = min + rand()%(max - min + 1);
        }
    }
}

void print_matrix(int mat[][dim])
{
    int i,j;

    for(i = 0; i < dim; i++)
    {
        printf("%d\t*",i);
        for(j = 0; j < dim; j++)
        {
            printf("\t%d",mat[i][j]);
        }
        printf("\n");
    }
    printf("\t\t");

    for(j = 0; j < dim; j++)
    {   
        printf("*\t");    
    }
    printf("\n\t\t");
    
    for(j = 0; j < dim; j++)
    {   
        printf("%d\t",j);    
    }
}

void sum_func(int mat[][dim], int *p1, int *p2)
{
    int i,j;

    *p1 = 0;
    *p2 = 1;   

    for(i = 0; i < dim; i++)
    {
        for(j = 0; j < dim; j++)
        {
            if((i == 0 && j == 0) || (i == dim-1 && j == 0) || (i == 0 && j == dim-1) || (i == dim-1 && j == dim-1))
            {
                *p1 = *p1 + *(*(mat+i)+j);
                *p2 = *p2 * *(*(mat+i)+j);
            }
        }
    }
}

void file_print(int mat[][dim], char *argv[])
{
    FILE *fp;
    fp = fopen(argv[4],"w");

    if(fp == NULL) {
        printf("Error: error on file opening\n");}

    fprintf(fp,"%d\t%d\n%d\t%d",mat[0][0],mat[0][dim-1],mat[dim-1][0],mat[dim-1][dim-1]);

    fclose(fp);
}

int main (int argc, char *argv[]) // ./a dim min_value max_value text_filename
{
    if(argc != 5) {
        printf("Error: number of parameter incorrect\n");
        exit(1); }
    
    if(atoi(argv[1]) < 2) {
        printf("Error: incorrect value\n"); 
        exit(2); }
    
    if(atoi(argv[2]) <= 0 || atoi(argv[2]) >= atoi(argv[3])) {
        printf("Error: incorrect value\n");
        exit(3); }

    dim = atoi(argv[1]);
    int mat[dim][dim], sum, product;

    load_matrix(dim, mat, atoi(argv[2]), atoi(argv[3]));
    print_matrix(mat);
    sum_func(mat,&sum,&product);
    printf("\nSum equal to: %d",sum);
    printf("\nProduct: %d\n",product);

    file_print(mat,argv);

    return 0;
}