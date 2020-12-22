###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Reduction
## Introduction
* The basic idea of **reduction** is to solve a problem with the solution to another “similar” problem.
* When Problem A can ==be reduced 轉化 (efficiently) to== Problem B, there are two consequences:
    * A solution to Problem B may be used to solve Problem A.
    * If A is known to be “hard”, then B is also necessarily “hard”.
    * *It's possible that two problems can be reduced to each other.*
* One should avoid the pitfall of reducing a problem to another that is too general or too hard.


## Bipartite Matching
### Matching
* Given an undirected graph $G = (V, E)$, a **matching** is a set of edges that do not share a common vertex.
* A ==maximum 最大 matching== is one with the maximum number of edges.
* A ==maximal 極大 matching== is one that cannot be extended by adding any other edge.

### Bipartite Matching
A **bipartite graph** $G = (V, E, U)$ is a graph with $V \cup U$ as the set of vertices and $E$ as the set of edges such that
* $V$ and $U$ are ==disjoint== and 
* The edges in $E$ connect vertices from $V$ to vertices in $U$.

### Problem 1. 
Given a bipartite graph $G = (V, E, U)$, find a maximum matching in $G$.
![](https://i.imgur.com/bmZlphR.png)

#### Maximal Matching and Maximum Matching
![](https://i.imgur.com/SO93YP0.png)


## Network Flows
### Networks
* Consider a directed graph, or network, $G = (V, E)$ with two distinguished vertices: $s$ (the source) with indegree $0$ and $t$ (the sink) with outdegree $0$.
* Each edge $e$ in $E$ has an associated positive weight $c(e)$, called the capacity of $e$.

### The Network Flow Problem
* A flow is a function $f$ on $E$ that satisﬁes the following two conditions:
    1. $0 \le f(e) \le c(e)$.
    2. $\sum_{u}{f(u, v)} = \sum_{w}{f(v, w)}$, for all $v \in V − \{s, t\}$.
* The network flow problem is to maximize the flow $f$ for a given network $G$.


## Bipartite Matching to Network Flow
![](https://i.imgur.com/L3U4g01.png)
![](https://i.imgur.com/gNiaHHJ.png)


## Linear Programming
### Notations
![](https://i.imgur.com/H7MHOXD.png)

### Linear Programming
![](https://i.imgur.com/cktuo62.png)
* Integer Linear Programming: 取整數


## Network Flow to Linear Programming
![](https://i.imgur.com/MKEjpsH.png)
