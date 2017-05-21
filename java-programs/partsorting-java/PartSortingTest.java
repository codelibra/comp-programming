import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class PartSortingTest {

    protected PartSorting solution;

    @Before
    public void setUp() {
        solution = new PartSorting();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] data = new int[]{10, 20, 30, 40, 50, 60, 70};
        int nSwaps = 1;

        int[] expected = new int[]{20, 10, 30, 40, 50, 60, 70};
        int[] actual = solution.process(data, nSwaps);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] data = new int[]{3, 5, 1, 2, 4};
        int nSwaps = 2;

        int[] expected = new int[]{5, 3, 2, 1, 4};
        int[] actual = solution.process(data, nSwaps);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] data = new int[]{19, 20, 17, 18, 15, 16, 13, 14, 11, 12};
        int nSwaps = 5;

        int[] expected = new int[]{20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
        int[] actual = solution.process(data, nSwaps);

        Assert.assertArrayEquals(expected, actual);
    }

}
