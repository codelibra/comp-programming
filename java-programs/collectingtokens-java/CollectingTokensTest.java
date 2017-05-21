import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CollectingTokensTest {

    protected CollectingTokens solution;

    @Before
    public void setUp() {
        solution = new CollectingTokens();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] A = new int[]{1};
        int[] B = new int[]{2};
        int[] tokens = new int[]{7, 1};
        int L = 6;

        int expected = 8;
        int actual = solution.maxTokens(A, B, tokens, L);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] A = new int[]{3, 1};
        int[] B = new int[]{2, 2};
        int[] tokens = new int[]{2, 3, 9};
        int L = 5;

        int expected = 14;
        int actual = solution.maxTokens(A, B, tokens, L);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] A = new int[]{1, 2, 5, 3};
        int[] B = new int[]{4, 4, 1, 4};
        int[] tokens = new int[]{6, 1, 6, 4, 4};
        int L = 3;

        int expected = 16;
        int actual = solution.maxTokens(A, B, tokens, L);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] A = new int[]{9, 1, 7, 10, 5, 8, 3, 4, 2};
        int[] B = new int[]{6, 6, 9, 6, 6, 1, 1, 6, 6};
        int[] tokens = new int[]{4, 2, 1, 6, 3, 7, 8, 5, 2, 9};
        int L = 4;

        int expected = 26;
        int actual = solution.maxTokens(A, B, tokens, L);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] A = new int[]{25, 22, 35, 42, 40, 9, 32, 12, 37, 44, 23, 1, 24, 28, 20, 4, 26, 33, 11, 48, 34, 6, 16, 50, 46, 17, 8, 43, 18, 30, 31, 36, 39, 13, 10, 45, 3, 47, 15, 2, 29, 19, 7, 14, 41, 49, 38, 27, 21};
        int[] B = new int[]{5, 5, 25, 25, 25, 42, 25, 40, 5, 35, 25, 32, 42, 9, 32, 23, 40, 25, 20, 33, 26, 37, 12, 1, 48, 24, 22, 25, 11, 24, 48, 34, 18, 9, 50, 42, 16, 40, 1, 10, 47, 22, 48, 44, 48, 1, 4, 46, 47};
        int[] tokens = new int[]{6, 9, 4, 9, 5, 8, 6, 4, 4, 1, 4, 8, 3, 4, 5, 8, 5, 6, 4, 9, 7, 9, 7, 9, 5, 2, 7, 2, 7, 7, 5, 9, 5, 8, 5, 7, 1, 9, 3, 9, 3, 6, 4, 5, 5, 4, 7, 9, 2, 2};
        int L = 48;

        int expected = 194;
        int actual = solution.maxTokens(A, B, tokens, L);

        Assert.assertEquals(expected, actual);
    }

}
