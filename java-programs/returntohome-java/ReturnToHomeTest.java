import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ReturnToHomeTest {

    protected ReturnToHome solution;

    @Before
    public void setUp() {
        solution = new ReturnToHome();
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
        int X = 6;
        int Y = 8;
        int D = 5;
        int T = 3;

        double expected = 6.0;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int X = 3;
        int Y = 4;
        int D = 6;
        int T = 3;

        double expected = 4.0;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int X = 400;
        int Y = 300;
        int D = 150;
        int T = 10;

        double expected = 40.0;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int X = 318;
        int Y = 445;
        int D = 1200;
        int T = 800;

        double expected = 546.9451526432975;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int X = 6;
        int Y = 8;
        int D = 3;
        int T = 2;

        double expected = 7.0;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int X = 10;
        int Y = 10;
        int D = 1000;
        int T = 5;

        double expected = 10.0;
        double actual = solution.goHome(X, Y, D, T);

        assertEquals(expected, actual);
    }

}
