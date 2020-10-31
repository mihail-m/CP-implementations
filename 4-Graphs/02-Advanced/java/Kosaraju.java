package graphs.advanced;

import graphs.DirectedGraph;
import graphs.Graph;

import java.util.Arrays;
import java.util.Stack;

public class Kosaraju {
    /**
     * Find the strongly connected components of a directed graph using the Kosaraju alori
     * @param graph
     * @return
     */
    public static int[] getStronglyConnectedComponents(DirectedGraph graph) {
        Stack<Integer> s = new Stack<>();
        Arrays.fill(graph.visited, false);

        for (int node = 0; node < graph.vertices; node++) {
            if (!graph.visited[node]) {
                dfs(graph, node, s);
            }
        }

        Graph reverseGraph = new Graph(graph.vertices);
        graph.edgesList.forEach(edge -> reverseGraph.addEdge(edge.to, edge.from, edge.cost));

        int[] components = new int[graph.vertices];
        Arrays.fill(graph.visited, false);

        int componentNumber = 0;
        while (!s.empty()) {
            int node = s.pop();
            if (!reverseGraph.visited[node]) {
                dfsReverse(reverseGraph, node, components, componentNumber);
                componentNumber++;
            }
        }

        return components;
    }

    private static void dfs(Graph graph, int node, Stack<Integer> s) {
        graph.visited[node] = true;
        graph.adjacencyList.get(node).forEach(neighbour -> {
            if (!graph.visited[neighbour.to]) {
                dfs(graph, neighbour.to, s);
            }
        });
        s.push(node);
    }

    private static void dfsReverse(Graph graph, int node, int[] components, int componentNumber) {
        graph.visited[node] = true;
        components[node] = componentNumber;
        graph.adjacencyList.get(node).forEach(neighbour -> {
            if (!graph.visited[neighbour.to]) {
                dfsReverse(graph, neighbour.to, components, componentNumber);
            }
        });
    }
}
