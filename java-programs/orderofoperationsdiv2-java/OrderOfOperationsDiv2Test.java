import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class OrderOfOperationsDiv2Test {

    protected OrderOfOperationsDiv2 solution;

    @Before
    public void setUp() {
        solution = new OrderOfOperationsDiv2();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String[] s = new String[]{"111", "001", "010"};

        int expected = 3;
        int actual = solution.minTime(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String[] s = new String[]{"11101", "00111", "10101", "00000", "11000"};

        int expected = 9;
        int actual = solution.minTime(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String[] s = new String[]{"11111111111111111111"};

        int expected = 400;
        int actual = solution.minTime(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String[] s = new String[]{"1000", "1100", "1110"};

        int expected = 3;
        int actual = solution.minTime(s);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        String[] s = new String[]{"111", "111", "110", "100"};

        int expected = 3;
        int actual = solution.minTime(s);

        Assert.assertEquals(expected, actual);
    }

}
