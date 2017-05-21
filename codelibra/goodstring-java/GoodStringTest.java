import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class GoodStringTest {

    protected GoodString solution;

    @Before
    public void setUp() {
        solution = new GoodString();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String s = "ab";

        String expected = "Good";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String s = "aab";

        String expected = "Bad";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String s = "aabb";

        String expected = "Good";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String s = "ababab";

        String expected = "Good";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String s = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb";

        String expected = "Bad";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        String s = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";

        String expected = "Good";
        String actual = solution.isGood(s);

        Assert.assertEquals(expected, actual);
    }

}
