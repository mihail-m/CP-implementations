package graphs;

public class Network extends DirectedGraph {
    public Network(int vertices) {
        super(vertices);
    }

    public void addEdge(int from, int to, long capacity) {
        this.adjacencyList.get(from).add(new ReachableVertex(this.edges));
        this.edgesList.add(new NetworkEdge(from, to, capacity));
        this.edges++;

        this.adjacencyList.get(to).add(new ReachableVertex(this.edges));
        this.edgesList.add(new NetworkEdge(to, from, 0));
        this.edges++;
    }

    public void addEdge(int from, int to, long capacity, int cost) {
        this.adjacencyList.get(from).add(new ReachableVertex(this.edges, cost));
        this.edgesList.add(new NetworkEdge(from, to, capacity, cost));
        this.edges++;

        this.adjacencyList.get(to).add(new ReachableVertex(this.edges, cost));
        this.edgesList.add(new NetworkEdge(to, from, 0, cost));
        this.edges++;
    }

    public static class NetworkEdge extends Edge {
        public long flow;
        public long capacity;

        public NetworkEdge(int from, int to, long capacity) {
            super(from, to);
            this.capacity = capacity;
            this.flow = 0L;
        }

        public NetworkEdge(int from, int to, long capacity, int cost) {
            super(from, to, cost);
            this.capacity = capacity;
            this.flow = 0L;
        }
    }
}
