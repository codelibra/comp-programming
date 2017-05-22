import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class PointDistanceTest {

    protected PointDistance solution;

    @Before
    public void setUp() {
        solution = new PointDistance();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int x1 = -1;
        int y1 = 0;
        int x2 = 1;
        int y2 = 0;

        int[] expected = new int[]{8, 48};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int x1 = 1;
        int y1 = 1;
        int x2 = -1;
        int y2 = -1;

        int[] expected = new int[]{25, -63};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int x1 = 0;
        int y1 = 1;
        int x2 = 2;
        int y2 = 3;

        int[] expected = new int[]{41, 65};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int x1 = 5;
        int y1 = -4;
        int x2 = -2;
        int y2 = 5;

        int[] expected = new int[]{68, 70};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int x1 = -50;
        int y1 = -50;
        int x2 = 50;
        int y2 = -50;

        int[] expected = new int[]{67, 4};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int x1 = -50;
        int y1 = 50;
        int x2 = -49;
        int y2 = 49;

        int[] expected = new int[]{73, -25};
        int[] actual = solution.findPoint(x1, y1, x2, y2);

        Assert.assertArrayEquals(expected, actual);
    }

}
