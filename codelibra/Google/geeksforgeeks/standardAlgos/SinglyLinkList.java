/**
 * @author panicker
 */
package standardAlgos;

public class SinglyLinkList {

    private Node head;

    public class Node {
        private int data;
        private Node nextNode;

        Node(int d, Node next) {
            data = d;
            nextNode = next;
        }

        public void print() {
            System.out.print(data+" ");
        }
        
        public Node getNext() {
            return nextNode;
        }
        
        public int getData() {
            return data;
        }
        
        public void setNext(Node n) {
            nextNode = n;
        }
        
        public void setData(int d) {
            data = d;
        }
    }
        
    public Node addNode(int x) {
        if(head == null){
            head = new Node(x, null);
        }
        else{
            Node temp = new Node(x, null);
            temp.nextNode = head;
            head = temp;
        }
        return head;
    }
        
    public Node deleteHead(){
        Node temp = head;
        head = head.nextNode;
        return temp;
    }
        
    public void printList() {
        Node temp = head;
        while(temp!=null){
            temp.print();
            temp = temp.nextNode; 
        }
        System.out.println();
    }
    
    public SinglyLinkList() {
        head = null;
    }
    
    public Node getHead() {
        return head;
    }
    
    public void setHead(Node h) {
        head = h;
    }
    
    public SinglyLinkList reverse() {
        SinglyLinkList rev = new SinglyLinkList();
        Node temp = head;
        while(temp!=null){
            rev.addNode(temp.getData());
            temp = temp.nextNode;
        }
        return rev;
    }
      
    public static void main(String[] args) {
        SinglyLinkList ll = new SinglyLinkList();
        ll.addNode(5);
        ll.addNode(6);
        ll.printList();
    }

}
