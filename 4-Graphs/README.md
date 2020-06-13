# Graphs:
<p>
Let V be a set of vertices V = {v | v ∈ N}. <br>
Let E be a set of edges connecting those vertices E = {(u, v) | u, v ∈ V}.<br>

We will call G(V, E) a graph vith vertices V and edges E.<br>

A path in G will be a sequence of vertices from V connected by edges from E:<br>
p = (v1, v2, ..., vn), v1, v2, ... vn ∈ V & ∀ (vi, vi+1) ∈ E.

A graph can be represented programatically in a few ways:

1. By a list of edges. (eg. vector<pair<int, int>> where each pair is an edge).<br>

2. By an adjacency matrix. A matrix where the cell at postition (i, j) indicates if there is an edge between vertices i and j.<br>

3. By an adjacency list. A list for each vetrex containing all of it's neighbours (eg. vector<int> graph[]).<br>
~~~    
Graph: (1)---(2)---(3)    List of edges: (1, 2)    Adjecency matrix: 0 1 0 0    Adjecency list: 1: 2
              |  /                       (2, 3)                      1 0 1 1                    2: 1, 3, 4
              (4)                        (3, 4)                      0 1 0 1                    3: 2, 4
                                         (2, 4)                      0 1 1 0                    4: 2, 3
~~~                                         
If we have a directed graph, then the edges have a direction and can be traversed only one way. The edge (i, j) allows us to go from vetrex i to vetrex j but not the other way around. We must take this into account when we build our graph.<br>
~~~  
Graph: (1)--->(2)----->(3)    List of edges: (1, 2)    Adjecency matrix: 0 1 0 0    Adjecency list: 1: 2
               |        |                    (2, 3)                      0 0 1 1                    2: 3, 4
               |->(4)<--|                    (3, 4)                      0 0 0 1                    3: 4
                                             (2, 4)                      0 0 0 0                    4:
~~~
A graph can have costs on its edges, it that case they are represented as triplets instead of pairs: e = (u, v, cost).
~~~
Graph: (1)--3--(2)--2--(3)    List of edges: (1, 2, 3)    Adjecency matrix: 0 3 0 0
                |     /                      (2, 3, 2)                      3 0 2 1
                1    5                       (3, 4, 5)                      0 2 0 5
                |   /                        (2, 4, 1)                      0 1 5 0
                |  /
                (4)           Adjecency list: 1: (2, 3)
                                              2: (1, 3), (3, 2), (4, 1)
                                              3: (2, 2), (4, 5)
                                              4: (2, 1), (3, 5)
~~~                  
</p>

## DFS
- Depth first search. Visits every vertex reachable from the starting vertex.

- O(V + E) complexity, where V is the number of vertixes, and E is the number of edges.

- <p>We want to visit every vertex only once so we need to keep track of which vertixes we have visited. (bool visited[]).<br>
   
   Let v be the vertex we are currenlty at. First we need to mark it as visited and then we need to recursively visit all of it's neighbours that aren't allready visited. When there are no more vertexes that are not visited, we are done.
   
   We consider every vertex only once and we consider each edge twice (once from evert direction) => O(n + m).</p>
   
   <p align="center">
      <img width="60%" src="https://inginious.org/course/competitive-programming/graphs-dfs/dfs.gif">
   </p>

## BFS
- Breadth first search. Visits every vertex reachable from the starting vertex. Splits the graph into levels. Finds the shortest path from the starting vertex to every other vertex in an unweight graph.

- O(V + E) complexity, where V is the number of vertixes, and E is the number of edges.

- <p>We want to visit every vertex only once so we need to keep track of which vertixes we have visited. (bool visited[]).<br>
   
   Let v be the vertex we are currenlty at. First we need to mark it as visited and then we need to add all of it's neighbours that aren't allready visited in a queue in order to be visited next. When there are no more vertexes that are not visited, we are done. The next vertex for processing is the one at the top of the queue.
   
   We consider every vertex only once and we consider each edge twice (once from evert direction) => O(n + m).</p>
   
   <p align="center">
      <img width="60%" src="https://miro.medium.com/max/1280/0*miG6xdyYzdvrB67S.gif">
   </p>

## Number of paths of fixed length

## Dijkstra

## Belman Ford

## Shortest Path Faster Algorithm (SPFA)

## Floyd Warshall

## Prim

## Kruskal

## Find cycles

## Find bridges

## Find articulation points

## Topological sort

## Strongly connected components (Koraraju)

## Boolean 2 satisfiability (2-SAT)

## K-th ancestor

## Lowest common ancestor (LSA)

## Max flow (Edmonds Karp)

## Max flow (Dinic)

## Max flow (MPM)

## Min cost max flow (assignment problem)

## Virtual tree

## Path queries on tree (LSA + Segment tree)

## A*


  

