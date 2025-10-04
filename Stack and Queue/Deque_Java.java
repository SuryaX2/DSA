class Deque {
    private int[] a;
    private int front, rear, size;

    public Deque(int size) {
        this.size = size;
        a = new int[size];
        front = rear = -1;
    }

    // Insert at front
    public void insertFront(int data) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            System.out.println("Deque is Full");
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        a[front] = data;
    }

    // Insert at rear
    public void insertRear(int data) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            System.out.println("Deque is Full");
            return;
        } else if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        a[rear] = data;
    }

    // Delete from front
    public int deleteFront() {
        if (front == -1 && rear == -1) {
            System.out.println("Deque is Empty");
            return -1;
        }
        int data = a[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return data;
    }

    // Delete from rear
    public int deleteRear() {
        if (front == -1 && rear == -1) {
            System.out.println("Deque is Empty");
            return -1;
        }
        int data = a[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return data;
    }

    // Peek front
    public int peekFront() {
        if (front == -1 && rear == -1) {
            System.out.println("Deque is Empty");
            return -1;
        }
        return a[front];
    }

    // Peek rear
    public int peekRear() {
        if (front == -1 && rear == -1) {
            System.out.println("Deque is Empty");
            return -1;
        }
        return a[rear];
    }

    // isEmpty Operation
    public boolean isEmpty() {
        return front == -1 && rear == -1;
    }

    // isFull Operation
    public boolean isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    @Override
    public String toString() {
        if (front == -1 && rear == -1) {
            return "Deque is Empty";
        }
        StringBuilder sb = new StringBuilder();
        int i = front;
        while (true) {
            sb.append(a[i]).append(" ");
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        return sb.toString().trim();
    }
}

public class Deque_Java {
    public static void main(String[] args) {
        Deque deque = new Deque(5);
        deque.insertRear(10);
        deque.insertRear(20);
        deque.insertFront(5);
        deque.insertFront(15);
        deque.insertRear(25); // Deque is Full
        System.out.println("Current Deque: " + deque);
        System.out.println("Front element: " + deque.peekFront());
        System.out.println("Rear element: " + deque.peekRear());
        System.out.println("Deleted from front: " + deque.deleteFront());
        System.out.println("Deleted from rear: " + deque.deleteRear());
        System.out.println("Is Deque empty? " + deque.isEmpty());
        System.out.println("Is Deque full? " + deque.isFull());
        System.out.println("Current Deque: " + deque);
    }
}
