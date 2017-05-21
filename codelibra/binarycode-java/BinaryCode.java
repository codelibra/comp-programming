public class BinaryCode {

    public String decodeString(int zero, String message) {
        if (message.length() == 1) {
            if (Character.getNumericValue(message.charAt(0)) < 2)
                return message;
            else {
                return "NONE";
            }
        }
        String ansString = Integer.toString(zero);

        int mprev = zero, ansprev = 0, anspprev = 0;
        for (int i = 1; i < message.length(); i++) {
            if (i - 1 >= 0) {
                mprev = Character.getNumericValue(message.charAt(i - 1));
                ansprev = Character.getNumericValue(ansString.charAt(i - 1));
            } else {
                mprev = 0;
                ansprev = 0;
            }
            if (i - 2 >= 0) {
                anspprev = Character.getNumericValue(ansString.charAt(i - 2));
            } else {
                anspprev = 0;
            }
            int ans = mprev - anspprev - ansprev;
            ansString = ansString + Integer.toString(ans);
        }

        for (int i = 0; i < ansString.length(); i++) {
            if (ansString.charAt(i) == '-' || Character.getNumericValue(ansString.charAt(i)) > 1)
                return "NONE";
        }
        return ansString;
    }

    public String[] decode(String message) {
        String anString[] = new String[2];
        anString[0] = decodeString(0, message);
        anString[1] = decodeString(1, message);
        return anString;
    }
}
