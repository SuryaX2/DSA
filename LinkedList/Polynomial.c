#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct link
{
    int coeff;
    int pow;
    struct link *next;
} my_poly;
void my_create_poly(my_poly **node);
void my_show_poly(my_poly *node);
void my_add_poly(my_poly **result, my_poly *poly1, my_poly *poly2);
int main()
{
    int ch;
    do
    {
        my_poly *poly1, *poly2, *poly3;
        printf("\nCreate 1st expression\n");
        my_create_poly(&poly1); // calling
        printf("\nStored the 1st expression");
        my_show_poly(poly1); // CALLING
        printf("\nCreate 2nd expression\n");
        my_create_poly(&poly2); // calling
        printf("\nStored the 2nd expression");
        my_show_poly(poly2);               // calling
        my_add_poly(&poly3, poly1, poly2); // calling
        my_show_poly(poly3);               // calling
        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch); // 0
    } while (ch);
    return 0;
}
void my_create_poly(my_poly **node)
{
    int flag;
    int coeff, pow;
    my_poly *tmp_node;
    tmp_node = (my_poly *)malloc(sizeof(my_poly));
    *node = tmp_node;
    do
    {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff); // coeff=4
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow); // pow=1
        tmp_node->pow = pow;
        tmp_node->next = NULL;
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag); // flag=0
        if (flag)
        {
            tmp_node->next = (my_poly *)malloc(sizeof(my_poly)); // Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
void my_show_poly(my_poly *node)
{
    printf("\nThe polynomial expression is:\n");
    while (node != NULL) // NODE=NULL
    {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next; // node=NULL
        if (node != NULL)  // NULL
            printf(" + ");
    }
}
void my_add_poly(my_poly **result, my_poly *poly1, my_poly *poly2)
{

    my_poly *tmp_node;
    tmp_node = (my_poly *)malloc(sizeof(my_poly));
    tmp_node->next = NULL;
    *result = tmp_node;
    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow) // 0>1
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) // 0<1
        {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff + poly2->coeff; // 5+3=8
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (poly1 && poly2)
        {
            tmp_node->next = (my_poly *)malloc(sizeof(my_poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
    while (poly1 || poly2)
    {
        tmp_node->next = (my_poly *)malloc(sizeof(my_poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
        if (poly1)
        {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2)
        {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
    printf("\nAddition Complete");
}