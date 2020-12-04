###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Graph Algorithms: Basic
## The Konigsberg Bridges Problem 七橋問題
Source: <a href = "https://zh.wikipedia.org/wiki/%E6%9F%AF%E5%B0%BC%E6%96%AF%E5%A0%A1%E4%B8%83%E6%A1%A5%E9%97%AE%E9%A2%98">Wikipedia </a>
![](https://i.imgur.com/CRc9OGy.png)
![](https://i.imgur.com/DlxnBu2.png)


## Graphs
Source: <a href = "https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)">Wikipedia </a>
 A graph consists of ==a set of vertices (or nodes) and a set of edges (or links, each normally connecting two vertices)==.
* A graph is commonly denoted as $G(V, E)$, where
    * $G$ is the name of the graph,
    * $V$ is the set of vertices, and
    * $E$ is the set of edges.

### Types of Graphs
* **Undirected 有向圖 vs. Directed Graph 無向圖**
    *Determined by whether the edges have directions or not*
* **Simple Graph vs. Multigraph**
    *In a multigraph, multiple edges are allowed between a pair of vertices; the edges are not labeled (and thus cannot be distinguished).*
    *兩個點之間，只能有一個邊/有多個邊*
* **Path, Simple Path, Trail**
    *Path often really means simple path (also called open path), where ==all vertices are distinct==. Trail is just another name for path, but strongly suggests that it may be ==a cycle== (also called ==closed path==, where the start and the end vertices are the only repeated vertices).*
    *Trail: A general path*
* **Circuit, Cycle**
    *Circuit: 終點和出發點一樣*
    *Cycle: 除了終點和出發點一樣外，中間經過的點都不重複。*
* Degree, In-Degree, Out-Degree
    *Degree: the number of edges connected to one single vertex.*
    *In-Degree: the number of directed edges connected to one single vertex.*
    *Out-Degree: the number of directed edges connected from one single vertex.*
* <a href ="https://zh.wikipedia.org/wiki/%E8%BF%9E%E9%80%9A%E5%9B%BE">Connected Graph</a>, Connected Components
* **Tree, Forest**
Source: <a href = "http://web.ntnu.edu.tw/~algo/SpanningTree.html"> Tree </a>
* **Subgraph, Induced Subgraph**
    *A vertex-induced subgraph must include every edge in the original graph that connects a pair of the selected vertices.*
* <a href="https://en.wikipedia.org/wiki/Spanning_tree">Spanning Tree</a>, Spanning Forest
    樹狀結構是沒有cycle的連通圖
* Weighted Graph


## Modeling with Graphs
* **Reachability 可達性**
    * *Example: Is it possible to visit $A$ from $B$?*
    * Finding program errors
        *A program state corresponds to a vertex and there is a directed edge from one vertex to another if the program represented by the first vertex may (in one execution step) become the program state represented by the second vertex.*
    * Solving sliding tile puzzles
        *A conﬁguration of the sliding tiles corresponds to a vertex and there is a directed edge from one vertex to another if the configuration represented by the ﬁrst vertex may (in one sliding step) become the conﬁguration represented by the second vertex.*
* **Shortest Paths 最短路徑**
    * Finding the fastest route to a place
    * Routing messages in networks
* Graph Coloring
    * Coloring maps
    * Scheduling classes


## <a href="https://en.wikipedia.org/wiki/Eulerian_path"><font color = "black">Eulerian Graphs</font></a>
### Problem
Given an undirected connected graph $G = (V , E )$ such that all the vertices have **even degrees**, ﬁnd a circuit $P$ such that each edge of $E$ appears in P exactly once.  

The circuit $P$ in the problem statement is called an **Eulerian circuit.**

### Theorem
An undirected connected graph has an Eulerian circuit ==if and only if== all of its vertices have **even degrees**. 每個節點的Degree都要是偶數。

### Proof
**Base Case**  
Must be a simple cycle.  

**Inductive Steps**
A graph that contain several Eulerian circuits. 


## Depth-First Search
![](https://i.imgur.com/ANoFYti.png)
![](https://i.imgur.com/kp5LxPU.png)

### Algorithm
```cpp=
Algorithm Depth_First_Search(G, v);
begin
    mark v;
    perform preWORK on v;
    for all edges (v, w) do
        if w is unmarked then
            Depth_First_Search(G, w);
        perform postWORK for (v, w)
end
```
```cpp=
Algorithm Refined_DFS(G, v);
begin
    mark v;
    perform preWORK on v;
    for all edges (v, w) do
        if w is unmarked then
            Refined_DFS(G, w);
        perform postWORK for (v, w);
    perform postWORK II on v
end
```

### Connected Components
```cpp=
Algorithm Connected_Components(G);
begin
    Component Number := 1;
    while there is an unmarked vertex v do
        Depth_First_Search(G, v)
        (preWORK:
            v.Component := Component Number);
        Component Number := Component Number + 1
end
```
#### Time Complexity = $O(|E| + |V|)$

### DFS Numbers
```cpp=
Algorithm DFS_Numbering(G, v);
begin
    DFS_Number := 1;
    Depth_First_Search(G, v)
    (preWORK:
    v.DFS := DFS_Number;
    DFS_Number := DFS_Number + 1)
end
```
#### Time Complexity = $O(|E|)$
$E \ge V - 1$

### The DFS Tree
```cpp=
Algorithm Build_DFS_Tree(G, v);
begin
    Depth_First_Search(G, v)
    (postWORK:
        if w was unmarked then
            add the edge (v, w) to T );
end
```
![](https://i.imgur.com/FPBp1Aa.png)

#### Lemma 3 (7.2). 
For an **undirected graph** $G = (V, E)$, every edge $e \in E$ either belongs to the DFS tree $T$, or connects two vertices of $G$, one of which is ==the ancestor of the other in $T$==.  

For undirected graphs, DFS avoids **cross edges**.

#### Lemma 4 (7.3). 
For a **directed graph** $G = (V, E)$, if $(v, w)$ is an edge in $E$ such that $v.DFS\_Number \lt w.DFS\_Number$, then $w$ is a descendant of $v$ in the DFS_tree $T$ .


## Directed Cycles
![](https://i.imgur.com/GhLjnEJ.png)
<font color='Tomato'>Back Edge</font>: An edge $(v, w)$ where $v$ is the descendant of $w$.
<font color = "DeepPink">Cross Edge</font>: An edge $(v, w)$ where $v$ and $w$ have same ancestors.
<font color = 'Cyan'>Forward Edge</font>:  An edge $(v, w)$ where $w$ is the descendant of $v$.
### Problem 
Given a directed graph $G = (V, E)$, determine whether it contains a (directed) cycle.

#### Lemma 6 (7.4).
$G$ contains a **directed cycle** if and only if ==$G$ contains a back edge== (relative to the DFS_tree).

### Find a Cycle
```cpp=
Algorithm Find_a_Cycle(G);
begin
    Depth_First_Search(G, v) /* arbitrary v */
    (preWORK:
        v.on_the_path := true;
    postWORK:
        if w.on_the_path then
            Find_a_Cycle := true;
            halt;
        if w is the last vertex on v’s list then
            v.on_the_path := false;)
end
```
```cpp=
Algorithm Refined_Find_a_Cycle(G);
begin
    Refined_DFS(G, v) /* arbitrary v */
    (preWORK:
        v.on_the_path := true;
    postWORK:
        if w.on_the_path then
            Refined_Find_a_Cycle := true;
            halt;
    postWORK II:
        v.on_the_path := false)
end
```


## Breadth-First Search
![](https://i.imgur.com/IAQ00JM.png)

### Algorithm
```cpp=
Algorithm Breadth_First_Search(G, v);
begin
    mark v;
    put v in a queue;
    while the queue is not empty do
        remove vertex w from the queue;
        perform preWORK on w;
        for all edges (w, x) with x unmarked do
            mark x;
            add (w, x) to the BFS tree T ;
            put x in the queue
end
```

#### Lemma 7 (7.5).
If an edge $(u, w)$ belongs to a BFS tree such that $u$ is a parent of $w$, then $u$ has the minimal BFS number among vertices with edges leading to $w$.

#### Lemma 8 (7.6).
For each vertex $w$, the path from the root to $w$ in $T$ is a shortest path from the root to $w$ in $G$.

#### Lemma 9 (7.7).
If an edge $(v, w)$ in $E$ does not belong to $T$ and $w$ is on a larger level, then the level numbers of $w$ and $v$ differ by at most $1$.

### Simple BFS
![](https://i.imgur.com/sAYNlHW.png)

|1|
|-|
|==1==,2,3,4|
|==1==,==2==,3,4,5|
|==1==,==2==,==3==,4,5,6|
|==1==,==2==,==3==,==4==,5,6,7|
|==1==,==2==,==3==,==4==,==5==,6,7|
|==1==,==2==,==3==,==4==,==5==,==6==,7|
|==1==,==2==,==3==,==4==,==5==,==6==,==7==|
```cpp=
Algorithm Simple_BFS(G, v);
begin
    put v in Queue;
    while Queue is not empty do
        remove vertex w from Queue;
        if w is unmarked then
            mark w; 
            perform preWORK on w;
            for all edges (w, x) with x unmarked do
                put x in Queue
end
```

### Simple Nonrecursive DFS
```cpp=
Algorithm Simple_Nonrecursive_DFS(G, v);
begin
    push v to Stack;
    while Stack is not empty do
        pop vertex w from Stack;
    if w is unmarked then
        mark w;
        perform preWORK on w;
    for all edges (w, x) with x unmarked do
        push x to Stack
end
```


## <a href="https://en.wikipedia.org/zh-tw/%E6%8B%93%E6%92%B2%E6%8E%92%E5%BA%8F"><font color = "black">Topological Sorting 拓蹼排序</font></a>
### Problem 10
Given a directed acyclic graph $G = (V, E)$ with $n$ vertices, label the vertices from $1$ to $n$ such that, if $v$ is labeled $k$, then all vertices that can be reached from $v$ by a directed path are labeled with labels $\gt k$.

#### Lemma 11 (7.8). 
A directed acyclic graph always contains a vertex with indegree $0$.

### Algorithm
```cpp=
Algorithm Topological_Sorting(G);
    initialize v.indegree for all vertices; /*by DFS*/
    G_label := 0;
    for i := 1 to n do
        if v_i.indegree = 0 then put v_i in Queue;
    repeat
        remove vertex v from Queue;
        G_label := G_label + 1;
        v.label := G_label;
        for all edges (v, w) do
            w.indegree := w.indegree − 1;
            if w.indegree = 0 then put w in Queue
    until Queue is empty
```


## Shortest Paths
### Single-Source Shortest Paths
### Problem 12
Given a directed graph $G = (V, E)$ and a vertex $v$, ﬁnd shortest paths from $v$ to all other vertices of $G$.

### Shorted Paths: The Acyclic Case
```cpp=
Algorithm Acyclic_Shortest_Paths(G, v, n);
{Initially, w.SP = ∞, for every node w.}
{A topological sort has been performed on G, . . .}
begin
    let z be the vertex labeled n;
    if z is not equal to v then
        Acyclic_Shortest_Paths(G − z, v, n − 1);
        for all w such that (w, z) ∈ E do
            if w.SP + length(w, z) < z.SP then
                z.SP := w.SP + length(w, z)
    else v.SP := 0
end
```
#### Nonrecursive Way
```cpp=
Algorithm Imp_Acyclic_Shortest_Paths(G, v);
    for all vertices w do w.SP := ∞;
    initialize v.indegree for all vertices;
    for i := 1 to n do
        if v_i.indegree = 0 then put v_i in Queue;
    v.SP := 0;
    repeat
        remove vertex w from Queue;
        for all edges (w, z) do
            if w.SP + length(w, z) < z.SP then
                z.SP := w.SP + length(w, z);
            z.indegree := z.indegree − 1;
            if z.indegree = 0 then put z in Queue
    until Queue is empty
```

### Shortest Paths: The General Case
```cpp=
Algorithm Single_Source_Shortest_Paths(G, v);
// Dijkstra’s algorithm
begin
    for all vertices w do
        w.mark := false;
        w.SP := ∞;
    v.SP := 0;
    while there exists an unmarked vertex do
        let w be an unmarked vertex s.t. w.SP is minimal;
        w.mark := true;
        for all edges (w, z) such that z is unmarked do
            if w.SP + length(w, z) < z.SP then
                z.SP := w.SP + length(w, z)
end
```
Dijkstra’s algorithm assumes that the weight of every edge is non-negative. Given the assumption, going from the source vertex $v$ to some other vertex $w$ will never need to pass any other vertex farther than $w$. So, the algorithm determines one at a time (the lengths of) the paths to the $1-st, 2-nd, · · · , n-th$ the closest vertices (including the source vertex) from the source vertex.
#### Time Complexity
The main loop requires $O(|V|)$ iterations. In each iteration, there is a delete operation on the heap, which takes $O(\log |V|)$ time. The for loop incurs a total of $O(|E|)$ updates to the heap, each taking $O(\log |V|)$ time.  
$O((|E| + |V|)\log|V|)$
![](https://i.imgur.com/Fo3jAf5.png)
![](https://i.imgur.com/k9Un8cR.png)


## Minimum-Weight Spanning Trees
### Problem 13
Given an undirected connected weighted graph $G = (V, E)$, find a spanning tree $T$ of $G$ of minimum weight.

### Theorem
Let $V_1$ and $V_2$ be a partition of $V$ and $E(V_1, V_2)$ be the set of edges connecting nodes in $V_1$
to nodes in $V_2$. The **edge with the minimum weight** in $E(V_1, V_2)$ must be in the minimum-cost spanning tree
of $G$.  

![](https://i.imgur.com/a477btx.png)

### Algorithm
```cpp=
Algorithm MST(G);
// A variant of Prim’s algorithm
begin
    initially T is the empty set;
    for all vertices w do
        w.mark := false; w.cost := ∞;
        let (x, y) be a minimum cost edge in G;
    x.mark := true;
    for all edges (x, z) do
        z.edge := (x, z); 
        z.cost := cost(x, z);
    while there exists an unmarked vertex do
        let w be an unmarked vertex with minimal w.cost;
        if w.cost = ∞ then
            print "G is not connected"; halt
        else
            w.mark := true;
            add w.edge to T;
            for all edges (w, z) do
                if not z.mark then
                    if cost(w, z) < z.cost then
                        z.edge := (w, z); 
                        z.cost := cost(w, z);
end
```
```cpp=
Algorithm Another MST(G);
// Prim’s algorithm
begin
    initially T is the empty set;
    for all vertices w do
        w.mark := false; w.cost := ∞;
    x.mark := true; /* x is an arbitrary vertex */
    for all edges (x, z) do
        z.edge := (x, z); z.cost := cost(x, z);
    while there exists an unmarked vertex do
        let w be an unmarked vertex with minimal w.cost;
        if w.cost = ∞ then
            print “G is not connected”; halt
        else
            w.mark := true;
            add w.edge to T;
            for all edges (w, z) do
                if not z.mark then
                    if cost(w, z) < z.cost then
                        z.edge := (w, z);
                        z.cost := cost(w, z);
end
```
![](https://i.imgur.com/AOId63o.png)


## All Shortest Paths
### Problem 15 
Given a weighted graph $G = (V, E)$ (directed or undirected) with **nonnegative** weights, find the minimum-length paths between all pairs of vertices.

### Floyd's Algorithm
```cpp=
Algorithm All_Pairs_Shortest_Paths(W);
begin
    {initialization}
    for i := 1 to n do
        for j := 1 to n do
            if (i, j) ∈ E then W[i, j] := length(i, j)
            else W [i, j] := ∞;
    for i := 1 to n do W [i, i] := 0;

    for m := 1 to n do {the induction sequence}
        for x := 1 to n do
            for y := 1 to n do
                if W [x, m] + W [m, y] < W[x, y] then
                    W [x, y] := W [x, m] + W [m, y]
end
```