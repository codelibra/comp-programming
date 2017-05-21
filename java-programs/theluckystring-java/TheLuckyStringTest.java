import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TheLuckyStringTest {

    protected TheLuckyString solution;

    @Before
    public void setUp() {
        solution = new TheLuckyString();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String s = "ab";

        int expected = 2;
        int actual = solution.count(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String s = "aaab";

        int expected = 0;
        int actual = solution.count(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String s = "aabbbaa";

        int expected = 1;
        int actual = solution.count(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String s = "abcdefghij";

        int expected = 3628800;
        int actual = solution.count(s);

        Assert.assertEquals(expected, actual);
    }

}
