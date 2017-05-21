import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class GearsDiv2Test {

    protected GearsDiv2 solution;

    @Before
    public void setUp() {
        solution = new GearsDiv2();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String Directions = "LRRR";

        int expected = 1;
        int actual = solution.getmin(Directions);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String Directions = "LLRLRLRRRLLRRL";

        int expected = 4;
        int actual = solution.getmin(Directions);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String Directions = "LRLR";

        int expected = 0;
        int actual = solution.getmin(Directions);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String Directions = "LRLLRRLLLRRRLLLL";

        int expected = 6;
        int actual = solution.getmin(Directions);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String Directions = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";

        int expected = 14;
        int actual = solution.getmin(Directions);

        Assert.assertEquals(expected, actual);
    }

}
