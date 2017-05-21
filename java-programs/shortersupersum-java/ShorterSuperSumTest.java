import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ShorterSuperSumTest {

    protected ShorterSuperSum solution;

    @Before
    public void setUp() {
        solution = new ShorterSuperSum();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int k = 1;
        int n = 3;

        int expected = 6;
        int actual = solution.calculate(k, n);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int k = 2;
        int n = 3;

        int expected = 10;
        int actual = solution.calculate(k, n);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int k = 4;
        int n = 10;

        int expected = 2002;
        int actual = solution.calculate(k, n);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int k = 10;
        int n = 10;

        int expected = 167960;
        int actual = solution.calculate(k, n);

        Assert.assertEquals(expected, actual);
    }

}
