class Stack {
    private int[] a;
    private int size;
    private int top;

    public Stack(int size) {
        this.size = size;
        this.a = new int[size];
        this.top = -1;
    }

    // Push Operation
    public void push(int data) {
        if (top == size - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        a[++top] = data;
    }

    // Pop Operation
    public int pop() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        }
        return a[top--];
    }

    // Peek Operation
    public int peek() {
        if (top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        }
        return a[top];
    }

    // isEmpty Operation
    public boolean isEmpty() {
        return top == -1;
    }

    // isFull Operation
    public boolean isFull() {
        return top == size - 1;
    }

    // Display Operation
    public void display() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return;
        }
        for (int i = top; i >= 0; i--) {
            System.out.println(a[i]);
        }
    }
}

public class Stack_Java {
    public static void main(String[] args) {
        Stack stack = new Stack(10);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();
        System.out.println("Top element is: " + stack.peek());
        System.out.println("Popped element is: " + stack.pop());
        stack.display();
        System.out.println("Is stack empty? " + stack.isEmpty());
        System.out.println("Is stack full? " + stack.isFull());
        stack.push(40);
        stack.push(50);
        stack.push(60);
        stack.display();
        System.out.println("Is stack full? " + stack.isFull());
        stack.push(70);
        stack.push(80);
        stack.push(90);
        stack.push(100);
        stack.push(110);
        stack.display();
        System.out.println("Is stack full? " + stack.isFull());
        stack.push(120);
        while (!stack.isEmpty()) {
            System.out.println("Popped element is: " + stack.pop());
        }
        stack.pop();
        stack.display();
    }
}