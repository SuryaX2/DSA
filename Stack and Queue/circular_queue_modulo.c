#include <stdio.h>
#define max 5
int queue[max], front = -1, rear = -1, n;
void enqueue() {
    if ((rear + 1) % max == front) {
        printf("Queue is overflow..");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else
        rear = (rear + 1) % max;
    printf("\nEnter the element which is to be inserted :: ");
    scanf("%d", &n);
    queue[rear] = n;
}
void dequeue() {
    if ((front == -1)) {
        printf("\nQueue is underflow..");
        return;
    }
    printf("\nThe dequeued element is %d", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else
        front = (front + 1) % max;
}
void display() {
    int i = front;
    if (front == -1) {
        printf("\n Queue is empty..");
        return;
    } else {
        printf("\nElements in a Queue are :");
        for (i = front; i != rear; i = (i + 1) % max)
            printf("%d,", queue[i]);
        printf("%d,", queue[i]);
    }
}
int main() {
    int choice = 1;
    while (choice < 4 && choice != 0) {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        printf("\n\nEnter your choice  : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
        }
    }
    return 0;
}