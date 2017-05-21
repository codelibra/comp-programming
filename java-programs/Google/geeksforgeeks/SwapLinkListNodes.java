import standardAlgos.SinglyLinkList;


public class SwapLinkListNodes extends SinglyLinkList{

    public static SinglyLinkList swapNode(int a, int b, SinglyLinkList ll) {
        
        SinglyLinkList.Node head = ll.getHead();
        SinglyLinkList.Node temp = ll.getHead();
        
        SinglyLinkList.Node prevN1 = null;
        SinglyLinkList.Node prevN2 = null;
        SinglyLinkList.Node nextN1 = null;
        SinglyLinkList.Node prev = null;
        SinglyLinkList.Node N1 = null;
        SinglyLinkList.Node N2 = null;   
        
        while(temp!=null){
            
         if(temp.getData()==a){
             prevN1 = prev;
             N1=temp;
             nextN1 = N1.getNext();
         }
         if(temp.getData()==b){
             prevN2 = prev;
             N2=temp;
         }
         prev = temp;
         temp = temp.getNext();
        }
        
        if(N1==null || N2==null)
            return null;
        
        if(N1==head)
            ll.setHead(N2);
        // Adjacent 
        if(N1.getNext() == N2){
            prevN1.setNext(N2);
            N2.setNext(N1);
            N1.setNext(nextN1);
        }
        else{
            prevN1.setNext(N2);
            prevN2.setNext(N1);
            N1.setNext(N2.getNext());
            N2.setNext(nextN1);
        }
        
        return ll;
    }
    public static void main(String[] args) {
        SinglyLinkList singlyLinkList = new SinglyLinkList();
        singlyLinkList.addNode(10);
        singlyLinkList.addNode(15);
        singlyLinkList.addNode(12);
        singlyLinkList.addNode(13);
        singlyLinkList.addNode(20);
        singlyLinkList.addNode(14);
        singlyLinkList = swapNode(12 , 13, singlyLinkList);
        singlyLinkList.printList();
    }

}
