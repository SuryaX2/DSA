// IMPLEMENTING ARRAY USING STACK
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
int stack[SIZE], top = -1, choice, value;
void push()
{
	if (top == SIZE - 1)
	{
		printf("STACK OVERFLOW !!\n");
		return;
	}
	else
	{
		printf("Enter Value : ");
		scanf("%d", &value);
		stack[++top] = value;
	}
}
void pop()
{
	if (top == -1)
	{
		printf("STACK UNDERFLOW !!\n");
		return;
	}
	else
		printf("DELETED : %d\n", stack[top--]);
}
void display()
{
	if (top == -1)
	{
		printf("STACK IS EMPTY !!\n");
		return;
	}
	else
	{
		printf("STACK is : \n");
		for (int i = top; i >= 0; i--)
			printf("|__%d__|\n", stack[i]);
		printf("\n");
	}
}
int main()
{
	printf("\n\n******MENU******\n");
	printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
	while (1)
	{
		printf("Enter Your Choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Wrong Choice !!");
		}
	}
	return 0;
}