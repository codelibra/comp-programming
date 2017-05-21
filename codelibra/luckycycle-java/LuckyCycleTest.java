import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class LuckyCycleTest {

    protected LuckyCycle solution;

    @Before
    public void setUp() {
        solution = new LuckyCycle();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] edge1 = new int[]{1};
        int[] edge2 = new int[]{2};
        int[] weight = new int[]{4};

        int[] expected = new int[]{};
        int[] actual = solution.getEdge(edge1, edge2, weight);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] edge1 = new int[]{1, 3, 2, 4};
        int[] edge2 = new int[]{2, 2, 4, 5};
        int[] weight = new int[]{4, 7, 4, 7};

        int[] expected = new int[]{1, 5, 7};
        int[] actual = solution.getEdge(edge1, edge2, weight);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] edge1 = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        int[] edge2 = new int[]{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        int[] weight = new int[]{4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7};

        int[] expected = new int[]{1, 12, 7};
        int[] actual = solution.getEdge(edge1, edge2, weight);

        Assert.assertArrayEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] edge1 = new int[]{1, 2, 3, 5, 6};
        int[] edge2 = new int[]{2, 3, 4, 3, 5};
        int[] weight = new int[]{4, 7, 7, 7, 7};

        int[] expected = new int[]{1, 4, 4};
        int[] actual = solution.getEdge(edge1, edge2, weight);

        Assert.assertArrayEquals(expected, actual);
    }

}
