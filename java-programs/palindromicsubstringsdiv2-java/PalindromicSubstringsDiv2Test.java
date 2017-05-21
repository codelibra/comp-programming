import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class PalindromicSubstringsDiv2Test {

    protected PalindromicSubstringsDiv2 solution;

    @Before
    public void setUp() {
        solution = new PalindromicSubstringsDiv2();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String[] S1 = new String[]{"a", "a", ""};
        String[] S2 = new String[]{"a"};

        int expected = 6;
        int actual = solution.count(S1, S2);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String[] S1 = new String[]{"zaz"};
        String[] S2 = new String[]{};

        int expected = 4;
        int actual = solution.count(S1, S2);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String[] S1 = new String[]{"top"};
        String[] S2 = new String[]{"coder"};

        int expected = 8;
        int actual = solution.count(S1, S2);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String[] S1 = new String[]{};
        String[] S2 = new String[]{"daata"};

        int expected = 7;
        int actual = solution.count(S1, S2);

        Assert.assertEquals(expected, actual);
    }

}
