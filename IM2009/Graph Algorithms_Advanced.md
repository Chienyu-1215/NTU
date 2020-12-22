###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Advanced Graph Algorithms
##  Strongly Connected Components
* A directed graph is **strongly connected** if there is ==a directed path== from every vertex to every other vertex.
* A **strongly connected component (SCC)** is a ==maximal subset== of the vertices such that its induced subgraph is strongly connected (namely, there is no other subset that contains it and induces a strongly connected graph).

![](https://i.imgur.com/QohnyjZ.png)

#### Lemma 1 (7.11). 
Two distinct vertices belong to the same SCC if and only if there is a circuit containing both of them.

#### Lemma 2 (7.12). 
Each vertex belongs to exactly one SCC.  
*All the SCCs of a graph form a partition of the set of vertices of the graph.*

### Algorithm
```cpp=
Algorithm Strongly_Connected_Components(G, n);
begin
    for every vertex v of G do
        v.DFS_Number := 0;
        v.Component := 0;
    Current_Component := 0; DFS_N := n;
    while v.DFS_Number = 0 for some v do
        SCC(v)
end

procedure SCC(v);
begin
    v.DFS_Number := DFS_N;
    DFS_N := DFS_N − 1;
    insert v into Stack;
    v.High := v.DFS_Number;
    for all edges (v, w) do
        if w.DFS_Number = 0 then
            SCC(w);
            v.High := max(v.High, w.High)
        else if w.DFS_Number > v.DFS_Number and w.Component = 0 then 
        //back ede, cross edge to a vertex that has no components
            v.High := max(v.High, w.DFS_Number)
            // max(v.High, w.High) also works
    if v.High = v.DFS_Number then
        Current_Component := Current_Component + 1;
        repeat
            remove x from the top of Stack;
            x.component := Current_Component;
        until x = v
end
```
![](https://i.imgur.com/sRo8SmU.png)

#### Time complexity: $O(|E| + |V|)$.


## Odd-Length Cycles
### Problem 3.
Given a directed graph $G = (V, E)$, determine whether it contains a (directed) cycle of odd length.
* A cycle must reside completely within a strongly connected component (SCC), so we exam each SCC separately.
* Mark the nodes of an SCC with “even” or “odd” using DFS.
* If we have to mark a node that is already marked in the opposite, then we have found an odd-length cycle.


## Biconnected Components
![](https://i.imgur.com/8UUm5Fe.png)

* An **undirected graph** is **biconnected** if there are ==at least two vertex-disjoint paths== from every vertex to every other vertex.
* A graph is not biconnected if and only if there is a vertex whose removal disconnects the graph. Such a vertex is called an articulation point.
* A **biconnected component (BCC)** is a maximal subset of the edges such that its induced subgraph is biconnected (namely, there is no other subset that contains it and induces a biconnected graph).

#### Lemma 4 (7.9). 
Two distinct edges $e$ and $f$ belong to the same BCC if and only if there is a cycle containing both of them.

#### Lemma 5 (7.10). 
Each edge belongs to exactly one BCC.

![](https://i.imgur.com/qgTFTRi.png)

### Algorithm
```cpp=
Algorithm Biconnected_Components(G, v, n);
begin
    for every vertex w do w.DF S Number := 0;
    DFS_N := n;
    BC(v);
end
```
```cpp=
procedure BC(v);
begin
    v.DFS_Number := DFS_N;
    DFS_N := DFS_N − 1;
    insert v into Stack;
    v.High := v.DFS_Number;
    for all edges (v, w) do
        insert (v, w) into Stack;
        if w is not the parent of v then
            if w.DFS_Number = 0 then
                BC(w);
                if w.High ≤ v.DFS_Number then
                    remove all edges and vertices from Stack until v is reached;
                    insert v back into Stack;
                v.High := max(v.High, w.High)
            else
                v.High := max(v.High, w.DF S Number)
                // max(v.High, w.High) would not work, unlike in SCC
end
```


## Network Flows
* Consider a directed graph, or network, $G = (V, E)$ with two distinguished vertices: $s$ (the source) with indegree $0$ and $t$ (the sink) with outdegree $0$.
* Each edge $e$ in $E$ has an associated positive weight $c(e)$, called the **capacity** of $e$
* A **flow** is a function $f$ on $E$ that satisfies the following two conditions:
    1. $0 \le f(e) \le c(e)$.
    2. $\sum_{u}{f(u, v)} = \sum_{w}{f(u, w)$, for all $v \in V - \{ s, t\}$
* The **network flow problem** is to maximize the ﬂow f for a given network $G$.

![](https://i.imgur.com/VzttYom.png)


## Augmenting Paths
An augmenting path w.r.t. a given flow $f$ (of a network $G$) is a directed path from $s$ to $t$ consisting of edges from $G$, but not necessarily in the same diretion; each of these edges $(v, u)$ satisﬁes exactly one of:
1. $(v, u)$ is in the same direction as it is in $G$, and $f(v, u) \lt c(v, u)$. (forward edge)
2. $(v, u)$ is in the opposite direction in $G$ (namely, $(u, v) \in E)$, and $f(u, v) \gt 0$. (backward edge)

* If there exists an augmenting path w.r.t. a flow $f$ ($f$ admits an augmenting path), then $f$ is not maximum.

![](https://i.imgur.com/qbJy42W.png)
![](https://i.imgur.com/koIwNZy.png)


## Properties of Network Flows
#### Theorem 8 (Augmenting-Path). 
A flow $f$ is maximum if and only if it admits no augmenting path.  

A **cut** is a set of edges that separate $s$ from $t$, or more precisely a set of the form $\{(v, w) \in E |
v \in A and w \in B\}$, where $B = V − A$ such that $s \in A$ and $t \in B$.

#### Theorem 10 (Integral-Flow). 
If the capacities of all edges in the network are integers, then there is a maximum ﬂow whose value is an integer.


## Residual Graphs
The residual graph with respect to a network $G = (V, E)$ and a flow $f$ is the network $R = (V, F)$, where $F$ consists of all forward and backward edges and their capacities are given as follows:
1. $c_R(v, w) = c(v, w) − f(v, w)$ if $(v, w)$ is a forward edge and
2. $c_R(v, w) = f(w, v)$ if $(v, w)$ is a backward edge.
* An augmenting path is thus a regular directed path from $s$ to $t$ in the residual graph.

![](https://i.imgur.com/rTgeTY7.png)
