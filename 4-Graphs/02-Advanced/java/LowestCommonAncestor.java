package graphs.advanced;

import graphs.Graph;

/**
 * Index that support queries of the type:<br>
 * Given two vertices from a tree find their lowest common ancestor in O(1) time<br>
 * O(N log N) build time
 */
public class LowestCommonAncestor {
    private static final int MAX_LOG_2 = 32;
    private static final int[] POWER_OF_2;

    static {
        int[] arr = new int[MAX_LOG_2];
        for (int i = 2; i < MAX_LOG_2; i++) {
            arr[i] = arr[i / 2];
        }
        POWER_OF_2 = arr;
    }

    private int[] depth;
    private int[] eulerianOrder;
    private int[] firstOccurrence;
    private int[][] minimumSparseTable;

    public LowestCommonAncestor(Graph tree) {
        build(tree, 0);
    }

    public LowestCommonAncestor(Graph tree, int root) {
        build(tree, root);
    }

    public int getLowestCommonAncestor(int node1, int node2) {
        int from = Math.min(firstOccurrence[node1], firstOccurrence[node2]);
        int to = Math.max(firstOccurrence[node1], firstOccurrence[node2]);

        int power = POWER_OF_2[to - from];

        int left = minimumSparseTable[from][power];
        int right = minimumSparseTable[to - (1 << (power))][power];

        return (depth[left] < depth[right]) ? eulerianOrder[left] : eulerianOrder[right];
    }

    public int getDepth(int node) {
        return depth[firstOccurrence[node]];
    }

    private void build(Graph tree, int root) {
        depth = new int[tree.vertices * 2];
        eulerianOrder = new int[tree.vertices * 2];
        firstOccurrence = new int[tree.vertices];

        Integer index = 0;
        eulerianTraversal(tree, root, -1, 0, index);

        minimumSparseTable = new int[tree.vertices][MAX_LOG_2];

        for (int i = 0; i < tree.vertices; i++) {
            minimumSparseTable[i][0] = i;
        }

        for (int power = 1; power < MAX_LOG_2; power++) {
            for (int node = 0; node + (1 << power) < tree.vertices * 2; node++) {
                int left = minimumSparseTable[node][power - 1];
                int right = minimumSparseTable[node + (1 << (power - 1))][power - 1];

                minimumSparseTable[node][power] = (depth[left] < depth[right]) ? left : right;
            }
        }
    }

    private void eulerianTraversal(Graph tree, int node, int parent, int currentDepth, Integer index) {
        depth[index] = currentDepth;
        eulerianOrder[index] = node;
        firstOccurrence[node] = index;
        index++;

        for (Graph.ReachableVertex reachableVertex : tree.adjacencyList.get(node)) {
            if (reachableVertex.to != parent) {
                eulerianTraversal(tree, reachableVertex.to, node, currentDepth + 1, index);

                depth[index] = currentDepth;
                eulerianOrder[index] = node;
                index++;
            }
        }
    }
}