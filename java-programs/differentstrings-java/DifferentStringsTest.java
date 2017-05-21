import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class DifferentStringsTest {

    protected DifferentStrings solution;

    @Before
    public void setUp() {
        solution = new DifferentStrings();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String A = "koder";
        String B = "topcoder";

        int expected = 1;
        int actual = solution.minimize(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String A = "hello";
        String B = "xello";

        int expected = 1;
        int actual = solution.minimize(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String A = "abc";
        String B = "topabcoder";

        int expected = 0;
        int actual = solution.minimize(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String A = "adaabc";
        String B = "aababbc";

        int expected = 2;
        int actual = solution.minimize(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String A = "giorgi";
        String B = "igroig";

        int expected = 6;
        int actual = solution.minimize(A, B);

        Assert.assertEquals(expected, actual);
    }

}
