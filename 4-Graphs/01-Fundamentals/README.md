# Graph fundamentals:

## DFS
- Depth first search. Visits every vertex reachable from the starting vertex.

- O(V + E) complexity, where V is the number of vertixes, and E is the number of edges.

- <p>We want to visit every vertex only once so we need to keep track of which vertixes we have visited. (bool visited[]).<br>
   
   Let v be the vertex we are currenlty at. First we need to mark it as visited and then we need to recursively visit all of it's neighbours that aren't allready visited. When there are no more vertices that are not visited, we are done.
   
   We consider every vertex only once and we consider each edge twice (once from every direction) => O(n + m).</p>
   
   <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/DFS.gif">
   </p>

## BFS
- Breadth first search. Visits every vertex reachable from the starting vertex. Splits the graph into levels. Finds the shortest path from the starting vertex to every other vertex in an unweighted graph.

- O(V + E) complexity, where V is the number of vertixes, and E is the number of edges.

- <p>We want to visit every vertex only once so we need to keep track of which vertixes we have visited. (bool visited[]).<br>
  
  We will use a queue to keep track of which is the current vertex we are at. This will always be the top of the queue.
  
  In the beginning all vertices are marked as not visited, except for the starting vertex.
   
   Let v be the vertex we are currenlty at. We need to add all of it's neighbours that aren't allready visited in the queue for processing and mark them as visited, so we do not add them to the queue more than once. When there are no more vertices that are not visited, we are done.<br>
   
   Let s be our starting vertex. The distance to s is 0. To find the distance to all of the neighbours of s is 1, the distance to all of their unvisited neighbours is 2 and so on. Those groups of vertices (that have the same distace to s) are the levels of the bfs. All vertices at level 1 are at distance 1 all at level to at distance 2 and so on.<br>
   
   When we are at vertex u that has level l, all of its unvisited neighbours are at level l + 1, because we must travel trough one more edge in order to reach them. So in order to calculate the distance, every time we add a new vertex to the queue, the distance to it is with 1 bigger that the distance to the vertex we are currently at: distance[new_vertex] = distance[current_vertex] + 1.
   
   We consider every vertex only once and we consider each edge twice (once from every direction) => O(n + m).</p>
   
   <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/BFS.gif">
   </p>

## Number of paths of fixed length
- Find the number of paths with lenght k between two nodes from the graph G.

- O(V^3 log k) complexity.

- <p>Let's take a look at the case where k = 1.<br>
  
  If we build the adjacency matrix Adj of the graph, then in the cell (u, v) we will have the number of ways to reach v from u by using only one edge: 1 way if they are connected, 0 ways if they are not.<br>
  
  Now let's take a look at the case where we know the number of paths with length k - 1 from u to v and we want to find out the number of paths with lenght k from u to v.<br>
  
  Then the number of paths from u to v with lenght k can be computed by counting all paths with length k - 1 that start at u end in a vertex that is connected to v. We can just sum the number of paths ending at every vertex connected to v. In order to do this we can take the paths ending at vertex i multiplied by Adj[i][v], which will be 1 if i is connected to v and 0 if it is not, and sum this value for every vertex i, which will add up to the total number ot paths from u to v with lenght k.<br>
  
  Let Pk-1 is the matrix that contains all the paths from u to v with lenght k - 1 in cell (u, v). Then we can calucate Pk with the help of the adjacency matrix Adj and Pk-1:<br>
              
  Pk [u][v] = Pk-1[u][0] * Adj[0][v] + Pk[u][1] * Adj[1][v] + ... + Pk-1[u][n - 1] * Adj[n - 1][v] = sum (Pk-1[u][i] * Adj[i][v]),<br>
  i = 0, 1, ..., n.<br>
  
  This operation is actually just the multiplication of the two matrices Pk-1 and A => Pk = Pk-1 * Adj.<br>
  
  With this observation we can see that to calculate Pk we can calculate A to the power of k. Pk = Adj^k.<br>
  
  All path with length k from u to v can be found at (Adj^k)[u][v].
  </p>

## Belman Ford
- Find the shortes path to every vertex from a starting vertex s in a weighted graph.

- O(VE) complexity.

- <p>We will create an array of distances dist[], which will contain the answer to the problem.<br>
  
  In the beginning we all elements of dist[] equal to infinity INT_MAX except for dist[s], which will be equal to 0, because it is our starting point.<br>
  
  Let (u, v, cost) in an edge from E. If the distance to v is greater that the distance to u plust the cost, then we can reach v more efficiently by using the path to u and the edge (u, v, cost) instead of the current path to v. This is called rexalxation and we will use it to solve our problem.<br>
  
  Relaxation: dist[u] + cost < dist[v] then dist[v] = dist[u] + cost.<br>

  The algorithm consists of n - 1 phases. Each phase goest through all edges of the graph, and tries to perform a relaxation using each edge (u, v, cost). After tring to relax with each edge n - 1 times the array dist will contain the values of the shortest paths from s to every other vertex in G.
</p>

## Dijkstra
- Find the shortes path to every vertex from a starting vertex s in a weighted graph.

- O(E log V) complexity or O(V ^ 2) complexity depending on implementation.

- On dense graphs: https://cp-algorithms.com/graph/dijkstra.html

- On sparce graphs: https://cp-algorithms.com/graph/dijkstra_sparse.html

## Floyd Warshall
- Find the shortest path between every pair of vertices from the weighted graph G(V, E).

- O(V ^ 3) complexity.

- <p>The approach we will take is that we will find the shortest path between every pair of vertices (u, v, cost) that uses only vertices with numbers less than k ({0, 1, 2, ..., k - 1}) as internal vertices (does not apply for the start and end vertex). Since we have V vertices that means that we must compute the shortest paths for k = 0, 1, 2, ..., V - 1.<br>

     Firstly we mark the distance from every vertex to itself as 0 (dist[i][i][k] = 0 for every k < V).<br>

     We mark the distance between every two vertices that are connected by an edge (u, v, cost) as that edges cost (dist[i][j][k] = cost, where (i, j, cost) ∈ E). The distance between all other pairs of vertices (that are not conected by an edge) we init as INT_MAX.<br>

     Once we have computed the aswers for 0, 1, ... k - 1, we can compute the asnwer for k as follows:<br>

     For every pair of vertices (u, v), we check if we can reach v from u by passing trough the vertex k with a lower cost than the best found up untill now:<br>

     distance[u][v][k] = min(distance[u][i][k] + distance[i][v][k], distance[u][v][k - 1]).<br>
     
     We can see that the last dimention is redundant since we use only the last stored value => we can drop it from our state:<br>
     
     distance[u][v] = min (distance[u][i] + distance[i][v], distance[u][v]).<br>
     
     We consider each pair of vertices a total of V times (every time we add a new vertex we update the best paths between every two vertices) => O(V^2 * V) = O(V ^ 3) time complexity. 
     
</p>

## Prim

## Kruskal

## Find cycles

## Find bridges

## Find articulation points

## Topological sort

## Max flow (Edmonds Karp)


  

