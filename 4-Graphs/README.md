# Graphs:
<p>
Let V be a set of vertices V = {v | v ∈ N}. <br></li>

Let E be a set of edges connecting those vertices E = {(u, v) | u, v ∈ V}.<br></li>

We will call G(V, E) a graph with vertices V and edges E.<br></li>

A path in G will be a sequence of vertices from V connected by edges from E:<br>
p = (v1, v2, ..., vn), v1, v2, ... vn ∈ V & ∀ (vi, vi+1) ∈ E.<br></li>

A simple path in G will be a path p, such that no vertex in the path is repeated:<br>
p = (v1, v2, ..., vn), v1, v2, ... vn ∈ V & ∀ (vi, vi+1) ∈ E, ∀ vi, vj : i != j => vi != vj.<br></li>

The length of a path is the number of edges in the path.<br></li>

In a weighted graph the cost of a path is the sum of the cost of all edges in the path.<br></li>

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


  

