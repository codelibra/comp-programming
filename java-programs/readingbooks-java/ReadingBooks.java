import java.time.chrono.MinguoChronology;

public class ReadingBooks {

    public int countBooks(String[] readParts) {
        int intro=0, edit=0, story =0, ans = 0;
        for (int i = 2; i < readParts.length; i++) {
            for (int j = 0; j <=2 ; j++) {
                if(readParts[i-j].compareTo("introduction")==0)
                    intro =1;
                else if (readParts[i-j].compareTo("story")==0) {
                    story =1;
                }
                else if (readParts[i-j].compareTo("edification")==0){
                    edit=1;
                }
            }
            if(intro==1 && edit==1 && story==1){
                ans++;
                i=i+2;
            }
            System.out.println(ans+" "+intro+" "+edit+" "+story);
            intro=0;
            edit =0;
            story=0;
        }
        return ans;
    }

}
