package graphs.advanced;

import basic.data.structures.Queue;
import graphs.Graph;

import java.util.Arrays;

public class SPFA {
    /**
     * Find the distance from a starting vertex to all other using the SPFA algorithm.
     * O(E) average case running time
     * O(EV) worst case complexity
     *
     * @param graph Graph to be processed
     * @param start starting vertex
     * @param distance int array to store the distances in
     * @return true if the graph contains a negative cycle and false otherwise
     */
    public static boolean getShortestPaths(Graph graph, int start, int[] distance) {
        Arrays.fill(distance, Integer.MAX_VALUE);

        int[] updated = new int[graph.vertices];
        Arrays.fill(updated, 0);

        boolean[] queued = new boolean[graph.vertices];
        Arrays.fill(queued, false);

        Queue<Integer> q = new Queue<>();
        q.push(start);
        distance[start] = 0;
        queued[start] = true;

        while (!q.empty()) {
            int node = q.poll();
            queued[node] = false;

            for (Graph.Edge edge : graph.edgesList) {
                if (distance[edge.to] > distance[edge.from] + edge.cost) {
                    distance[edge.to] = distance[edge.from] + edge.cost;

                    if (!queued[edge.to]) {
                        q.push(edge.to);
                        queued[edge.to] = true;
                        updated[edge.to]++;

                        if (updated[edge.to] > graph.vertices) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
}
