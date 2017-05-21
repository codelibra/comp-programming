import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BearSortsDiv2Test {

    protected BearSortsDiv2 solution;

    @Before
    public void setUp() {
        solution = new BearSortsDiv2();
    }

    public static void assertEquals(double expected, double actual) {
        if (Double.isNaN(expected)) {
            Assert.assertTrue("expected: <NaN> but was: <" + actual + ">", Double.isNaN(actual));
            return;
        }
        double delta = Math.max(1e-9, 1e-9 * Math.abs(expected));
        Assert.assertEquals(expected, actual, delta);
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] seq = new int[]{1, 2};

        double expected = -0.6931471805599453;
        double actual = solution.getProbability(seq);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] seq = new int[]{1, 3, 2};

        double expected = -1.3862943611198906;
        double actual = solution.getProbability(seq);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] seq = new int[]{10, 13, 18, 2, 4, 6, 24, 22, 19, 5, 7, 20, 23, 14, 21, 17, 25, 3, 1, 11, 12, 8, 15, 16, 9};

        double expected = -57.53121598647546;
        double actual = solution.getProbability(seq);

        assertEquals(expected, actual);
    }

}
