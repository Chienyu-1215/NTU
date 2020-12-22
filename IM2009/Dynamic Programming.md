###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Dynamic Programming
## Design Methods
* Greedy
    * Huffman’s encoding algorithm, Dijkstra’s algorithm, Prim’s algorithm, etc.
* Divide-and-Conquer
    * Binary search, merge sort, quick sort, etc.
* Dynamic Programming
* Branch-and-Bound


## Dynamic Programming
### Principles of Dynamic Programming
* Property of Optimal Substructure (Principle of Optimality):
    An ==optimal solution to a problem== contains optimal solutions to its subproblems.
* A particular subproblem or subsubproblem typically recurs while one tries diﬀerent decompositions of the original problem.
* To reduce running time, optimal solutions to subproblems are computed only once and stored (in an array) for subsequent uses.

### Development by Dynamic Programming
1. Characterize the structure of an optimal solution.
2. Recursively deﬁne the value of an optimal solution.
3. Compute the value of an optimal solution in a bottom-up fashion.
4. Construct an optimal solution from computed information.


## Matrix-Chain Multiplication
### Problem
Given a chain $A_1, A_2, ..., A_n$ of matrices where $A_i , 1 \le i \le n$, has dimension $p_{i − 1} \times p_i$ , fully parenthesize (i.e., find a way to evaluate) the product $A_1A_2 ... A_n$ such that the number of scalar multiplications is minimum.
***
* Why is dynamic programming a feasible approach?
* To evaluate $A_1A_2 ... A_n$, one ﬁrst has to evaluate $A_1A_2 ... A_k$ and $A_{k + 1}A_{k + 2} ... A_n$ for some $k$ and then multiply the two resulting matrices.
* An optimal way for evaluating $A_1A_2···A_n$ must contain optimal ways for evaluating $A_1A_2 ... A_k$ and $A_{k + 1}A_{k + 2} ... A_n$ for some $k$.

![](https://i.imgur.com/SKcSpLx.png)

### Algorithm
```cpp=
Algorithm Matrix_Chain_Order(n, p);
begin
    for i := 1 to n do
        m[i, i] := 0;
    for l := 2 to n do { l is the chain length }
        for i := 1 to (n − l + 1) do
            j := i + l − 1;
            m[i, j] := ∞;
            for k := i to (j − 1) do
                if m[i, k] + m[k + 1, j] + p[i − 1]p[k]p[j] < m[i, j] then
                    m[i, j] := m[i, k] + m[k + 1, j] + p[i − 1]p[k]p[j]
end
```

#### Using Recursion
```cpp=
Algorithm Recursive_Matrix_Chain(p, i, j);
begin
    if i = j then return 0;
        m[i, j] := ∞;
    for k := i to (j − 1) do
        q := Recursive_Matrix_Chain(p, i, k) + Recursive_Matrix_Chain(p, k + 1, j) + p[i − 1]p[k]p[j];
        if q < m[i, j] then
            m[i, j] := q;
    return m[i, j]
end
```

#### Recursion with Memoization
```cpp=
Algorithm Memoized_Matrix_Chain(n, p);
begin
    for i := 1 to n do
        for j := i to n do
            m[i, j] := ∞;
    return Lookup_Matrix_Chain(p, 1, n)
end

Function Lookup_Matrix_Chain(p, i, j);
begin
    if m[i, j] < ∞ then return m[i, j];
    if i = j then
        m[i, j] := 0;
    else
        for k := i to (j − 1) do
            q := Lookup_Matrix_Chain(p, i, k) + Lookup_Matrix_Chain(p, k + 1, j) + p[i − 1]p[k]p[j];
        if q < m[i, j] then
            m[i, j] := q;
    return m[i, j]
end
```


## Single-Source Shortest Paths
### Problem 2. 
Given a weighted directed graph $G = (V, E)$ with no negative-weight cycles and a vertex $v$, find (the lengths of) the shortest paths from $v$ to all other vertices.
***
* Notice that edges with negative weights are permitted; so, Dijkstra’s algorithm does not work here.
* A shortest path from $v$ to any other vertex $u$ contains at most $n − 1$ edges.
* A shortest path from $v$ to $u$ with at most $k (\gt 1)$ edges must be composed of a ==shortest path from $v$ to $u′$== with at most $k − 1$ edges and the edge from $u′$ to $u$, for some $u′$.

![](https://i.imgur.com/5MqqKb1.png)

### Algorithm
```cpp=
Algorithm Single_Source_Shortest_Paths(length);
begin
    D[v] := 0;
    for all u != v do
        if (v, u) ∈ E then
            D[u] := length(v, u)
        else D[u] := ∞;
    for k := 2 to n − 1 do
        for all u != v do
            for all u′ such (u′, u) ∈ E do
                if D[u′] + length[u′, u] < D[u] then
                    D[u] := D[u′] + length[u′, u]
end
```
```cpp=
Algorithm Single_Source_Shortest_Paths_withL(length);
begin
    D[1][v] := 0;
    for all u != v do
        if (v, u) ∈ E then
            D[1][u] := length(v, u)
        else D[1][u] := ∞;
    for l := 2 to n − 1 do
        for all u != v do
            D[l][u] := D[l − 1][u];
            for all u′ such (u′, u) ∈ E do
                if D[l − 1][u′] + length[u′, u] < D[l][u] then
                    D[l][u] := D[l − 1][u′] + length[u′, u]
end
```



## All-Pairs Shortest Paths
### Problem 3. 
Given a weighted directed graph $G = (V, E)$ with no negative-weight cycles, find (the lengths of) the shortest paths between all pairs of vertices.
***
* Consider a shortest path from $v_i$ to $v_j$ and an arbitrary intermediate vertex $v_k$ (if any) on this path.
* The subpath from $v_i$ to $v_k$ must also be a shortest path from $v_i$ to $v_k$; analogously for the subpathfrom $v_k$ to $v_j$.  

![](https://i.imgur.com/IbZHjW3.png)

### Algorithm
```cpp=
Algorithm All_Pairs_Shortest_Paths(length);
begin
    for i := 1 to n do
        for j := 1 to n do
            if (i, j) ∈ E then W[i, j] := length(i, j)
            else W [i, j] := ∞;
    for i := 1 to n do W [i, i] := 0;
    for k := 1 to n do
        for i := 1 to n do
            for j := 1 to n do
                if W[i, k] + W [k, j] < W[i, j] then
                    W[i, j] := W [i, k] + W [k, j]
end
```

```cpp=
Algorithm All_Pairs_Shortest_Paths_withK(length);
begin
    for i := 1 to n do
        for j := 1 to n do
            if (i, j) ∈ E then W[0][i, j] := length(i, j)
            else W[0][i, j] := ∞;
    for i := 1 to n do W[0][i, i] := 0;
    for k := 1 to n do
        W[k][i, j] := W[k − 1][i, j];
    for i := 1 to n do
        for j := 1 to n do
            if W[k − 1][i, k] + W[k − 1][k, j] < W[k][i, j] then
                W[k][i, j] := W[k − 1][i, k] + W[k − 1][k, j]
end
```