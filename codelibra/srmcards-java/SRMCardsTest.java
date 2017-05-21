import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class SRMCardsTest {

    protected SRMCards solution;

    @Before
    public void setUp() {
        solution = new SRMCards();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] cards = new int[]{498, 499};

        int expected = 1;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] cards = new int[]{491, 492, 495, 497, 498, 499};

        int expected = 4;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] cards = new int[]{100, 200, 300, 400};

        int expected = 4;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] cards = new int[]{11, 12, 102, 13, 100, 101, 99, 9, 8, 1};

        int expected = 6;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] cards = new int[]{118, 321, 322, 119, 120, 320};

        int expected = 4;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int[] cards = new int[]{10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int expected = 7;
        int actual = solution.maxTurns(cards);

        Assert.assertEquals(expected, actual);
    }

}
