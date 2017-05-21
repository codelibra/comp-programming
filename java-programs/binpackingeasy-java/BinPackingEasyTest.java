import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BinPackingEasyTest {

    protected BinPackingEasy solution;

    @Before
    public void setUp() {
        solution = new BinPackingEasy();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] item = new int[]{150, 150, 150, 150, 150};

        int expected = 3;
        int actual = solution.minBins(item);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] item = new int[]{130, 140, 150, 160};

        int expected = 2;
        int actual = solution.minBins(item);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] item = new int[]{101, 101, 101, 101, 101, 101, 101, 101, 101};

        int expected = 5;
        int actual = solution.minBins(item);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] item = new int[]{101, 200, 101, 101, 101, 101, 200, 101, 200};

        int expected = 6;
        int actual = solution.minBins(item);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] item = new int[]{123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};

        int expected = 8;
        int actual = solution.minBins(item);

        Assert.assertEquals(expected, actual);
    }

}
