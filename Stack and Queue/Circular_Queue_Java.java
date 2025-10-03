class CircularQueue {
    private int[] a;
    private int front, rear, size;

    public CircularQueue(int size) {
        this.size = size;
        a = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    public void enqueue(int data) {
        if ((rear + 1) % size == front) {
            System.out.println("Queue is Full");
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
            a[rear] = data;
        } else {
            rear = (rear + 1) % size;
            a[rear] = data;
        }
    }

    // Dequeue Operation
    public int dequeue() {
        if (front == -1 && rear == -1) {
            System.out.println("Queue is Empty");
            return -1;
        } else if (front == rear) {
            int data = a[front];
            front = rear = -1;
            return data;
        } else {
            int data = a[front];
            front = (front + 1) % size;
            return data;
        }
    }

    // Peek Operation
    public int peek() {
        if (front == -1 && rear == -1) {
            System.out.println("Queue is Empty");
            return -1;
        } else {
            return a[front];
        }
    }

    // isEmpty Operation
    public boolean isEmpty() {
        return front == -1 && rear == -1;
    }

    // isFull Operation
    public boolean isFull() {
        return (rear + 1) % size == front;
    }

    // Size Operation
    public int size() {
        if (front == -1)
            return 0;
        if (isFull())
            return size;
        return (size + rear - front + 1) % size;
    }

    // Display Operation
    public void display() {
        if (front == -1 && rear == -1) {
            System.out.println("Queue is Empty");
            return;
        } else {
            int i = front;
            while (true) {
                System.out.print(a[i] + " ");
                if (i == rear) {
                    break;
                }
                i = (i + 1) % size;
            }
            System.out.println();
        }
    }
}

public class Circular_Queue_Java {
    public static void main(String[] args) {
        CircularQueue cq = new CircularQueue(5);
        cq.enqueue(1);
        cq.enqueue(2);
        cq.enqueue(3);
        cq.enqueue(4);
        cq.enqueue(5);
        cq.display(); // Output: 1 2 3 4 5
        cq.enqueue(6); // Output: Queue is Full
        System.out.println("Dequeued: " + cq.dequeue()); // Output: Dequeued: 1
        cq.display(); // Output: 2 3 4 5
        cq.enqueue(6);
        cq.display(); // Output: 2 3 4 5 6
        System.out.println("Front element: " + cq.peek()); // Output: Front element: 2
        System.out.println("Is Queue Full? " + cq.isFull()); // Output: Is Queue Full? true
        System.out.println("Is Queue Empty? " + cq.isEmpty()); // Output: Is Queue Empty? false
        System.out.println("Size of Queue: " + cq.size()); // Output: Size of Queue: 5
    }
}
