import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ColorfulRoadTest {

    protected ColorfulRoad solution;

    @Before
    public void setUp() {
        solution = new ColorfulRoad();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String road = "RGBGBRRRB";

        int expected = 34;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String road = "RGBRGBRGB";

        int expected = 8;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String road = "RBBGGGRR";

        int expected = -1;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String road = "RBRRBGGGBBBBR";

        int expected = 50;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String road = "RG";

        int expected = 1;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        String road = "RBRGBGBGGBGRGGG";

        int expected = 52;
        int actual = solution.getMin(road);

        Assert.assertEquals(expected, actual);
    }

}
