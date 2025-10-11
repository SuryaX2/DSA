import java.util.NoSuchElementException;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }

    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }
}

class CircularSinglyLinkedList {
    Node head, tail;
    int size;

    public CircularSinglyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public CircularSinglyLinkedList(Node head, Node tail) {
        this.head = head;
        this.tail = tail;
        this.size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int get(int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else {
            Node temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp.next;
            }
            return temp.data;
        }
    }

    public void insertAtBegin(int data) {
        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
        } else {
            newNode.next = head;
            head = newNode;
            tail.next = head;
        }
        size++;
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
        } else {
            tail.next = newNode;
            newNode.next = head;
            tail = newNode;
        }
        size++;
    }

    public void insertAtSpecific(int data, int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos > size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else if (pos == 0) {
            insertAtBegin(data);
        } else if (pos == size) {
            insertAtEnd(data);
        } else {
            Node newNode = new Node(data);
            Node temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
            size++;
        }
    }

    public int deleteAtBegin() {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (size == 1) {
            int data = head.data;
            head = tail = null;
            size--;
            return data;
        } else {
            int data = head.data;
            head = head.next;
            tail.next = head;
            size--;
            return data;
        }
    }

    public int deleteAtEnd() {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (size == 1) {
            int data = head.data;
            head = tail = null;
            size--;
            return data;
        } else {
            Node temp = head;
            while (temp.next != tail) {
                temp = temp.next;
            }
            int data = tail.data;
            temp.next = head;
            tail = temp;
            size--;
            return data;
        }
    }

    public int deleteAtSpecific(int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else if (pos == 0) {
            return deleteAtBegin();
        } else if (pos == size - 1) {
            return deleteAtEnd();
        } else {
            Node temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp.next;
            }
            int data = temp.next.data;
            temp.next = temp.next.next;
            size--;
            return data;
        }
    }

    public void set(int data, int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else {
            Node temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp.next;
            }
            temp.data = data;
        }
    }

    public boolean contains(int data) {
        if (isEmpty()) {
            return false;
        } else {
            Node temp = head;
            do {
                if (temp.data == data) {
                    return true;
                }
                temp = temp.next;
            } while (temp != head);
            return false;
        }
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            return "null";
        }
        StringBuilder sb = new StringBuilder();
        Node temp = head;
        do {
            sb.append(temp.data).append(" -> ");
            temp = temp.next;
        } while (temp != head);
        sb.append("(head)");
        return sb.toString().trim();
    }
}

public class CSLL {
    public static void main(String[] args) {
        CircularSinglyLinkedList list = new CircularSinglyLinkedList();

        System.out.println("\n:: Intial List ::");
        System.out.println(list);

        System.out.println("\n:: Insert at Begin ::");
        list.insertAtBegin(30);
        list.insertAtBegin(20);
        list.insertAtBegin(10);
        System.out.println(list);
        System.out.println("Size: " + list.size());

        System.out.println("\n:: Insert at Specific ::");
        list.insertAtSpecific(25, 2);
        list.insertAtSpecific(5, 0);
        list.insertAtSpecific(35, list.size());
        System.out.println(list);
        System.out.println("Size: " + list.size());

        System.out.println("\n:: Insert at End ::");
        list.insertAtEnd(40);
        list.insertAtEnd(50);
        list.insertAtEnd(60);
        System.out.println(list);
        System.out.println("Size: " + list.size());
    }
}
