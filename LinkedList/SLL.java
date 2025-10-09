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

class LinkedList {
    Node head;

    LinkedList() {
        this.head = null;
    }

    LinkedList(Node head) {
        this.head = head;
    }

    public int size() {
        int count = 0;
        Node temp = head;

        while (temp != null) {
            count++;
            temp = temp.next;
        }

        return count;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int get(int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size()) {
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

        if (head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void insertAtSpecific(int data, int pos) {
        int size = size();
        if (pos < 0) {
            throw new IndexOutOfBoundsException("Position cannot be negative");
        } else if (pos > size) {
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
        }
    }

    public int deleteFromBegin() {
        if (head == null) {
            throw new NoSuchElementException("List is empty");
        }
        int data = head.data;
        head = head.next;
        return data;
    }

    public int deleteFromEnd() {
        if (head == null) {
            throw new NoSuchElementException("List is empty");
        }

        if (head.next == null) {
            int data = head.data;
            head = null;
            return data;
        }

        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        int data = temp.next.data;
        temp.next = null;
        return data;
    }

    public int deleteFromSpecific(int pos) {
        if (head == null) {
            throw new NoSuchElementException("List is empty");
        }

        int size = size();
        if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else if (pos == 0) {
            return deleteFromBegin();
        } else if (pos == size - 1) {
            return deleteFromEnd();
        } else {
            Node temp = head;

            for (int i = 0; i < pos - 1; i++) {
                temp = temp.next;
            }

            int data = temp.next.data;
            temp.next = temp.next.next;
            return data;
        }
    }

    public void set(int data, int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size()) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else {
            Node temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp.next;
            }
            temp.data = data;
        }
    }

    public boolean contains(int key) {
        Node temp = head;

        while (temp != null) {
            if (temp.data == key) {
                return true;
            }
            temp = temp.next;
        }

        return false;
    }

    public void reverse() {
        Node prev = null;
        Node curr = head;
        Node next = null;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node temp = head;
        while (temp != null) {
            sb.append(temp.data).append(" -> ");
            temp = temp.next;
        }
        sb.append("null");
        return sb.toString().trim();
    }
}

public class SLL {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        System.out.println("\n:: Intial List ::");
        System.out.println(list);

        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        System.out.println("\n:: List After Insertions (Insert At End) ::");
        System.out.println(list);

        list.insertAtBegin(3);
        list.insertAtBegin(2);
        list.insertAtBegin(1);
        System.out.println("\n:: List After Insertions (Insert At Begin) ::");
        System.out.println(list);

        list.insertAtSpecific(15, 0);
        list.insertAtSpecific(25, 4);
        list.insertAtSpecific(35, list.size());
        System.out.println("\n:: List After Insertions (Insert At Specific Positions) ::");
        System.out.println(list);

        System.out.println("\n:: List After Deletions (Delete From Specific Positions) ::");
        System.out.println(list.deleteFromSpecific(0));
        System.out.println(list.deleteFromSpecific(3));
        System.out.println(list.deleteFromSpecific(list.size() - 1));
        System.out.println(list);

        System.out.println("\n:: List After Deletions (Delete From Begin and End) ::");
        System.out.println(list.deleteFromBegin());
        System.out.println(list.deleteFromEnd());
        System.out.println(list);

        System.out.println("\n:: List Information ::");
        System.out.println("Size: " + list.size());
        System.out.println("Contains 20? : " + list.contains(20));
        System.out.println("Contains 40? : " + list.contains(40));

        System.out.println("Element at index 0: " + list.get(0));
        System.out.println("Element at index 2: " + list.get(2));

        System.out.println("\n:: List After Set Operation ::");
        list.set(100, 0);
        list.set(300, 2);
        System.out.println(list);

        System.out.println("\n:: List After Reversing ::");
        list.reverse();
        System.out.println(list);
    }
}
