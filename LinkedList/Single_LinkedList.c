// wap to create a single linked list & traverse the S.L.L.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head;
void createlist(int);
void traverse();
void insertatbeg();
void insertatend();
void insertatspecific();
void deleteatbeg();
void deleteatspecific();
void deleteatend();
int c = 0, tempo;
void main()
{
	while (1) // for(;;)
	{
		printf("Press 1 for Create\nPress 2 for Display\nPress 3 for Insert at beginning\nPress 4 for Insert at End\nPress 5 for Insert at Specific\nPress 6 for Delete at Beginning\nPress 7 for Delete at End\nPress 8 for Delete at Specific\n");
		int ch, n;
		printf("Enter the Choice = ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the Range = ");
			scanf("%d", &n);
			createlist(n); // calling
			break;
		case 2:
			traverse(); // calling
			break;
		case 3:
			insertatbeg(); // calling
			break;
		case 4:
			insertatend(); // calling
			break;
		case 5:
			insertatspecific(); // calling
			break;
		case 6:
			deleteatbeg(); // calling
			break;
		case 7:
			deleteatend(); // calling
			break;
		case 8:
			deleteatspecific(); // calling
			break;
		default:
			exit(0);
		}
	}
	getch();
}
void createlist(int n)
{
	struct Node *newNode, *temp;
	int x, i;
	head = (struct Node *)malloc(sizeof(struct Node));
	if (head == NULL)
		printf("Memory can't be allocated");
	else
	{
		printf("Enter the No.=");
		scanf("%d", &x);
		head->data = x;
		head->next = NULL;
		temp = head;
		for (i = 2; i <= n; i++)
		{
			newNode = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter the No.=");
			scanf("%d", &x);
			newNode->data = x;
			newNode->next = NULL;
			temp->next = newNode;
			temp = newNode;
		}
	}
}
void traverse()
{
	struct Node *p;
	p = head;
	while (p != NULL)
	{
		printf("Value =%d Address = %u\n", p->data, p);
		p = p->next;
		c++;
	}
	printf("\n");
	printf("Total Nodes = %d", c);
	tempo = c;
	c = 0;
}
void insertatbeg()
{
	struct Node *beg;
	int x;
	beg = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the No.=");
	scanf("%d", &x);
	beg->data = x;
	beg->next = head;
	head = beg;
}
void insertatend()
{
	struct Node *end, *temp, *p;
	int x;
	end = head;
	while (end != NULL)
	{
		temp = end;
		end = end->next;
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter the No.=");
	scanf("%d", &x);
	p->data = x;
	p->next = NULL;
	temp->next = p;
}
void insertatspecific()
{
	struct Node *q, *temp, *newNode;
	int i, pos, x;
	printf("Enter the Position = ");
	scanf("%d", &pos);
	temp = head;
	if (pos == 1)
		insertatbeg();
	else if (pos == tempo + 1)
		insertatend();
	else
	{
		for (i = 1; i < pos; i++)
		{
			q = temp;
			temp = temp->next;
		}
		newNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter the No.= ");
		scanf("%d", &x);
		newNode->data = x;
		newNode->next = temp;
		q->next = newNode;
	}
}
void deleteatbeg()
{
	struct Node *p;
	p = head;
	if (p == NULL)
	{
		printf("L.L. is empty!!! deletion can't be possible\n");
		return;
	}
	else
	{
		printf("\nDeleted = %d Address = %u\n", p->data, p);
		head = head->next;
		free(p);
		//   printf("%d     %u",p->data,p);
		printf("\nDeleted Successfully !!\n");
	}
}
void deleteatspecific()
{
	struct Node *p, *q, *r;
	int i, n;
	p = head;
	if (p == NULL)
	{
		printf("L.L. is empty!!! deletion can't be possible\n");
		return;
	}
	else
	{
		printf("Enter the Position u wanna delete = ");
		scanf("%d", &n);
		for (i = 1; i < n; i++)
		{
			q = p;
			p = p->next;
		}
		r = p->next;
		printf("\nDeleted = %d Address = %u\n", p->data, p);
		free(p);
		q->next = r;
	}
}
void deleteatend()
{
	struct Node *p, *q;
	p = head;
	if (p == NULL)
	{
		printf("L.L. is empty!!! deletion can't be possible\n");
		return;
	}
	else
	{
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		printf("\nDeleted = %d Address = %u\n", p->data, p);
		free(p);
		q->next = NULL;
	}
}