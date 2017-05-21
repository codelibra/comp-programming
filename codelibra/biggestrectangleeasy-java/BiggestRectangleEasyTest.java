import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BiggestRectangleEasyTest {

    protected BiggestRectangleEasy solution;

    @Before
    public void setUp() {
        solution = new BiggestRectangleEasy();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int N = 11;

        int expected = 6;
        int actual = solution.findArea(N);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int N = 5;

        int expected = 1;
        int actual = solution.findArea(N);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int N = 64;

        int expected = 256;
        int actual = solution.findArea(N);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int N = 753;

        int expected = 35344;
        int actual = solution.findArea(N);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int N = 7254;

        int expected = 3288782;
        int actual = solution.findArea(N);

        Assert.assertEquals(expected, actual);
    }

}
