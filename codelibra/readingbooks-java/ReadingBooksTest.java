import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ReadingBooksTest {

    protected ReadingBooks solution;

    @Before
    public void setUp() {
        solution = new ReadingBooks();
    }

    @Test(timeout = 2000)
    public void testCase0() {
        String[] readParts = new String[]{"introduction", "story", "introduction", "edification"};

        int expected = 1;
        int actual = solution.countBooks(readParts);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase1() {
        String[] readParts = new String[]{"introduction", "story", "edification", "introduction", "story", "edification"};

        int expected = 2;
        int actual = solution.countBooks(readParts);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase2() {
        String[] readParts = new String[]{"introduction", "story", "introduction", "edification", "story", "introduction"};

        int expected = 1;
        int actual = solution.countBooks(readParts);

        Assert.assertEquals(expected, actual);
    }

    @Test(timeout = 2000)
    public void testCase3() {
        String[] readParts = new String[]{"introduction", "story", "introduction", "edification", "story", "story", "edification", "edification", "edification", "introduction", "introduction", "edification", "story", "introduction", "story", "edification", "edification", "story", "introduction", "edification", "story", "story", "edification", "introduction", "story"};

        int expected = 5;
        int actual = solution.countBooks(readParts);

        Assert.assertEquals(expected, actual);
    }

}
