#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void enqueue(); // function declaration
void dequeue(); // function declaration
void display(); // function declaration

int queue[SIZE], front = -1, rear = -1;
int value, choice; // global variable
int main()
{
	printf("\n\n*****MENU*****\n");
	printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
	while (1)
	{
		printf("Enter Your Choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("WRONG CHOICE !!\n");
		}
	}
	return 0;
}

void enqueue()
{
	if (rear == SIZE - 1)
	{
		printf("QUEUE OVERFLOW !!\n");
		return;
	}
	else
	{
		if (front == -1)
			front = 0;
		printf("Enter Value : ");
		scanf("%d", &value);
		queue[++rear] = value;
	}
}
void dequeue()
{
	if (front == -1 || front > rear)
	{
		printf("QUEUE UNDERFLOW !!\n");
		return;
	}
	else
		printf("DELETED : %d\n", queue[front++]);
}
void display()
{
	int i;
	if (front == -1 || front > rear)
	{
		printf("QUEUE IS EMPTY !!\n");
		return;
	}
	else
	{
		printf("QUEUE is : ");
		for (i = front; i <= rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
}
