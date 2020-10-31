package graphs.advanced;

import java.util.Arrays;

import basic.data.structures.Queue;

import graphs.Graph;
import graphs.Network;

public class Dinic {
    /**
     * Return the maximum flow in the given graph from the source to the sink<br>
     * O(V^2E) complexity<br>
     */
    public long dinic(Network graph, int source, int sink) {
        long flow = 0;

        Integer[] level = new Integer[graph.vertices];
        Arrays.fill(level, -1);
        level[source] = 0;

        Queue<Integer> q = new Queue<>();
        q.push(source);

        while (dinicBfs(graph, q, level, sink)) {
            Integer[] ptr = new Integer[graph.vertices];
            long pushed = dinicDfs(graph, source, sink, Long.MAX_VALUE, ptr, level);
            while (pushed > 0) {
                flow += pushed;
                pushed = dinicDfs(graph, source, sink, Long.MAX_VALUE, ptr, level);
            }

            Arrays.fill(level, -1);
            level[source] = 0;
            q.push(source);
        }

        return flow;
    }

    private boolean dinicBfs(Network graph, Queue<Integer> q, Integer[] level, int sink) {
        while (!q.empty()) {
            int node = q.poll();

            for (Graph.ReachableVertex vertex : graph.adjacencyList.get(node)) {
                Network.NetworkEdge edge = (Network.NetworkEdge) graph.edgesList.get(vertex.to);

                if (edge.capacity - edge.flow < 1) {
                    continue;
                }

                if (level[edge.to] != -1) {
                    continue;
                }

                level[edge.to] = level[node] + 1;
                q.push(edge.to);
            }
        }

        return level[sink] != -1;
    }

    private long dinicDfs(Network graph, int node, int sink, long pushed, Integer[] ptr, Integer[] level) {
        if (pushed == 0) {
            return 0;
        }

        if (node == sink) {
            return pushed;
        }

        for (; ptr[node] < graph.adjacencyList.get(node).size(); ptr[node]++) {
            int id = graph.adjacencyList.get(node).get(ptr[node]).to;

            Network.NetworkEdge edge = (Network.NetworkEdge) graph.edgesList.get(id);
            Network.NetworkEdge reverseEdge = (Network.NetworkEdge) graph.edgesList.get(id ^ 1);

            if (level[node] + 1 != level[edge.to] || edge.capacity - edge.flow < 1) {
                continue;
            }

            long currentFlow = dinicDfs(graph, edge.to, sink, Math.min(pushed, edge.capacity - edge.flow), ptr, level);

            if (currentFlow == 0) {
                continue;
            }

            edge.flow += currentFlow;
            reverseEdge.flow -= currentFlow;

            return currentFlow;
        }

        return 0;
    }
}
