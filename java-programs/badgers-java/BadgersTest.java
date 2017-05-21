import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class BadgersTest {

    protected Badgers solution;

    @Before
    public void setUp() {
        solution = new Badgers();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] hunger = new int[]{1, 2, 3};
        int[] greed = new int[]{2, 2, 1};
        int totalFood = 7;

        int expected = 2;
        int actual = solution.feedMost(hunger, greed, totalFood);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] hunger = new int[]{5, 2, 1, 5};
        int[] greed = new int[]{0, 2, 4, 1};
        int totalFood = 19;

        int expected = 3;
        int actual = solution.feedMost(hunger, greed, totalFood);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] hunger = new int[]{1, 1, 1, 1, 1};
        int[] greed = new int[]{1000, 1000, 1000, 1000, 1000};
        int totalFood = 10;

        int expected = 1;
        int actual = solution.feedMost(hunger, greed, totalFood);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] hunger = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] greed = new int[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int totalFood = 100;

        int expected = 5;
        int actual = solution.feedMost(hunger, greed, totalFood);

        Assert.assertEquals(expected, actual);
    }

}
