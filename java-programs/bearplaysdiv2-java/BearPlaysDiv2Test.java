import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BearPlaysDiv2Test {

    protected BearPlaysDiv2 solution;

    @Before
    public void setUp() {
        solution = new BearPlaysDiv2();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int A = 25;
        int B = 6;
        int C = 17;

        String expected = "possible";
        String actual = solution.equalPiles(A, B, C);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int A = 1;
        int B = 1;
        int C = 2;

        String expected = "impossible";
        String actual = solution.equalPiles(A, B, C);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int A = 4;
        int B = 6;
        int C = 8;

        String expected = "impossible";
        String actual = solution.equalPiles(A, B, C);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int A = 18;
        int B = 18;
        int C = 18;

        String expected = "possible";
        String actual = solution.equalPiles(A, B, C);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int A = 225;
        int B = 500;
        int C = 475;

        String expected = "possible";
        String actual = solution.equalPiles(A, B, C);

        Assert.assertEquals(expected, actual);
    }

}
