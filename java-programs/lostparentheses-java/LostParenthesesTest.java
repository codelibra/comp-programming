import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class LostParenthesesTest {

    protected LostParentheses solution;

    @Before
    public void setUp() {
        solution = new LostParentheses();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String e = "55-50+40";

        int expected = -35;
        int actual = solution.minResult(e);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String e = "10+20+30+40";

        int expected = 100;
        int actual = solution.minResult(e);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String e = "00009-00009";

        int expected = 0;
        int actual = solution.minResult(e);

        Assert.assertEquals(expected, actual);
    }

}
