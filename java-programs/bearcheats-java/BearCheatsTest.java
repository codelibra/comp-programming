import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BearCheatsTest {

    protected BearCheats solution;

    @Before
    public void setUp() {
        solution = new BearCheats();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int A = 8072;
        int B = 3072;

        String expected = "happy";
        String actual = solution.eyesight(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int A = 508;
        int B = 540;

        String expected = "glasses";
        String actual = solution.eyesight(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int A = 854000;
        int B = 854000;

        String expected = "happy";
        String actual = solution.eyesight(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int A = 1;
        int B = 6;

        String expected = "happy";
        String actual = solution.eyesight(A, B);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int A = 385900;
        int B = 123000;

        String expected = "glasses";
        String actual = solution.eyesight(A, B);

        Assert.assertEquals(expected, actual);
    }

}
