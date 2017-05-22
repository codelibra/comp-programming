public class GoodString {

    public String rebuild(String s) {
        int i = 0;
        String str = "";
        boolean found = false;
        for (; i < s.length() - 1; ++i) {
            if (s.charAt(i) == 'a' && s.charAt(i + 1) == 'b') {
                found = true;
                break;
            } else {
                str = str + s.charAt(i);
            }
        }
        if (!found)
            return "X";

        i = i + 2;
        while (i < s.length()) {
            str = str + s.charAt(i);
            ++i;
        }
        return str;

    }

    public String isGood(String s) {

        while (true) {
            s = rebuild(s);
            if (s.length() == 0)
                break;

            if (s.charAt(0) == 'X')
                return "Bad";
        }
        return "Good";
    }

}
