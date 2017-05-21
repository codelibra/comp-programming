import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class RedAndGreenTest {

    protected RedAndGreen solution;

    @Before
    public void setUp() {
        solution = new RedAndGreen();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String row = "RGRGR";

        int expected = 2;
        int actual = solution.minPaints(row);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String row = "RRRGGGGG";

        int expected = 0;
        int actual = solution.minPaints(row);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String row = "GGGGRRR";

        int expected = 3;
        int actual = solution.minPaints(row);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String row = "RGRGRGRGRGRGRGRGR";

        int expected = 8;
        int actual = solution.minPaints(row);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String row = "RRRGGGRGGGRGGRRRGGRRRGR";

        int expected = 9;
        int actual = solution.minPaints(row);

        Assert.assertEquals(expected, actual);
    }

}
