import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class SortMachineTest {

    protected SortMachine solution;

    @Before
    public void setUp() {
        solution = new SortMachine();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] a = new int[]{19, 7, 8, 25};

        int expected = 2;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] a = new int[]{1, 2, 3, 4, 5};

        int expected = 0;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] a = new int[]{1000, -1000, 0};

        int expected = 1;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] a = new int[]{1, 3, 4, 5, 6, 7, 8, 9, 2};

        int expected = 7;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] a = new int[]{-2, -8, 9, 0};

        int expected = 3;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int[] a = new int[]{976, -946, -824, 680, -644, -95, 128, -892, 816, -263, -592, -669, 887, 447, -653, -759, 572, 171, 635, 98, -904, 78, 143, -416, -40, -846, 784, -702, -738, -858, 582, 603, -535, 529, 84, -964, 934, 36, 783};

        int expected = 38;
        int actual = solution.countMoves(a);

        Assert.assertEquals(expected, actual);
    }

}
