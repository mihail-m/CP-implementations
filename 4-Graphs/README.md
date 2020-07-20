# Graphs:
<p>
Let V be a set of vertices V = {v | v ∈ N}. <br></li>

Let E be a set of edges connecting those vertices E = {(u, v) | u, v ∈ V}.<br></li>

We will call G(V, E) a graph with vertices V and edges E.<br></li>

A graph can be represented programatically in a few ways:<br></li>

1. By a list of edges. (eg. vector<pair<int, int>> where each pair is an edge).<br>

2. By an adjacency matrix. A matrix where the cell at postition (i, j) indicates if there is an edge between vertices i and j.<br>

3. By an adjacency list. A list for each vetrex containing all of it's neighbours (eg. vector<int> graph[]).<br>
  
   <p align="center">
     <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Graphs1.png">
   </p>
  
If we have a directed graph, then the edges have a direction and can be traversed only one way. The edge (i, j) allows us to go from vetrex i to vetrex j but not the other way around. We must take this into account when we build our graph.<br>

   <p align="center">
     <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Graphs2.png">
   </p>
   
A graph can have costs on its edges, it that case they are represented as triplets instead of pairs: e = (u, v, cost).</li>

   <p align="center">
     <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Graphs3.png">
   </p>
   
Let G(V, E) is an undrirected graph and v ∈ V and D = {(u, v) ∈ E} U {(v, u) ∈ E}., then |D| = degree of v.

Let G(V, E) is an drirected graph and v ∈ V and Din = {(u, v) ∈ E} and Dout = {(v, u) ∈ E}., then |Din| = in degree of v and |Dout| = out degree of v.
   
A path in G will be a sequence of vertices from V connected by edges from E:<br>
p = (v1, v2, ..., vn), v1, v2, ... vn ∈ V & ∀ (vi, vi+1) ∈ E.<br></li>

A simple path in G will be a path p, such that no vertex in the path is repeated:<br>
p = (v1, v2, ..., vn), v1, v2, ... vn ∈ V & ∀ (vi, vi+1) ∈ E, ∀ vi, vj : i != j => vi != vj.<br></li>

The length of a path is the number of edges in the path.<br></li>

In a weighted graph the cost of a path is the sum of the cost of all edges in the path.<br></li>

If p = (v1, v2, ..., vn) is a path in G and v1 = vn, then we will can p a cycle.<br>

If G is a directed graph, and G has no cycles, the we will call G acyclic.

Let u, v ∈ V are vertices, we will say that v is reachable from u, if there exists a path p = (u, v1, v2, ..., vn, v).<br>

If G(V, E) is an undirected graph and for every u, v ∈ V, v is reachable from u, then G is connected (is a connected component).
  
Let T(V, E) is a graph and:<br>

  1. T is a connected;<br>
  2. |E| = |V| - 1; (T has exactly |V| - 1 edges).<br>
  3. T has no cycles.<br>

If any 2 of those are true, then all 3 are true and we will call the graph T a tree.<br>

If T(V, E) is a tree for every u, v ∈ V, there is only a single path from u to v in T.<br>

If G(V, E) is a connected graph and T(V, E1) is a tree such that: E1 ⊆ E, then we will call T a spanning tree of the graph G. A graph can have multiple sapnning trees.<br>

If G(V, E) is a connected weighted graph and T(V, E1) is a tree such that: E1 ⊆ E and the sum of the costs of all edges in E1 is minumum possible, then T is a minimum spanning tree of the graph G. A graph can have multiple minimum sapnning trees.<br>

Let A be the adjacency matrix of the graph: A[u][v] is the number of edges between u and v and let D be the degree matrix of the graph: a diagonal matrix with D[u][u] in the degree of vertex u. The Laplacian matrix of the graph is defined as L = D − A.<br>

(Kirchhoff's theorem) All cofactors of L are equal to each other, and they are equal to the number of spanning trees of the graph.<br>
</p>

## Graph fundamentals:

- DFS

- BFS

- Number of paths of fixed length

- Belman Ford

- Dijkstra

- Floyd Warshall

- Prim

- Kruskal

- Find cycles

- Find bridges

- Find articulation points

- Topological sort

- Max flow (Edmonds Karp)


## Graphs Advanced:

- Shortest Path Faster Algorithm (SPFA)

- Strongly connected components (Kosaraju)

- Boolean 2 satisfiability (2-SAT)

- K-th ancestor

- Lowest common ancestor (LSA)

- Max flow (Dinic)

- Max flow (MPM)

- Min cost max flow (assignment problem)

- Virtual tree

- Path queries on tree (LSA + Segment tree)

- A*


  

