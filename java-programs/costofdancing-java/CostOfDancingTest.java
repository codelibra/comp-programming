import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CostOfDancingTest {

    protected CostOfDancing solution;

    @Before
    public void setUp() {
        solution = new CostOfDancing();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int K = 2;
        int[] danceCost = new int[]{1, 5, 3, 4};

        int expected = 4;
        int actual = solution.minimum(K, danceCost);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int K = 3;
        int[] danceCost = new int[]{1, 5, 4};

        int expected = 10;
        int actual = solution.minimum(K, danceCost);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int K = 1;
        int[] danceCost = new int[]{2, 2, 4, 5, 3};

        int expected = 2;
        int actual = solution.minimum(K, danceCost);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int K = 39;
        int[] danceCost = new int[]{973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932, 703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};

        int expected = 20431;
        int actual = solution.minimum(K, danceCost);

        Assert.assertEquals(expected, actual);
    }

}
