import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class NextOrPrevTest {

    protected NextOrPrev solution;

    @Before
    public void setUp() {
        solution = new NextOrPrev();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int nextCost = 5;
        int prevCost = 8;
        String start = "ae";
        String goal = "bc";

        int expected = 21;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int nextCost = 5;
        int prevCost = 8;
        String start = "ae";
        String goal = "cb";

        int expected = -1;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int nextCost = 1;
        int prevCost = 1;
        String start = "srm";
        String goal = "srm";

        int expected = 0;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int nextCost = 10;
        int prevCost = 1;
        String start = "acb";
        String goal = "bdc";

        int expected = 30;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int nextCost = 10;
        int prevCost = 1;
        String start = "zyxw";
        String goal = "vuts";

        int expected = 16;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int nextCost = 563;
        int prevCost = 440;
        String start = "ptrbgcnlaizo";
        String goal = "rtscedkiahul";

        int expected = 10295;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase6() {
        int nextCost = 126;
        int prevCost = 311;
        String start = "yovlkwpjgsna";
        String goal = "zpwnkytjisob";

        int expected = -1;
        int actual = solution.getMinimum(nextCost, prevCost, start, goal);

        Assert.assertEquals(expected, actual);
    }

}
