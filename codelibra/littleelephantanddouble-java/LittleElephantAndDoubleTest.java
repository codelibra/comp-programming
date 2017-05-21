import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class LittleElephantAndDoubleTest {

    protected LittleElephantAndDouble solution;

    @Before
    public void setUp() {
        solution = new LittleElephantAndDouble();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] A = new int[]{1, 2};

        String expected = "YES";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] A = new int[]{1, 2, 3};

        String expected = "NO";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] A = new int[]{4, 8, 2, 1, 16};

        String expected = "YES";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] A = new int[]{94, 752, 94, 376, 1504};

        String expected = "YES";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] A = new int[]{148, 298, 1184};

        String expected = "NO";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int[] A = new int[]{7, 7, 7, 7};

        String expected = "YES";
        String actual = solution.getAnswer(A);

        Assert.assertEquals(expected, actual);
    }

}
