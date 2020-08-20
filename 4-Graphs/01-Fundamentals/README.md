# Graph fundamentals:

## DFS
- Depth first search. Visits every vertex reachable from the starting vertex.

- O(V + E) complexity, where V is the number of vertixes, and E is the number of edges.

- <p>We want to visit every vertex only once so we need to keep track of which vertixes we have visited. (bool visited[]).<br>
   
   Let v be the vertex we are currenlty at. First we need to mark it as visited and then we need to recursively visit all of it's neighbours that aren't allready visited. When there are no more vertices that are not visited, we are done.
   
   We consider every vertex only once and we consider each edge twice (once from every direction) => O(V + E).</p>
   
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
   
   When we are at vertex u that has level l, all of its unvisited neighbours are at level l + 1, because we must travel trough one more edge in order to reach them. So in order to calculate the distance, every time we add a new vertex to the queue, the distance to it is with 1 bigger that the distance to the vertex we are currently at: `distance[new_vertex] = distance[current_vertex] + 1`.
   
   We consider every vertex only once and we consider each edge twice (once from every direction) => O(V + E).</p>
   
   <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/BFS.gif">
   </p>
   
## Topological sort

## Find cycles

- Find if a graph has a cycle.

- O(V + E) complexity.

- To check for a cycle we will run a series of DFSs on the graph (possibly 1) and colour it's vertices in 3 colours. Initially all vertices are white (color 0). When we enter a vertex it becomes gray (color 1) and when we exit a vertex it becomes black (color 2). If at any point we encounter an edge to a gray vertex then the graph has a cycle. If the graph is undirected we must also keep track of the vertex we came from so that we do not consider it when checking for a gray vertex.

## Number of paths of fixed length
- Find the number of paths with lenght k between two nodes from the graph G.

- O(V^3 log k) complexity.

- <p>Let's take a look at the case where k = 1.<br>
  
  If we build the adjacency matrix Adj of the graph, then in the cell (u, v) we will have the number of ways to reach v from u by using only one edge: 1 way if they are connected, 0 ways if they are not.<br>
  
  Now let's take a look at the case where we know the number of paths with length k - 1 from u to v and we want to find out the number of paths with lenght k from u to v.<br>
  
  Then the number of paths from u to v with lenght k can be computed by counting all paths with length k - 1 that start at u end in a vertex that is connected to v. We can just sum the number of paths ending at every vertex connected to v. In order to do this we can take the paths ending at vertex i multiplied by Adj[i][v], which will be 1 if i is connected to v and 0 if it is not, and sum this value for every vertex i, which will add up to the total number ot paths from u to v with lenght k.<br>
  
  Let Pk-1 is the matrix that contains all the paths from u to v with lenght k - 1 in cell (u, v). Then we can calucate Pk with the help of the adjacency matrix Adj and Pk-1:<br>
              
  Pk [u][v] = Pk-1[u][0] * Adj[0][v] + Pk[u][1] * Adj[1][v] + ... + Pk-1[u][n - 1] * Adj[n - 1][v] = sum (Pk-1[u][i] * Adj[i][v]),<br> i = 0, 1, ..., n.<br>
  
  This operation is actually just the multiplication of the two matrices Pk-1 and A => Pk = Pk-1 * Adj.<br>
  
  With this observation we can see that to calculate Pk we can calculate A to the power of k. Pk = Adj^k.<br>
  
  All path with length k from u to v can be found at (Adj^k)[u][v].
  </p>
  
## Find bridges

## Find articulation points

## Belman Ford
- Find the shortes path to every vertex from a starting vertex s in a weighted graph.

- O(VE) complexity.

- <p>We will create an array of distances dist[], which will contain the answer to the problem.<br>
  
  In the beginning we all elements of dist[] equal to infinity INT_MAX except for dist[s], which will be equal to 0, because it is our starting point.<br>
  
  Let (u, v, cost) in an edge from E. If the distance to v is greater that the distance to u plust the cost, then we can reach v more efficiently by using the path to u and the edge (u, v, cost) instead of the current path to v. This is called rexalxation and we will use it to solve our problem.<br>
  
  Relaxation: `dist[v] = min(dist[v], dist[u] + cost)`.<br>

  The algorithm consists of n - 1 phases. Each phase goest through all edges of the graph, and tries to perform a relaxation using each edge (u, v, cost). After tring to relax with each edge n - 1 times the array dist will contain the values of the shortest paths from s to every other vertex in G.
</p>

## Dijkstra
- Find the shortes path to every vertex from a starting vertex in a weighted graph.

- O(V^2) complexity on dense graphs.

- O(E log V) complexity on sparce graphs.

- <p>We will create an array dist[], that will contain the current distance from start to v in dist[v]. Initially dist[start] = 0 and dist[i] = ∞, i ≠ start.<br>

     Additionally, we need to keep track of the vertices that are maked. A vertex v is marked if we allready know the shortest path from start to v. Initially all vertices are unmarked.<br>

     On every iteration, we choose the vertex v for which dist[v] is the smallest and v is unmarked. (On the first iteration the selected vertex will be start). When a vertex is slected, we mark it (makred[v] = true) and then we try to perform relaxations with all edges going out of v: (v, to, cost). A relaxation for the edge (v, to, cost) would look like this: `dist[to] = min (dist[to], dist[v] + cost).`<br>

     After V iteraions all vertices will be marked and the procedure will terminate yelding the aswer in the array dist: the distance for start to v will be in dist[v]. If there are any unreachable vetices from start the distance to them will remain ∞.</p>

- If the graph is dense then we can simply keep 2 arrays: dist[] and marked[]. In the beginning of each iteration we find the minumum element in dist that is not marked and then we perform the relaxations. The selection of the minimum element takes O(V) time, since we have to traverse the array dist[] that has V elements (since we have V vertices),  2e make V iterations => O(V^2). All edges are considered at most twice, since each vertex is considered at most once and each edge connects exactly two vertexes => additional O(E) = O(V^2) time for the whole procedure. O(V^2) + O(V^2) = O(V^2) overall compelxity.<br>
 
- <p>If the graph is sparce, we can use a sutable data structure that will help us get the minimum element quicker. We can use a heap like structure that allow adding an element and getting minimum element (possibly deletion of an element). In c++, sutable data structures would be `set`, and `prority_queue`. This will allow us to get the minimum element in O(1) time and insert/delete an element in O(log V) time. Every time we perform a relaxation we need to update not only the dist[] array, but also our data structure.<br>

     We can keep pairs of values in the data structure (dist[v], v), this way the top of the structure will always be the pair containing the vertex with the minimum distance. Istead of marking vertices, we simply remove them form the data strucure when we process them, since they will never go back in unless we find a shorter path to them. That ensures that vertices that allready have their shortest path calculate will not be considered anymore.<br>
      
     Every time a relaxation is repformed: `dist[u] = dist[v] + cost`, we must erase the old pair for the u from the data structure (remove(dist[u], u)) and add the new one (dist[v] + cost, u) in addition to updating the dist[] array. If the data strucure we have chosen does not support the removal of up element, evry time we select an element for processing we must check if the distance stored in the data structure matches the distance in the dist[] array and if it does not we must skip it (this acts as a delayed removal).<br>
      
     The overall complexity of this approach is O(E log V). In dense graphs O(E) = O(V^2) and the complexity becomes O(V^2 log V) which is worse that O(V^2) and in this situation the other approach is prefferd.</p>
  

## Floyd Warshall
- Find the shortest path between every pair of vertices from the weighted graph G(V, E).

- O(V ^ 3) complexity.

- <p>The approach we will take is that we will find the shortest path between every pair of vertices (u, v, cost) that uses only vertices with numbers less than k ({0, 1, 2, ..., k - 1}) as internal vertices (does not apply for the start and end vertex). Since we have V vertices that means that we must compute the shortest paths for k = 0, 1, 2, ..., V - 1.<br>

     Firstly we mark the distance from every vertex to itself as 0 (dist[i][i][k] = 0 for every k < V).<br>

     We mark the distance between every two vertices that are connected by an edge (u, v, cost) as that edges cost (dist[i][j][k] = cost, where (i, j, cost) ∈ E). The distance between all other pairs of vertices (that are not conected by an edge) we init as INT_MAX.<br>

     Once we have computed the aswers for 0, 1, ... k - 1, we can compute the asnwer for k as follows:<br>

     For every pair of vertices (u, v), we check if we can reach v from u by passing trough the vertex k with a lower cost than the best found up untill now:<br>

     `distance[u][v][k] = min(distance[u][i][k] + distance[i][v][k], distance[u][v][k - 1])`.<br>
     
     We can see that the last dimention is redundant since we use only the last stored value => we can drop it from our state:<br>
     
     `distance[u][v] = min (distance[u][i] + distance[i][v], distance[u][v])`.<br>
     
     We consider each pair of vertices a total of V times (every time we add a new vertex we update the best paths between every two vertices) => O(V^2 * V) = O(V ^ 3) time complexity. 
     
</p>

## Prim
- Find the minimum spanning tree of a weighted graph.

- O(V^2) complexity on dense graphs.

- O(E log V) complexity on sparce graphs.

- <p> The idea of the algorithm is to build the tree by adding edges one by one. We start with a sigle vertex s (doesn't matter which one). At the first iteration we select the edge with minimum cost connected to s: (s, to, cost), we add it to the minimum spanning tree. After that the tree consists of two vertexes and one edge. On each iteration we choose the edge that has the minimum cost from all edges such that one end in a vertex in the tree and the other end is a vertex not in the tree. After V iteration we will have constructed the minumum spanning tree, because there will be no vertices that are not in the tree.<br>
   
   The most obvious imlementation would be to consider all edges each time we add a new vertex to the tree. The time needed to chose an edge will be O(E) and we must perform that operation O(V) times, so the overall complexity becomes O(V + E) which is really slow. A possible optimisation of that approach would be to sort the edges going out of each node. This will make the selection of an edge take O(V) time instead of O(E), but the sorting of the edges will take O(V * V log V) = O(V^2 log V), so the overall complexiy is O(V^2 log 2) for this approach which is still very slow.</p>
   
- The idea that works best is not to look at all continuations as edges, but as vertices. Instead of searching for the cheapest edges at each iteration, we will search for the vertex that we can reach for the lowest cost. The idea is very similar to the idea of the Dijkstra alorithgm. Instead of keeping the distance to each vertex, we will keep lowest cost of an edge going into the vertex: lowest_cost[]. On each iteration we select the vertex for which the value of lowest_cost[] is minimal and that is unmarked. Let that vertex be v. We add v to the tree, mark it and iterate over all of its neighbours to see if any of them are reachable with a lower cost through v. After V iteration there will be no more unmarked edges and the procedure ends. Each iteration takes O(V) time to select the vertex with the lowest cost => O(V^2) total. All edges are considered at most twice, since each vertex is considered at most once and each edge connects exactly two vertexes => additional O(E) time for the whole procedure. The overall complexity is O(V^2) + O(E), but O(E) = O(V^2) => O(V^2) overall.<br>
   
- If the graph is sparce, then we can again use the same approach as in the Dijkstra alorithgm. We use a heap like structure, but instead of keeping the distance to the vertex we keep we will keep lowest cost of an edge going into the vertex. The overall complexity of this approach is O(E log V). In dense graphs O(E) = O(V^2) and the complexity becomes O(V^2 log V) which is worse that O(V^2) and in this situation the other approach is prefferd.<br>

## Kruskal
- Find the minimum spanning tree of a weighted graph.

- O(E log V) complexity.

- <p> The idea of the agorithm is to add the edges one by one. Each time we add the edge with the lowest cost that connects vertices from different components. This way we start with V components and each time we add an edgethe number of components is decreased by one. Afrer adding V - 1 edges there will be exactly 1 connected component - the minimum spannig tree.<br>
   
   The easiest way to do this is to sort the edges and then try to add each edge consecutively by check with dfs/bfs if the two ends of the edge are in the same component. The overall complexity of this approach is O(E * (V + E)), because we run a dfs/bfs for each edge, which is very slow.<br>
   
   In order to speed this porcess up we will use a data structure knows as Dijoint Set, this approach is also reffered to as Disjoint Set Union (DSU). It is essentially a set of dijoint sets.<br>
   
   The Disjoined Set supports the folowing operations:
   - Add an element to a set.
   - Find which set an element belongs to.
   - Unite two sets.
   
   The sets are sotred a tree, where each element has a parent element. The root of each set is a special case since it has no parent so we can say that it is its own parent.<br>
   
   The sets a deferentiated by their root elements. To check which set a given element bellongs to, we simply traverse trough the parents until we reach the root.<br>
   
   Uniting two sets is done by simply assigning one root as the parent of the other root.<br>
   
   In order to speed up this data strucure we must add two optimisations:
   - Add a weight to each set, that can be either the number of elements, or the depth of the tree of the set. This way we can always attach the sets with the smaller weight to the ones with bigger weight so that when a union is done the depth of the resulting set is with at most 1 more that the depth of the sets that are being united. This is so, because if we unite sets with different depths, the one with lower depth is attached to the one with bigger depth and the overall depth is preserved, but if we unite sets with equal depth then the depth is increased by one because of the edge between the two roots.
   - When traversing trought the parents, while searching for the root of a set, we attach each visited node directly to the root, by changing their parents to the root.
   
   In order to find the minumum spanning tree we will need only the find and unite operations of the Disjoint Set. Each set wil contain the vetrices from one connected component. When considering an edge if both ends are in the same set, then it connects vertices from the same component and must be skiped, otherwise it is added to the tree and the the sets containing both ends are united, since their components are now connected. In the start all verices will be in seperate sets.<br>
   
   The find operation's complexity when ditributed over E calls is an amortized constant O(1) since it's distributed complexity is equivalent to the inverse Ackermann function α, and α(n) <= 5 for any reasonable n. The unite operation's complexity is also O(1) => the overall complexity comes from the sorting of the edges. 
  </p>

## Max flow (Edmonds Karp)
