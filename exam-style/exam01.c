/*
EXAM 01 – Programming in C

Implement the following functions and a main program.


1) File-to-array loading function

Write a function that:
- takes as input:
  * an integer array,
  * an integer value x,
  * a file pointer.
- reads integers from the file and stores into the array only those values
  that are strictly positive and divisible by x.
- ensures that the array capacity is not exceeded.
- appends the value -1 as a sentinel marking the end of the array.
- returns 1 if the array becomes full (including the sentinel),
  otherwise returns 0.

Example:
x = 3
file contents: 7 9 1 27 0 3 -8 14 -15 21 33
resulting array: 9 27 3 21 33 -1


2) Array display function

Write a function that:
- receives an integer array terminated by -1 as a sentinel.
- if the array contains no elements other than the sentinel,
  prints an appropriate error message.
- otherwise prints the indices and corresponding values of the array
  (excluding the sentinel) in horizontal format.
- returns nothing.

Example:
indices: 0 1 2 3 4
values:  9 27 3 21 33


3) Digit-counting function

Write a function that:
- receives an integer array terminated by -1 as a sentinel
  and two output parameters q1 and q2.
- assigns to q1 the number of values consisting of exactly one digit
  contained in the array.
- assigns to q2 the number of values consisting of exactly two digits
  contained in the array.
- returns nothing.

Example:
array: 9 27 3 21 33
q1 = 2
q2 = 3


4) Front-insertion function using pointer arithmetic

Write a function that:
- using pointer arithmetic only,
  receives an integer array terminated by -1 as a sentinel
  and an integer value x.
- inserts x as the first element of the array,
  shifting all existing elements to the right.
- returns nothing.

Example:
array: 9 27 3 21 33
x = 4
resulting array: 4 9 27 3 21 33 -1


5) Main program requirements

The main function must:
- accept exactly one command-line argument representing the file name.
  If the number of arguments is incorrect, print an error message and
  terminate returning 1.
- declare an integer array with fixed size 10 (defined as a constant).
- attempt to open the specified file.
  If the file cannot be opened, print an error message and terminate
  returning 2.
- prompt the user to input an integer value x and call the file-loading
  function; then close the file.
- call the array display function.
- call the digit-counting function and display the obtained results.
- if the array is full, print an error message and terminate returning 3.
  Otherwise:
  * prompt the user to input another integer value;
  * call the front-insertion function;
  * call again the array display function;
  * terminate returning 0.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define SENTINEL -1

int load_vect(int v[], int x, FILE* fp)
{
  int i,value,output;

  i = 0;
  while(fscanf(fp, "%d", &value) == 1 && i < DIM-1 )
  {
    if(value > 0 && value%x == 0)
    {
      v[i] = value;
      i++;
    }
  }
  v[i] = SENTINEL;

  if(i == DIM-1)
      output = 1;
      else 
        output = 0;
  
  return output; 
}

void visual_array(int v[])
{
  int i;

  if(v[0] == SENTINEL) 
    printf("Error- empty array\n");
  
  else {
    printf("Index:\t");
    for(i = 0; v[i] != SENTINEL; i++)
    {
      printf("%d\t",i);
    }
    printf("\nValue:\t");
    
    for(i = 0; v[i] != SENTINEL; i++)
    {
      printf("%d\t",v[i]);
    }
    printf("\n");
  }
}

void digit_counter(int v[DIM], int* q1, int* q2)
{
  int i;

  *q1 = 0;
  *q2 = 0;

  for(i = 0; i < DIM && v[i] != SENTINEL; i++)
  {
    if(v[i] >= 0 && v[i] <= 9) 
    *(q1)++;

    if(v[i] > 9 && v[i] < 100) 
    *(q2)++;
  }
}

void add_value(int v[DIM], int number)
{
  int i,len;

  len = 0;
  while(*(v+len) != SENTINEL)
  len ++;

  for(i = len+1; i > 0; i--)
  {
    *(v+i) = *(v+i-1); 
  }
  *v = number;
}


int main (int argc, char* argv[])
{
  if(argc != 2)
  {
      printf("Error: function need one parameter as input (file-name)\n");
      exit(1);
  }
  FILE *fp;
  int v[DIM],x,sing_digit,doub_digit,is_full,number;

  fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("Error: file %s does not exist\n",argv[1]);
    exit(2);}

  printf("\nEnter a number to search in the file: "); 
  scanf("%d", &x);
  is_full = load_vect(v,x,fp);
  fclose(fp);

  visual_array(v);

  digit_counter(v,&sing_digit,&doub_digit);
  printf("\nSingle digit number: %d\n",sing_digit);
  printf("Double digit number: %d\n",doub_digit);

  if(is_full) {
    printf("\nError - vector is full\n"); 
    exit(3); }
  else {
    printf("Enter an int: ");
    scanf("%d",&number);

    add_value(v,number);
    visual_array(v);
  }

    return 0;
}

