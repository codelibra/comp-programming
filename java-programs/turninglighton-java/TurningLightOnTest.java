import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TurningLightOnTest {

    protected TurningLightOn solution;

    @Before
    public void setUp() {
        solution = new TurningLightOn();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String[] board = new String[]{"0001111", "0001111", "1111111"};

        int expected = 1;
        int actual = solution.minFlips(board);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String[] board = new String[]{"1111111", "1111111", "1111111"};

        int expected = 0;
        int actual = solution.minFlips(board);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String[] board = new String[]{"01001"};

        int expected = 3;
        int actual = solution.minFlips(board);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String[] board = new String[]{"0101", "1010", "0101", "1010"};

        int expected = 7;
        int actual = solution.minFlips(board);

        Assert.assertEquals(expected, actual);
    }

}
