###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: NP-Completeness
## P v.s. NP
https://people.cs.nctu.edu.tw/~chengchc/Course_2011_Spr_DS/DS_08_NPC.pdf
* $P$ denotes the class of all problems that can be solved by ==**deterministic algorithms 決定式演算法** in polynomial time==.
* $NP$ denotes the class of all problems that can be solved by ==**nondeterministic algorithms 非決定式**== in polynomial time.
    * Alternativley, NP problems may be defined as those whose positive solutions can be verified (using a deterministic algorithm) in polynomial time. 
* A **nondeterministic** algorithm, when faced with a choice of several options, has the power to guess the right one (if there is any).
    * 遇到選擇，可以表述其選擇情形
    * Without loss of generality, you may assume that it is always a choice between two options. 
* We will focus on decision problems, whose answer is either yes or no.

![](https://i.imgur.com/tdFw9Eb.png)


## Polynomial-Time Reductions
### Decision as Language Recognition
* A decision problem can be viewed as a language-recognition problem.
* Let $U$ be the set of all possible inputs to the decision problem and $L ⊆ U$ be the set of all inputs for which the answer to the problem is yes.
    * Every input is in essence a string. 
* We call $L$ the language corresponding to the problem.
* • The decision problem is to recognize whether a given input belongs to $L$.

### Polynomial-Time Reduction
![](https://i.imgur.com/skzsuvg.png)

#### Theorem 1 (11.1). 
If $L_1$ is polynomially reducible to $L_2$ and there is a polynomial-time algorithm for $L_2$, then there is a polynomial-time algorithm for $L_1$.

#### Theorem 2 (11.2: transitivity). 
If $L_1$ is polynomially reducible to $L_2$ and $L_2$ is polynomially reducible to $L_3$, then $L_1$ is polynomially reducible to $L_3$.


##  NP-Completeness
https://bluelove1968.pixnet.net/blog/post/222283186
* A problem $X$ is called an **NP-hard** problem if every problem in NP is polynomially reducible to $X$.
* A problem $X$ is called an **NP-complete** problem if (1) $X$ belongs to NP, and (2) $X$ is NP-hard.

#### Lemma 3(11.3)
A problem $X$ is an NP-complete problem if (1) $X$ belongs to NP, and (2') $Y$ is polynomially reducible to $X$, for some NP-complete problem $Y$ .

***
If there exists an efficient (polynomial-time) algorithm for any NP-complete problem, then there exist efficient algorithms for all NP-complete (and hence all NP) problems.



## The SAT Problem
### The Satisfiability Problem (SAT)
#### Problem 4. 
Given a **Boolean expression** in conjunctive normal form, determine whether it is satisfiable.
***
* A Boolean expression is in **conjunctive normal form** (CNF) if it is the product of several sums, e.g., $(x + y + \bar{z})·(\bar{x} + y + z)·(\bar{x} + \bar{y} + \bar{z})$.
*  A Boolean expression is said to be **satisfiable** if there exists an assignment of $0$s and $1$s to its variables such that the value of the expression is $1$.

#### Theorem 5 (Cook’s Theorem). 
The SAT problem is NP-complete.
* This is our starting point for showing the NP-completeness of some other problems.
* Their NP-hardness will be proved by reduction directly or indirectly from SAT.

![](https://i.imgur.com/ey5wiEO.png)


## Vertex Cover
https://en.wikipedia.org/wiki/Vertex_cover
* A vertex cover of $G$ is a set of vertices such that every edge in $G$ is incident to at least one of these vertices.

### Problem 6. 
Given an undirected graph $G = (V, E)$ and an integer $k$, determine whether $G$ has a vertex cover containing $\le k$ vertices.

#### Theorem 7 (11.4). 
The vertex-cover problem is NP-complete.
* Main idea: by reduction from the **clique** problem.


## Dominating Set
https://en.wikipedia.org/wiki/Dominating_set
### Problem 8. 
Given an undirected graph $G = (V, E)$ and an integer $k$, determine whether $G$ has a dominating set containing $\le k$ vertices.
***
A dominating set $D$ is a set of vertices such that every vertex of $G$ is either in $D$ or is adjacent to some vertex in D.

#### Theorem 9 (11.5). 
The dominating-set problem is NP-complete.

![](https://i.imgur.com/gbZlH1J.png)


## 3SAT
https://en.wikipedia.org/wiki/Boolean_satisfiability_problem#3-satisfiability
### Problem 10. 
Given a Boolean expression in CNF such that each clause contains exactly three variables, determine whether it is satisfiable.

#### Theorem 11 (11.6). 
The 3SAT problem is NP-complete.
![](https://i.imgur.com/U8mKRwp.png)


## Clique
### Problem
Given an undirected graph $G = (V,E)$ and an integer $k$, determine whether $G$ contains a clique of size $\ge k$.
*** 
A clique $C$ is a subgraph of $G$ such that all vertices in $C$ are adjacent to all other vertices in $C$.

#### Theorem (11.7)
The clique problem is NP-complete.
* By reduction from the SAT problem.

![](https://i.imgur.com/VQqp5Dd.png)


## 3-Coloring
### Problem 14. 
Given an undirected graph $G = (V, E)$, determine whether $G$ can be colored with three colors.

#### Theorem 15 (11.8). 
The 3-coloring problem is NP-complete.

![](https://i.imgur.com/23SC4j0.png)
![](https://i.imgur.com/bmbh2TM.png)
* $I$: inner triangle
* $O$: outer triangle

For each clause, we create a graph component like the above, which is illustrated for the case of $(x + y + z)$. The construction ensures that, if a literal in a clause gets a $1$ (the representing vertex is colored $T$ ), then this part of the graph can be colored in three colors, and vice versa. 
![](https://i.imgur.com/ei8564N.png)
