import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class EmoticonsDiv2Test {

    protected EmoticonsDiv2 solution;

    @Before
    public void setUp() {
        solution = new EmoticonsDiv2();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int smiles = 2;

        int expected = 2;
        int actual = solution.printSmiles(smiles);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int smiles = 6;

        int expected = 5;
        int actual = solution.printSmiles(smiles);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int smiles = 11;

        int expected = 11;
        int actual = solution.printSmiles(smiles);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int smiles = 16;

        int expected = 8;
        int actual = solution.printSmiles(smiles);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int smiles = 1000;

        int expected = 21;
        int actual = solution.printSmiles(smiles);

        Assert.assertEquals(expected, actual);
    }

}
