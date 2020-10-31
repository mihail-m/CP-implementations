package graphs.advanced;

import graphs.GraphsTest;

import org.junit.Assert;
import org.junit.Test;

public class GraphsAdvancedTest extends GraphsTest {
    @Test
    public void testSPFA() {
        int[] expectedResult = {0, 4, 12, 19, 21, 11, 9, 8, 14};
        int[] actualResult = new int[9];

        Assert.assertFalse(SPFA.getShortestPaths(buildGraph(9, super::addEdges1), 0, actualResult));
        Assert.assertArrayEquals(expectedResult, actualResult);
    }
}
