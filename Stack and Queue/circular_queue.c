// CIRCULAR QUEUE
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 3

void insert();	// function declaration
void del();		// function declaration
void display(); // function declaration

int cqueue[SIZE], front = -1, rear = -1; // global variable
int choice, value;						 // global variable
int main()
{
	printf("\n\n*****MENU*****\n");
	printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
	do
	{
		printf("Enter Choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("WRONG CHOICE !!\n");
		}
	} while (choice != 4);
	return 0;
}

void insert()
{
	if ((rear + 1) % SIZE == front)
	{
		printf("QUEUE OVERFLOW !!\n");
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if (rear == SIZE - 1)
			rear = 0;
		else
			rear++;
	}
	printf("Enter Value : ");
	scanf("%d", &value);
	cqueue[rear] = value;
}

void del()
{
	if (front == -1)
	{
		printf("QUEUE IS UNDERFLOW !!\n");
		return;
	}
	printf("DELETED : %d\n", cqueue[front]);
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == SIZE - 1)
			front = 0;
		else
			front++;
	}
}

void display()
{
	int i = front;
	if (front == -1)
	{
		printf("\n Queue is empty..");
		return;
	}
	else
	{
		printf("\nElements in a Queue are :");
		for (i = front; i != rear; i = (i + 1) % SIZE)
			printf("%d,", cqueue[i]);
		printf("%d,", cqueue[i]);
	}
}
