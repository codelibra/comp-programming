import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CreateGroupsTest {

    protected CreateGroups solution;

    @Before
    public void setUp() {
        solution = new CreateGroups();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        int[] groups = new int[]{10, 20};
        int minSize = 10;
        int maxSize = 15;

        int expected = 5;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        int[] groups = new int[]{20, 8, 6};
        int minSize = 10;
        int maxSize = 15;

        int expected = 6;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        int[] groups = new int[]{10, 20, 30};
        int minSize = 1;
        int maxSize = 18;

        int expected = -1;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        int[] groups = new int[]{50, 10, 20, 20, 5};
        int minSize = 15;
        int maxSize = 30;

        int expected = 20;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase4() {
        int[] groups = new int[]{100, 200, 301};
        int minSize = 200;
        int maxSize = 200;

        int expected = -1;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase5() {
        int[] groups = new int[]{1, 10, 10};
        int minSize = 9;
        int maxSize = 20;

        int expected = -1;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase6() {
        int[] groups = new int[]{55, 33, 45, 71, 27, 89, 16, 14, 61};
        int minSize = 33;
        int maxSize = 56;

        int expected = 53;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase7() {
        int[] groups = new int[]{49, 60, 36, 34, 36, 52, 60, 43, 52, 59};
        int minSize = 45;
        int maxSize = 51;

        int expected = 31;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase8() {
        int[] groups = new int[]{5, 5, 5, 5, 5};
        int minSize = 5;
        int maxSize = 5;

        int expected = 0;
        int actual = solution.minChanges(groups, minSize, maxSize);

        Assert.assertEquals(expected, actual);
    }

}
