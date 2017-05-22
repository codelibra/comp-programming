import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ShopPositionsTest {

    protected ShopPositions solution;

    @Before
    public void setUp() {
        solution = new ShopPositions();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int n = 1;
        int m = 5;
        int[] c = new int[]{100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1};

        int expected = 300;
        int actual = solution.maxProfit(n, m, c);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int n = 1;
        int m = 5;
        int[] c = new int[]{1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        int expected = 1000;
        int actual = solution.maxProfit(n, m, c);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int n = 3;
        int m = 1;
        int[] c = new int[]{7, 6, 1, 10, 4, 1, 7, 6, 3};

        int expected = 14;
        int actual = solution.maxProfit(n, m, c);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int n = 2;
        int m = 2;
        int[] c = new int[]{12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        int expected = 24;
        int actual = solution.maxProfit(n, m, c);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int n = 3;
        int m = 3;
        int[] c = new int[]{30, 28, 25, 15, 14, 10, 5, 4, 2, 50, 40, 30, 28, 17, 13, 8, 6, 3, 45, 26, 14, 14, 13, 13, 2, 1, 1};

        int expected = 127;
        int actual = solution.maxProfit(n, m, c);

        Assert.assertEquals(expected, actual);
    }

}
