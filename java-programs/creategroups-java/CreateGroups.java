public class CreateGroups {

    public int minChanges(int[] groups, int minSize, int maxSize) {
        int adjustPositive = 0, adjustNegetive = 0, upperBound = 0, lowerBound = 0;
        for (int i = 0; i < groups.length; i++) {
            if (groups[i] >= minSize && groups[i] <= maxSize) {
                adjustPositive = adjustPositive + (groups[i] - minSize);
                adjustNegetive = adjustNegetive + (maxSize - groups[i]);
            } else if (groups[i] < minSize) {
                lowerBound = lowerBound + (minSize - groups[i]);
                adjustNegetive = adjustNegetive + (maxSize - minSize);

            } else if (groups[i] > maxSize) {
                upperBound = upperBound + (groups[i] - maxSize);
                adjustPositive = adjustPositive + (maxSize - minSize);

            }
        }
        System.out.println(adjustNegetive+" "+adjustPositive +" "+upperBound +" "+lowerBound);
        if(upperBound > lowerBound && (upperBound - lowerBound)>adjustNegetive)
            return -1;
        if(upperBound < lowerBound && (lowerBound - upperBound )>adjustPositive)
            return -1;
        
        return Math.max(upperBound, lowerBound);
    }

}
