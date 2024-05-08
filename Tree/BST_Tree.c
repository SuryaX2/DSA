// Wap to create/insert a tree from ar array
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};
struct node *root = NULL;
void insert(int);
struct node *search(int);
int search1(int);
void pre_order_traversal(struct node *);
void post_order_traversal(struct node *);
void in_order_traversal(struct node *);
int main()
{
    int i, n, x, ch;
    int array[n];
    while (1)
    {
        printf("\n\n::::MENU::::\n");
        printf("\n1.Insert\n2.Search\n3.Search 2.0\n4.Pre Order Traversal\n5.In Order Traversal\n6.Post Order Traversal\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Range=");
            scanf("%d", &n); // n=5
            // input
            for (i = 0; i < n; i++) // i=0  0<5
            {
                printf("Enter the No.=");
                scanf("%d", &array[i]);
            }
            // tree insert
            for (i = 0; i < n; i++) // i=5  <5
            {
                insert(array[i]); // calling  10  20 30 15 50
            }
            break;
        case 2:
            printf("Enter the No. to be Search=");
            scanf("%d", &x); // x=30
            // search 1 process
            if (search1(x) == 1) // func. calling
                printf("\nSearch Found");
            else
                printf("\nSearch NOT Found");
            break;
        case 3: // search 2nd process
            printf("Enter the No. to be Search=");
            scanf("%d", &x);               // x=30
            struct node *temp = search(x); // calling  x=30  temp=148
            if (temp != NULL)
            {
                printf("\n[%d] Element found. %u", temp->data, temp); // 30
                printf("\n");
            }
            else
            {
                printf("\n[ x ] Element not found (%d).\n", i);
            }
            break;
        case 4:
            printf("\nPreorder traversal: ");
            pre_order_traversal(root); // calling  root=100
            break;
        case 5:
            printf("\nInorder traversal: ");
            in_order_traversal(root); // calling root =100
            break;
        case 6:
            printf("\nPost order traversal: ");
            post_order_traversal(root); // calling root=100
            break;
        }
    }
    getch();
    return 0;
}
void insert(int data) // data =50
{
    struct node *tempNode;
    tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    // if tree is empty
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root; // current=100
        parent = NULL;
        while (1)
        {
            parent = current; // parent=100
            // go to left of the tree
            if (data < parent->data) // 50<30
            {
                current = current->leftChild;
                // insert to the left
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            } // go to right of the tree
            else
            {
                current = current->rightChild; // NULL
                // insert to the right
                if (current == NULL)
                {
                    parent->rightChild = tempNode; // 148
                    return;
                }
            }
        }
    }
}
struct node *search(int data) // data=30
{
    struct node *current = root; // current=100
    printf("Visiting elements: ");
    while (current->data != data) // 30!=30
    {
        if (current != NULL)
            printf("%d ", current->data); // 10 20
        // go to left tree
        if (current->data > data) // 20>30
        {
            current = current->leftChild;
        }
        // else go to right tree
        else
        {
            current = current->rightChild; // current=148
        }
        // not found
        if (current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
int search1(int data) // data=60
{
    struct node *current = root;
    printf("Visiting elements: ");
    while (current->data != data) // 50!=60
    {
        if (current != NULL)              // 196!=NULL
            printf("%d ", current->data); // 10 20 30 50
        // go to left tree
        if (current->data > data) // 50>60
        {
            current = current->leftChild;
        }
        // else go to right tree
        else
        {
            current = current->rightChild; // current=NULL
        }
        // not found
        if (current == NULL)
        {
            return 0;
        }
    }
    return 1;
}
void pre_order_traversal(struct node *root) // root=196
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order_traversal(root->leftChild);  // recursion
        pre_order_traversal(root->rightChild); // recursion
    }
}
void in_order_traversal(struct node *root) // root=NULL
{
    if (root != NULL)
    {
        in_order_traversal(root->leftChild); // calling NULL
        printf("%d ", root->data);
        in_order_traversal(root->rightChild); // calling  196
    }
}
void post_order_traversal(struct node *root) // root=100
{
    if (root != NULL)
    {
        post_order_traversal(root->leftChild);  // null
        post_order_traversal(root->rightChild); // null
        printf("%d ", root->data);
    }
}