public class BearCheats {

	public String eyesight(int A, int B) {
	    String aString = Integer.toString(A);
	    String bString = Integer.toString(B);
	    if(aString.length()!=bString.length())
	        return "glasses";
	    
	    int mismatches = 0;
	    for (int i = 0; i < aString.length(); i++) {
            if(aString.charAt(i)!=bString.charAt(i))
                mismatches++;
        }
	    if(mismatches>1)
	        return "glasses";
		return "happy";
	}

}
