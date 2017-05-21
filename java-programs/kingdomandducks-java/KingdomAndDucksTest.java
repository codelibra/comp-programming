import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class KingdomAndDucksTest {

    protected KingdomAndDucks solution;

    @Before
    public void setUp() {
        solution = new KingdomAndDucks();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] duckTypes = new int[]{5, 8};

        int expected = 2;
        int actual = solution.minDucks(duckTypes);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] duckTypes = new int[]{4, 7, 4, 7, 4};

        int expected = 6;
        int actual = solution.minDucks(duckTypes);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] duckTypes = new int[]{17, 17, 19, 23, 23, 19, 19, 17, 17};

        int expected = 12;
        int actual = solution.minDucks(duckTypes);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] duckTypes = new int[]{50};

        int expected = 1;
        int actual = solution.minDucks(duckTypes);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] duckTypes = new int[]{10, 10, 10, 10, 10};

        int expected = 5;
        int actual = solution.minDucks(duckTypes);

        Assert.assertEquals(expected, actual);
    }

}
