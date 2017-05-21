/**
 * @author shiv
 */
import standardAlgos.SinglyLinkList;

public class MergeSortLinkLists {

    public static void divideLinkList(SinglyLinkList ll, SinglyLinkList firstPart, SinglyLinkList secondPart) {
        // divide the link lists into two parts
        // return the two parts
        // not use any extra space in the separations
        SinglyLinkList.Node headNode = ll.getHead();
        if (headNode == null || headNode.getNext() == null) {
            firstPart.setHead(ll.getHead());
            secondPart.setHead(null);
        }

        SinglyLinkList.Node tortise = ll.getHead();
        SinglyLinkList.Node rabbit = ll.getHead();
        if (rabbit != null)
            rabbit = rabbit.getNext();

        while (rabbit != null) {
            rabbit = rabbit.getNext();
            if (rabbit != null) {
                tortise = tortise.getNext();
                rabbit = rabbit.getNext();
            }
        }

        firstPart.setHead(ll.getHead());
        secondPart.setHead(tortise.getNext());
        tortise.setNext(null);
    }

    public static SinglyLinkList.Node sortedMerge(SinglyLinkList ll1, SinglyLinkList ll2) {
        // Given the link list, requirement is to return the new link list which 
        // is completely sorted
        SinglyLinkList.Node head1 = ll1.getHead();
        SinglyLinkList.Node head2 = ll2.getHead();
        SinglyLinkList.Node head3 = null;
        SinglyLinkList.Node temp = null;

        if (head1 == null){
            return ll2.getHead();
        }
        if (head2 == null){
            return ll1.getHead();
        }

        while (head1 != null || head2 != null) {
            if (head1 == null) {
                temp.setNext(head2);
                temp = temp.getNext();
                head2 = head2.getNext();
            }

            else if (head2 == null) {
                temp.setNext(head1);
                temp = temp.getNext();
                head1 = head1.getNext();
            }

            else if (head1.getData() >= head2.getData()) {
                if (head3 == null) {
                    head3 = head1;
                    temp = head1;
                } else {
                    temp.setNext(head1);
                    temp = temp.getNext();
                }
                head1 = head1.getNext();
            } else {
                if (head3 == null) {
                    head3 = head2;
                    temp = head2;
                } else {
                    temp.setNext(head2);
                    temp = temp.getNext();
                }
                head2 = head2.getNext();
            }
        }
        temp.setNext(null);
        return head3;
    }

    public static void mergeSort(SinglyLinkList ll) {
        // divide the ll into parts and call mergesort on indivisual pieces
        SinglyLinkList.Node head = ll.getHead();
        SinglyLinkList aLinkList = new SinglyLinkList();
        SinglyLinkList bLinkList = new SinglyLinkList();

        if (head == null || head.getNext() == null) {
            return;
        }

        divideLinkList(ll, aLinkList, bLinkList);
        mergeSort(aLinkList);
        mergeSort(bLinkList);
        ll.setHead(sortedMerge(aLinkList, bLinkList));
    }

    public static void main(String[] args) {
        // created a new link list with the given elements
        SinglyLinkList ll = new SinglyLinkList();
        ll.addNode(2);
        ll.addNode(10);
        ll.addNode(3);
        ll.addNode(50);
        ll.addNode(45);
        ll.addNode(1);
        ll.addNode(91);
        ll.addNode(10);
        ll.addNode(25);
        ll.addNode(5);
        ll.addNode(34);
        ll.addNode(9);
        System.out.println("The orignal link list :");
        ll.printList();
        mergeSort(ll);
        System.out.println("The sorted link list is");
        ll.printList();
    }

}
