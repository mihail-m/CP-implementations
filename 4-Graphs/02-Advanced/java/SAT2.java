package graphs.advanced;

import graphs.DirectedGraph;

public class SAT2 {
    /**
     * Expected satisfiability graph structure: if (term_i) is at node (i) then (!term_i) in at node (i + n).
     */
    public boolean check2SAT(DirectedGraph graph) {
        int[] components = Kosaraju.getStronglyConnectedComponents(graph);

        for (int component = 0; component < components.length; component++) {
            if (components[component] == components[component + graph.vertices]) {
                return false;
            }
        }

        return true;
    }
}
