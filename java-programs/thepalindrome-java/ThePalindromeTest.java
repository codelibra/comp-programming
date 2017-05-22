import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ThePalindromeTest {

    protected ThePalindrome solution;

    @Before
    public void setUp() {
        solution = new ThePalindrome();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String s = "aaaabbaaaaa";

        int expected = 17;
        int actual = solution.find(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String s = "abacaba";

        int expected = 7;
        int actual = solution.find(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String s = "qwerty";

        int expected = 11;
        int actual = solution.find(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String s = "abdfhdyrbdbsdfghjkllkjhgfds";

        int expected = 38;
        int actual = solution.find(s);

        Assert.assertEquals(expected, actual);
    }

}
