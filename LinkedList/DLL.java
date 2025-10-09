import java.util.NoSuchElementException;

class Node {
    int data;
    Node prev, next;

    Node(int data) {
        this.prev = null;
        this.data = data;
        this.next = null;
    }

    Node(int data, Node prev, Node next) {
        this.prev = prev;
        this.data = data;
        this.next = next;
    }
}

class LinkedList {
    Node head;
    int size;

    LinkedList() {
        this.head = null;
        this.size = 0;
    }

    LinkedList(Node head) {
        this.head = head;
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
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
        size++;
    }

    public void insertAtSpecific(int data, int pos) {
        if (pos < 0 || pos > size) {
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
            newNode.prev = temp;
            newNode.next = temp.next;
            temp.next.prev = newNode;
            temp.next = newNode;
            size++;
        }
    }

    public int deleteFromBegin() {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (head.next == null) {
            int data = head.data;
            head = null;
            size--;
            return data;
        } else {
            int data = head.data;
            head = head.next;
            head.prev = null;
            size--;
            return data;
        }
    }

    public int deleteFromEnd() {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (head.next == null) {
            int data = head.data;
            head = null;
            size--;
            return data;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            int data = temp.data;
            temp.prev.next = null;
            size--;
            return data;
        }
    }

    public int deleteFromSpecific(int pos) {
        if (isEmpty()) {
            throw new NoSuchElementException("List is empty");
        } else if (pos < 0 || pos >= size) {
            throw new IndexOutOfBoundsException("Position out of bounds");
        } else if (pos == 0) {
            return deleteFromBegin();
        } else if (pos == size - 1) {
            return deleteFromEnd();
        } else {
            Node temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp.next;
            }
            int data = temp.data;
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;
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

    public boolean contains(int key) {
        if (isEmpty()) {
            return false;
        } else {
            Node temp = head;
            while (temp != null) {
                if (temp.data == key) {
                    return true;
                }
                temp = temp.next;
            }
            return false;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node temp = head;
        while (temp != null) {
            sb.append(temp.data).append(" <-> ");
            temp = temp.next;
        }
        sb.append("null");
        return sb.toString().trim();
    }
}

public class DLL {
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

        System.out.println("\n:: List After Deletions (Delete From Begin, End, Specific Positions) ::");
        System.out.println(list.deleteFromBegin());
        System.out.println(list.deleteFromEnd());
        System.out.println(list.deleteFromSpecific(3));
        System.out.println(list);

        list.set(50, 2);
        System.out.println("\n:: List After Set Operation ::");
        System.out.println(list);

        System.out.println("\n:: Contains Check ::");
        System.out.println("Contains 20: " + list.contains(20));
        System.out.println("Contains 40: " + list.contains(40));

        System.out.println("\n:: Get Elements at Specific Positions ::");
        System.out.println("Element at index 0: " + list.get(0));
        System.out.println("Element at index 2: " + list.get(2));

        System.out.println("\n:: Final List ::");
        System.out.println(list);
    }
}
