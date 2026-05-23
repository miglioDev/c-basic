// Manage a dynamic inventory array of products, search by name,
// and modify quantity and price using structs and functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int number;
    float price;
} prodt;

void load_product(prodt list[], int i);
void modify(prodt list[], char name[20], int n);

int main ()
{
    int i,n;
    char name[20];

    printf("How many product will you enter? ");
    scanf("%d",&n);

    prodt *list = malloc(sizeof(prodt) * n);

    for(i = 0; i < n; i++)
    {
        load_product(list,i);
    }

    printf("Choose 1 product to modify (enter the name): ");
    scanf("%s",name);

    modify(list,name,n);

    return 0;
}

void load_product(prodt list[], int i)
{
    printf("\n\nProduct n.%d",i);
    printf("\nEnter product name: ");
    scanf("%s",list[i].name);

    printf("\nEnter number of pieces: ");
    scanf("%d",&list[i].number);

    printf("\nEnter product price: ");
    scanf("%f",&list[i].price);
}

void modify(prodt list[], char name[20], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(list[i].name, name) == 0) {
            printf("\nEnter new amount: ");
            scanf("%d",&list[i].number);

            printf("\nEnter new price: ");
            scanf("%f",&list[i].price);
            return;           
        }
    }

    printf("\nProduct not found\n");
}