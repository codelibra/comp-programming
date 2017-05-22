import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class IncrementingSequenceTest {

    protected IncrementingSequence solution;

    @Before
    public void setUp() {
        solution = new IncrementingSequence();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int k = 3;
        int[] A = new int[]{1, 2, 4, 3};

        String expected = "POSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int k = 5;
        int[] A = new int[]{2, 2};

        String expected = "IMPOSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int k = 1;
        int[] A = new int[]{1, 1, 1, 1, 1, 1, 1, 1};

        String expected = "POSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int k = 2;
        int[] A = new int[]{5, 3, 3, 2, 1};

        String expected = "IMPOSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int k = 9;
        int[] A = new int[]{1, 2, 3, 1, 4, 5, 6, 7, 9, 8};

        String expected = "POSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int k = 2;
        int[] A = new int[]{1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

        String expected = "POSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase6() {
        int k = 1;
        int[] A = new int[]{1};

        String expected = "POSSIBLE";
        String actual = solution.canItBeDone(k, A);

        Assert.assertEquals(expected, actual);
    }

}
