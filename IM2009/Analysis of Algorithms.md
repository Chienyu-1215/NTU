###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Analysis of Algorithms
## Introduction 
* The purpose of algorithm analysis is to *predict the behavior*(running time, space requirement, etc.) of an algorithm *without implementing it* on a specific computer. (Why?)
不寫程式 -> 分析行為 -> 提前預測錯誤 -> 節省時間
* As the exact behavior of an algorithm is hard to predict, the analysis is usually an *approximation*:
    #### Relative to the input size (usually denoted by $n$) 
    input possibilities too enormous to elaborate
    i.e. sorting an array
    #### Asymptotic 
    should care more about larger inputs
    ####  Worst-Case 
    easier to do, often representative (Why not average-case?)
* Such an *approximation* is usually good enough for *comparing* different algorithms for the same problem.


## Complexity
* Theoretically, *“complexity of an algorithm”* is a more precise term for “approximate behavior of an algorithm”.
* Two most important measures of complexity:
    #### Time Complexity
    an upper bound on the number of steps that the algorithm performs.
    #### Space Complexity
    an upper bound on the amount of temporary storage required for running the algorithm.
* Mostly focus on time complexity. 


## Comparing Running Times
* How do we compare the following running times:
    * $100n$
    * $2n^2 + 50$
    * $100 \times n ^ {1.8}$
* The second one is worse than the first since $n ^ 2$ will grow fast as $n$ becoming larger. $Case 2 \gt Case 3 \gt Case 1$.


## The $O$ Notation
* A function $g(n)$ is $O(f(n))$ for another function $f(n)$ if there exist constants $c$ and $N$ s.t., for all $n \ge N$, $g(n) \le cf(n)$
* The function $g(n)$ may be substantially less than $cf (n)$; the $O$ notation bounds *it only from above*. (Upper Bound)
* The $O$ notation allows us to **ignore constants** conveniently. 
* No need to specify the base of a logarithm.
    * $\log_{2}{n} = \frac{\log_{10}{n}}{\log_{10}{2}}=\frac{1}{\log_{10}{2}}\log_{10}{n}$ -> We can just write $O(\log{n})$
* $O(1)$ denotes a constant.


## Properties of $O$
1. If $f (n) = O(s(n))$ and $g(n) = O(r(n))$, then $f(n) + g(n) = O(s(n) + r(n))$.
2. If $f(n) = O(s(n))$ and $g(n) = O(r(n))$, then $f(n) · g(n) = O(s(n) · r(n))$.

* However, we cannot subtract or divide with O. (Why?)
    * $2n = O(n), n = O(n)$, and $2n − n = n \ne O(n − n)$.
    * $n^2 = O(n^2), n = O(n^2)$, and $\frac{n^2}{n} = n \ne O(n^2/n^2)$.


## Polynomial vs. Exponential
* A function $f(n)$ is monotonically growing (or monotonically increasing) if $n_1 \ge n_2$ implies that $f(n_1) \ge f(n_2)$.
* An exponential function grows at least as fast as a polynomial function does.

**Theorem**
For all constants $c > 0$ and $a > 1$, and for all monotonically growing functions $f(n)$, $(f(n))^c = O(a^{f(n)})$.


## Speed of Growth 
![](https://i.imgur.com/JjOJfBu.png)
![](https://i.imgur.com/0GsJ16T.png)


## $O, o, \Omega,$ and $\Theta$
* Let $T(n)$ be the number of steps required to solve a given problem for input size $n$.
* We say that $T(n) = \Omega(g(n))$ or the problem has a lower bound of $\Omega(g(n))$ if there exist constants $c$ and $N$ such that, for all $n \ge N, T(n) \ge cg(n)$.
* If a certain function $f(n)$ satisfies both $f(n) = O(g(n))$ and $f(n) = \Omega(g(n))$, then we say that $f(n) = \Theta(g(n))$.
* We say that $f(n) = o(g(n))$ if $\lim_{n→\inf} \frac{f(n)}{g(n)}= 0$.


## Sum
* Techniques for summing expressions are essential for complexity analysis.
* For example, given that we know
![](https://i.imgur.com/KLz2me8.png)
![](https://i.imgur.com/3n5UOVL.png)
* So, we have $(n + 1)^3 − 1 = 3 \times S_2(n) + 3 \times S_1(n) + S_0(n)$.
* Given $S_0(n)$ and $S_1(n)$, the sum $S_2(n)$ can be computed by straightforward algebra.
* Recall that the left-hand side $(n + 1)^3 − 1$ equals $(S_3(n + 1) − S_3(1)) − S_3(n)$, a result from “shifting and canceling” terms of two sums.
* This generalizes to $S_k(n)$, for $k \gt 2$.
* Similar shifting and canceling techniques apply to other kinds of sums.


## Recurrence Relations
* A recurrence relation is a way to define a function by an expression involving the same function.
* The Fibonacci numbers, for example, can be defined as follows:$$\left\{\begin{array}{} F(1) = 1 \\ F(2) 1 \\ F(n) = F(n - 2) + F(n - 1) \end{array}\right. $$
    We would need $k − 2$ steps to compute $F(k)$.
* It is more convenient to have an explicit (or closed-form) expression.
* To obtain the explicit expression is called solving the recurrence relation. 

### Guessing and Proving an Upper Bound
![](https://i.imgur.com/HZKyaih.png)

### Solving the Fibonacci Relation
* We will study two techniques for solving the Fibonacci relation.
    1. One uses the characteristic equation
    2. The other uses generating functions
* These techniques may be generalized to handle recurrence relations of the form $$F(n) = b_1F(n − 1) + b_2F(n − 2) + · · · + b_kF(n − k)$$ for a constant $k$.
*  
### Using the Characteristic Equation
* $F(n)$ nearly doubles every time and should be an exponential function.
* The base a should satisfy $a^n = a^{n−1} + a^{n−2}, which implies $a^2 = a + 1$ (called the characteristic equation).
* There are two solutions to the characteristic equation: $a_1 = \frac{1 + \sqrt{5}}{2}, a_2 = \frac{1 - \sqrt{5}}{2}$
* Any linear combination of $a_1^n, a_2^n$ solves the recurrence relation.
![](https://i.imgur.com/XPBTupR.png)

### Using Generation Function (z-transform)
* *Generating functions* provide a systematic, effective means for representing and manipulating infinite sequences (of numbers).
* We use them here to derive a closed-form representation of the Fibonacci numbers.
* Below are two basic generating functions:
![](https://i.imgur.com/fM2IFoH.png)
* The second one is a generalization of the first and will be used in our solution.
![](https://i.imgur.com/muvckn6.png)


## Divide and Conquer Relations
* The running time $T(n)$ of a divide-and-conquer algorithm satisfies $T(n) = aT(\frac{n}{b}) + O(n^k)$ where 
    * $a$ is the number of subproblems
    * $\frac{n}{b}$ is the size of each subproblem
    * $O(n^k)$ is the time spent on dividing the problem and combining the solutions.

**Theorem**
The solution of the recurrence relation $T(n) = aT(\frac{n}{b}) + O(n^k)$, where $a$ and $b$ are integer constants, $a \ge 1, b \ge 2$, and $k$ is a non-negative real constant, is $T(n) = \left\{\begin{array}{} O(n^{\log_ba}) & \text{if } a \gt b^k \\
O(n^k \log n) & \text{if } a = b^k \\
O(n^k) & \text{if } a \lt b^k \end{array} \right.$
This theorem may be slightly generalized by replacing $O(n^k)$ with some $f(n)$, but the current form is sufficient for the cases we will encounter. Due to its generality and usefulness, the theorem has conventionally been referred to as “the master theorem”.
### Recurrent Relations with Full History
![](https://i.imgur.com/e8tkUWJ.png)
![](https://i.imgur.com/Q2ytOIq.png)
![](https://i.imgur.com/rMN2Dbm.png)


## Useful Facts
![](https://i.imgur.com/BGG1Qo4.png)
![](https://i.imgur.com/DyxgRd2.png)

### Bounding a Summation by an Integral
![](https://i.imgur.com/I6nV4Nh.png)
![](https://i.imgur.com/qYMSD0C.png)











