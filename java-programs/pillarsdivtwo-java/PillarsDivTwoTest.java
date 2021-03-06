import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class PillarsDivTwoTest {

    protected PillarsDivTwo solution;

    @Before
    public void setUp() {
        solution = new PillarsDivTwo();
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
        int[] height = new int[] { 3, 3, 3 };
        int w = 2;

        double expected = 5.656854249492381;
        double actual = solution.maximalLength(height, w);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] height = new int[] { 1, 50, 20, 57, 99, 4, 25, 9, 45, 10, 90, 3, 96, 86, 94, 44, 24, 88, 15, 4, 49, 1,
                59, 19, 81, 97, 99, 82, 90, 99, 10, 58, 73, 23, 39, 93, 39, 80, 91, 58, 59, 92, 16, 89, 57, 12, 3, 35,
                73, 56 };
        int w = 29;

        double expected = 3524.900000318473;
        double actual = solution.maximalLength(height, w);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] height = new int[] { 100, 2, 100, 2, 100 };
        int w = 4;

        double expected = 396.32310051270036;
        double actual = solution.maximalLength(height, w);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] height = new int[] { 2, 1, 1, 2 };
        int w = 1;

        double expected = 3.82842712474619;
        double actual = solution.maximalLength(height, w);

        assertEquals(expected, actual);
    }

}
