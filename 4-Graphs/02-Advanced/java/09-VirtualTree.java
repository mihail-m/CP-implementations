package graphs.advanced;

import graphs.Graph;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Tree structure answering queries of the type: <br>
 * Given a list of K vertices from a tree find the distance between each pair of vertices in O(K log K) time<br>
 */
@SuppressWarnings({"unused", "unchecked"})
public class VirtualTree {
    private final Graph tree;

    private final int[] timeIn;
    private final int[] timeOut;

    private final int[] subtreeSize;
    private final boolean[] importantNodes;

    private final List<Integer>[] virtualTreeIndex;

    private final LowestCommonAncestor lca;

    public VirtualTree(Graph t) {
        tree = t;

        timeIn = new int[tree.vertices];
        timeOut = new int[tree.vertices];
        subtreeSize = new int[tree.vertices];
        importantNodes = new boolean[tree.vertices];

        lca = new LowestCommonAncestor(tree);

        virtualTreeIndex = (ArrayList<Integer>[]) new ArrayList[tree.vertices];
        for (int i = 0; i < tree.vertices; i++) {
            virtualTreeIndex[i] = new ArrayList<>();
        }

        Integer time = 0;
        assignVisitTimes(0, -1, time);
    }

    public long sumDistance(List<Integer> nodes) {
        nodes.forEach(node -> {
            importantNodes[node] = true;
        });

        int root = build(nodes);

        long result = findSum(root, -1, nodes.size());

        nodes.forEach(node -> {
            importantNodes[node] = false;
            virtualTreeIndex[node].clear();
            subtreeSize[node] = 0;
        });

        return result;
    }

    private int build(List<Integer> nodes) {
        nodes.sort(Comparator.comparingInt(node -> timeIn[node]));

        int size = nodes.size();
        for (int i = 1; i < size; i++) {
            nodes.add(lca.getLowestCommonAncestor(nodes.get(i - 1), nodes.get(i)));
        }

        nodes.sort(Comparator.comparingInt(node -> timeIn[node]));
        nodes = nodes.stream().distinct().collect(Collectors.toList());

        ArrayList<Integer> stack = new ArrayList<>();
        stack.add(nodes.get(0));

        for (int i = 1; i < nodes.size(); i++) {
            int node = nodes.get(i);

            while (stack.size() >= 2 && !upper(stack.get(stack.size() - 1), node)) {
                virtualTreeIndex[stack.get(stack.size() - 2)].add(stack.get(stack.size() - 1));
                stack.remove(stack.size() - 1);
            }

            stack.add(node);
        }

        while (stack.size() >= 2) {
            virtualTreeIndex[stack.get(stack.size() - 2)].add(stack.get(stack.size() - 1));
            stack.remove(stack.size() - 1);
        }

        return stack.get(0);
    }

    private long findSum(int node, int parent, int total) {
        long result = 0;

        subtreeSize[node] = importantNodes[node] ? 1 : 0;
        for (int child : virtualTreeIndex[node]) {
            result += findSum(child, node, total);
            subtreeSize[node] += subtreeSize[child];
        }

        if (parent != -1) {
            int distance = lca.getDepth(node) - lca.getDepth(parent);
            result += distance * (total - subtreeSize[node]) * subtreeSize[node];
        }

        return result;
    }

    private void assignVisitTimes(int node, int parent, Integer time) {
        timeIn[node] = time++;
        for (Graph.ReachableVertex reachableVertex : tree.adjacencyList.get(node)) {
            if (reachableVertex.to != parent) {
                assignVisitTimes(reachableVertex.to, node, time);
            }
        }
        timeOut[node] = time++;
    }

    private boolean upper(int node1, int node2) {
        return timeIn[node1] < timeIn[node2] && timeOut[node1] > timeOut[node2];
    }
}
