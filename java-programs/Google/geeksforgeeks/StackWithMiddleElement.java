import standardAlgos.SinglyLinkList;


public class StackWithMiddleElement {

    private static SinglyLinkList stackLinkList;
    private static SinglyLinkList.Node middle;
    
    
    
    public static void main(String[] args) {
        stackLinkList = new SinglyLinkList();
        stackLinkList.addNode(1);
        stackLinkList.addNode(2);
        stackLinkList.addNode(3);
        stackLinkList.printList();

    }

}
