package graphs.advanced;


import graphs.Graph;

/**
 * Index that support queries of the type:<br>
 * Given a vertex in a tree and a number k, find the vertex that is at distance k from the given vertex
 * laying on the path to the root of the tree in O(log(tree depth)) complexity<br>
 * O(N log N) build time
 */
public class KthAncestor {
    private static final int MAX_LOG_2 = 32;
    private static final int[] POWER_OF_2;

    static {
        int[] arr = new int[MAX_LOG_2];
        for (int i = 2; i < MAX_LOG_2; i++) {
            arr[i] = arr[i / 2];
        }
        POWER_OF_2 = arr;
    }

    private int[][] ancestorsIndex;

    public KthAncestor(Graph tree) {
        build(tree, 0);
    }

    public KthAncestor(Graph tree, int root) {
        build(tree, root);
    }

    public int getKthAncestor(int node, int k) {
        int kthAncestor = node;

        while (k > 0) {
            kthAncestor = ancestorsIndex[kthAncestor][POWER_OF_2[k]];
            k -= (1 << POWER_OF_2[k]);
        }

        return kthAncestor + 1;
    }

    private void build(Graph tree, int root) {
        ancestorsIndex = new int[tree.vertices][MAX_LOG_2];

        assignParents(tree, root, -1);
        ancestorsIndex[root][0] = root;

        for (int power = 1; power < MAX_LOG_2; power++) {
            for (int node = 0; node < tree.vertices; node++) {
                ancestorsIndex[node][power] = ancestorsIndex[ancestorsIndex[node][power - 1]][power - 1];
            }
        }
    }

    private void assignParents(Graph tree, int node, int parent) {
        ancestorsIndex[node][0] = parent;
        for (Graph.ReachableVertex reachableVertex : tree.adjacencyList.get(node)) {
            if (reachableVertex.to != parent) {
                assignParents(tree, reachableVertex.to, node);
            }
        }
    }
}