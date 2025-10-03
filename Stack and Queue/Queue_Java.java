class Queue {
    private int[] a;
    private int front;
    private int rear;
    private int size;

    public Queue(int size) {
        this.size = size;
        this.a = new int[size];
        this.front = -1;
        this.rear = -1;
    }

    // Enqueue Operation
    public void enqueue(int data) {
        if (rear == size - 1) {
            System.out.println("Queue Overflow");
            return;
        }
        if (front == -1) {
            front = 0;
        }
        a[++rear] = data;
    }

    // Dequeue Operation
    public int dequeue() {
        if (front == -1 || front > rear) {
            System.out.println("Queue Underflow");
            return -1;
        }
        int data = a[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return data;
    }

    // Peek Operation
    public int peek() {
        if (front == -1 || front > rear) {
            System.out.println("Queue Underflow");
            return -1;
        }
        return a[front];
    }

    // isEmpty Operation
    public boolean isEmpty() {
        if (front == -1 || front > rear) {
            return true;
        }
        return false;
    }

    // isFull Operation
    public boolean isFull() {
        return rear == size - 1;
    }

    // Size Operation
    public int size() {
        if (front == -1 || front > rear) {
            return 0;
        }
        return rear - front + 1;
    }

    // Display Operation
    public void display() {
        if (front == -1 || front > rear) {
            System.out.println("Queue is empty");
            return;
        }
        for (int i = front; i <= rear; i++) {
            System.out.print(" | " + a[i] + " | ");
        }
    }
}

public class Queue_Java {
    public static void main(String[] args) {
        Queue q = new Queue(5);
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        System.out.println("Is Queue full?: " + q.isFull());
        System.out.println("Size of Queue: " + q.size());
        q.enqueue(60); // This should show Queue Overflow
        q.display();
        System.out.println("\nDequeued: " + q.dequeue());
        System.out.println("Front element: " + q.peek());
        q.display();
        System.out.println();
        System.out.println("Size of Queue: " + q.size());
        System.out.println("Is Queue empty?: " + q.isEmpty());

        while (!q.isEmpty()) {
            System.out.println("Dequeued: " + q.dequeue());
        }
        q.dequeue(); // This should show Queue Underflow
        System.out.println("Is Queue empty?: " + q.isEmpty());
    }
}
