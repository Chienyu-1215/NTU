###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Design by Induction
## Introduction
* It is **not** necessary to design the steps required to solve a problem *from scratch*.
* It is sufficient to guarantee the following:
1. It is possible to solve one small instance or a few small instances of the problem. (base case)
2. A solution to every problem/instance can be constructed from solutions to smaller problems/instances. (inductive step)


## Evaluating Polynomials
### Problem
Given a sequence of real numbers $a_n, a_{n-1},.., a_1, a_0$, and a real number $x$, compute the value of the polynomial $$P_n(x) = a_n x^n + a_{n - 1} x^{n - 1} + ... + a_1 x + a_0 $$ 
***
**Motivation**:
**different approaches to the inductive step** may result in algorithms of very **different time complexities**.

Let $P_{n - 1}(x) = a_{n - 1} x^{n - 1} + ... + a_1 x + a_0$:

### Induction Hypothesis
**#1**
We know how to evaluate a polynomial represented by the input $a_{n - 1}, ... , a_1, a_0$, at the point $x$, i.e., we know how to compute $P_{n - 1}(x)$.
$P_n(x) = a_n x^n + P_{n - 1}(x)$
Number of multiplications:
$n + (n - 1) + ... + 2 + 1 = \frac{n(n + 1)}{2}$

**#2**
* We know how to compute $P_{n - 1}(x)$, and we know how to compute $x^{n - 1}$.
* Number of multiplication: $2n - 1$

**#3**
* Let $P'(x) = a_n x^{n - 1} + a_{n - 1} x^{n - 2} + ... + a_1$
* We know how to evaluate a polynomial represented by the coefficients $a_n, a_{n - 1},..., a_1$ at the point $x$, i.e., we know how to compute $P'_{n - 1}(x).
* $P_n(x) = P_n'(x) = P_{n - 1}'(x) \times x + a_0$
* More generally, $$\left\{\begin{array}{} P_0'(x) = a_n \\ P_i'(x) = P_{i - 1}''(x) x + a_{n - 1} \quad \mbox{for } 1 \le i \le n \end{array}\right.$$
* Number of multiplication: $n$

### Algorithms
![](https://i.imgur.com/gM9pY5O.png)


## Maximal Induced Subgraph
### Problem
Given an undirected graph $G = (V , E)$ and an integer $k$, find an **induced subgraph**(Choose some vertices and remain the edges connect between those chosen in $G$) $H = (U , F)$ of $G$ of maximum size such that all vertices of $H$ have degree $\ge k$ (in $H$), or conclude that no such induced subgraph exists.
***
**Design Idea**:
in the inductive step, we try to remove one vertex (that cannot possibly be part of the solution) to get a smaller instance.

### Algorithms
![](https://i.imgur.com/5M09maQ.png)
**Base Case** are required to mention.
* 排除點的順序會影響結果嗎？ 不會


## One-to-One Mapping
### Problem
Given a finite set $A$ and a mapping $f$ from $A$ to itself, find a subset $S \subseteq A$ with the maximum number of elements, such that
1. the function $f$ maps every element of $S$ to another element of $S$ (i.e., $f$ maps $S$ into itself), and
2. no two elements of $S$ are mapped to the same element (i.e., $f$ is one-to-one when restricted to $S$).
***
**Design Idea**: 
similar to the previous problem; in the inductive step, we try to ==remove one element== (that cannot possibly be part of the solution) to get a smaller instance.

An element that is not mapped to may be removed.

### Algorithms
![](https://i.imgur.com/owPwyn6.png)


## Celebrity
### Problem
Given an $n \times n$ adjacency matrix, determine whether there exists an $i$ (the **celebrity**) such that all the entries in the $i -th$ column (except for the $ii -th$ entry) are $1$, and all the entries in the $i -th$ row (except for the $ii -th$ entry) are $0$.
***
*Note* 
* A celebrity corresponds to a **sink** of the directed graph.
    * **sink** : every node collect to the celebrity while there are no edges collect from the celebrity.
* Every directed graph has **at most one** sink.

**Motivation**: 
the trivial solution has a time complexity of $O(n^2)$. Can we do better, in $O(n)$?

* Basic idea: check whether $i$ knows $j$.
    In either case, one of the two may be eliminated.
* The $O(n)$ algorithm proceeds in two stages:
    * Eliminate a node every round until only one is left.
    * Check whether the remaining one is truly a celebrity.

### Algorithms
![](https://i.imgur.com/wu15PJT.png)
![](https://i.imgur.com/ForGdWh.png)


## The Skyline Problem
### Problem
Given the exact locations and shapes of several rectangular buildings in a city, draw the skyline (in two dimension) of these buildings, eliminating hidden lines.
***
**Motivation**:
different approaches to the inductive step may result in algorithms of very different time complexities.
**Compare**: 
*adding buildings* one by one to an existing skyline vs. *merging two skylines* of about the same size

### Mathematical Analysis
![](https://i.imgur.com/myvLmL5.png)
Input: $(1,11,5), (2,6,7), (3,13,9), (12,7,16), (14,3,25), (19,18,22), (23,13,29), (24,4,28)$.
![](https://i.imgur.com/8MBEVV9.png)


## Balance Factors in Binary Trees
### Problem
Given a binary tree $T$ with $n$ nodes, compute the balance factors of all nodes.
***
The balance factor of a node is defined as the difference between the
height of the node’s left subtree and the height of the node’s right
subtree.
**Motivation**
an example of why we must ==strengthen the hypothesis==
(and hence the problem to be solved).
![](https://i.imgur.com/SF43QwM.png)

### Induction Hypothesis
We know how to compute balance factors of all nodes in trees that have $\lt n$ nodes.

### Stronger induction hypothesis
We know how to compute balance factors and heights of all nodes in trees that have $\lt n$ nodes.


## Maximum Consecutive Subsequence
### Problem
Given a sequence $x_1, x_2,..., x_n$ of real numbers (not necessarily positive) find a subsequence $x_i
, x_{i+1},..., x_j$ (of consecutive elements) such that the sum of the numbers in it is maximum over all subsequences of consecutive elements.
***
**Motivation**
another example of strengthening the hypothesis.

### Induction hypothesis
We know how to find the maximum subsequence in sequences of size $\lt n$.

### Stronger induction hypothesis
We know how to find, in sequences of size < n, the maximum subsequence overall and ==the maximum subsequence that is a suffix==.
*Reasoning* 
the maximum subsequence of problem size n is obtained either
* directly from the maximum subsequence of problem size $n − 1$ or
* from appending the $n-th $element to the maximum suffix of problem size $n − 1$.

### Algorithm
![](https://i.imgur.com/GdzGVpq.png


## The Knapsack Problem
### Problem
Given an integer $K$ and $n$ items of different sizes such that the $i-th$ item has an integer size $k_i$, find a subset of the items whose sizes sum to exactly $K$, or determine that no such subset exists.
***
**Design Idea** 
use strong induction so that solutions to all smaller instances may be used.

Let $P(n,K)$ denote the problem where $n$ is the number of items and $K$ is the size of the knapsack. 

### Induction hypothesis
We know how to solve $P(n − 1,K)$.

### Stronger induction hypothesis
We know how to solve $P(n − 1, k)$, for all $0 \le k \le K$.
Reasoning: $P(n,K)$ has a solution if either 
* $P(n − 1,K)$ has a solution or 
* $P(n − 1,K − k_n)$ does, provided $K − k_n \ge 0$.
![](https://i.imgur.com/nIZQUBr.png)

### Algorithm
![](https://i.imgur.com/D8HZhDM.png)
$O(nK) \Rightarrow O(n 2^{\log_2 K})$