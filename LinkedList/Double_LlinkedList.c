// double linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} N;
N *head, *temp, *newNode;
// struct Node N;
void createList(int);
void TraverseForward();
void TraverseBackward();
void insertatbeg();
void insertatend();
void insertatspecific();
void delatbeg();
void delatend();
void delatspecific();
int count = 0, i;
void main()
{
    while (1) // for(;;)
    {
        printf("Press 1 for Create\nPress 2 for Display\nPress 3 for TraverseBackward\nPress 4 for Insert at beginning\nPress 5 for Insert at End\nPress 6 for Insert at Specific\nPress 6 for Delete at Beginning\nPress 7 for Delete at End\nPress 8 for Delete at Specific\n");
        int ch, n;
        printf("Enter the Choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Range = ");
            scanf("%d", &n);
            createList(n); // calling
            break;
        case 2:
            TraverseForward(); // calling
            break;
        case 3:
            TraverseBackward(); // calling
            break;
        case 4:
            insertatbeg(); // calling
            break;
        case 5:
            insertatend(); // calling
            break;
        case 6:
            insertatspecific(); // calling
            break;
        case 7:
            delatbeg(); // calling
            break;
        case 8:
            delatend(); // calling
            break;
        case 9:
            delatspecific(); // calling
            break;
        default:
            exit(0);
        }
    }
}
void createList(int n)
{
    int i, x;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the No.= ");
    scanf("%d", &x);
    if (head == NULL)
    {
        printf("Memory can't be deleted");
        return;
    }
    else
    {
        head->data = x;
        head->prev = NULL;
        head->next = NULL;
        temp = head;
        count++;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter the No.= ");
            scanf("%d", &x);
            newNode->data = x;
            newNode->prev = temp;
            newNode->next = NULL;
            temp->next = newNode;
            count++;
            temp = newNode;
        }
    }
}
void TraverseForward()
{
    struct Node *p;
    p = head;
    while (p->next != NULL)
    {
        printf("Value = %d Address = %u\n", p->data, p);
        p = p->next;
    }
    printf("Value = %d Address = %u\n", p->data, p);
    printf("\nReverse List = \n");
    while (p->prev != NULL)
    {
        printf("Value = %d Address = %u\n", p->data, p);
        p = p->prev;
    }
    printf("Value = %d Address = %u\n", p->data, p);
}
void TraverseBackward()
{
    struct Node *q;
    q = temp;
    while (q != head)
    {
        printf("Value = %d Address = %u\n", q->data, q);
        q = q->prev;
    }
    printf("Value = %d Address = %u\n", q->data, q);
    //  printf("Address = %u\n",q->next);
}
void insertatbeg()
{
    int x;
    newNode = (N *)malloc(sizeof(N));
    printf("Enter the data: ");
    scanf("%d", &x);
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    count++;
}
void insertatend()
{
    int x;
    newNode = (N *)malloc(sizeof(N));
    N *p;
    printf("Enter the data to insert at the end: ");
    scanf("%d", &x);
    newNode->data = x;
    newNode->next = NULL;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->prev = p;
    count++;
}
void insertatspecific()
{
    int x, pos;
    struct Node *p, *q;
    p = head;
    printf("Enter the position to insert the data: ");
    scanf("%d", &pos);
    if (pos == 1)
        insertatbeg();
    else if (pos == count + 1)
        insertatend();
    else
    {
        for (i = 1; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        newNode = (N *)malloc(sizeof(N));
        printf("Enter the data: ");
        scanf("%d", &x);
        newNode->data = x;
        newNode->prev = q;
        newNode->next = p;
        q->next = newNode;
        p->prev = newNode;
        count++;
    }
}
void delatbeg()
{
    N *p;
    p = head;
    head = head->next;
    free(p);
    head->prev = NULL;
    --count;
}
void delatend()
{
    N *tmp, *p;
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    p = tmp->prev;
    free(tmp);
    p->next = NULL;
    --count;
}
void delatspecific()
{
    int i, pos;
    N *del, *temp1, *q;
    printf("\nEnter the Position =");
    scanf("%d", &pos);
    if (pos == 1)
        delatbeg();
    else if (pos == count)
        delatend();
    else if (pos > count)
        return;
    else
    {
        del = head;
        for (i = 1; i < pos; i++)
        {
            temp1 = del;
            del = del->next;
        }
        /*  q=del->next;
          free(del);
        temp1->next=q;
        q->prev=temp1;*/
        temp1->next = del->next;
        del->next->prev = temp1;
        free(del);
        --count;
    }
}