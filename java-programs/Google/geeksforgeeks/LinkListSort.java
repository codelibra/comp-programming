import standardAlgos.SinglyLinkList;

/**
 * http://www.geeksforgeeks.org/how-to-sort-a-linked-list-that-is-sorted-alternating-ascending-and-descending-orders/
 * @author shiv
 *
 */
public class LinkListSort extends SinglyLinkList{

    public static SinglyLinkList sortedLinkList(SinglyLinkList ll) {
        SinglyLinkList ans = new SinglyLinkList();
        SinglyLinkList a = new SinglyLinkList();
        SinglyLinkList b = new SinglyLinkList();
        // two pointers
        // break the ll into two parts 
        // merge the ll
        SinglyLinkList.Node head1 = ll.getHead();
        SinglyLinkList.Node head2 = head1.getNext();
        
        a.addNode(head1.getData());
        while(head1!=null && head2!=null){
            if(head2!=null){
                b.addNode(head2.getData());
                head1.setNext(head2.getNext());
                head1 = head1.getNext();
            }
            if(head1!=null){
                a.addNode(head1.getData());
                head2.setNext(head1.getNext());
                head2 = head2.getNext();
            }
        }
        b = b.reverse();
        SinglyLinkList.Node head3 = a.getHead();
        SinglyLinkList.Node head4 = b.getHead();
        
        while(head3!=null || head4!=null){
            if(head3==null){
                ans.addNode(head4.getData());
                head4 = head4.getNext();
            }
            else if (head4==null) {
                ans.addNode(head3.getData());
                head3=head3.getNext();
            }
            else if (head3.getData() > head4.getData()) {
                ans.addNode(head4.getData());
                head4 = head4.getNext();
            }
            else{
                ans.addNode(head3.getData());
                head3=head3.getNext();
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        //0->40->53->30->67->12->89->NULL
        SinglyLinkList singlyLinkList = new SinglyLinkList();
        singlyLinkList.addNode(0);
        singlyLinkList.addNode(40);
        singlyLinkList.addNode(53);
        singlyLinkList.addNode(30);
        singlyLinkList.addNode(67);
        singlyLinkList.addNode(12);
        singlyLinkList.addNode(89);        
        //singlyLinkList.printList();
        singlyLinkList = LinkListSort.sortedLinkList(singlyLinkList);
        singlyLinkList.printList();
    }

}
