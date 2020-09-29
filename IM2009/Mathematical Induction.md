###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Mathematical Induction
## Recursively/Inductively-Defined Sets
* The set $N$ of natural numbers,  including $0$:
    1. Base case: $0$ is a natural number $(0 \in N)$.
    2. Inductive step: if n is a natural number $(n \in N)$, then $n + 1$ is also a natural number $((n + 1) \in N)$.
* The set $N_1$ of natural numbers, excluding $0$:
    1. Base case: $1$ is a natural number.
    2. Inductive step: if $n$ is a natural number, then$ n + 1$ is also a natural number.

*Note* 
When $n = n' + 1$ for some $n' \in N$, we write $n'$ as $n − 1$; similarly, for $n' \in N_1$. The factorial function fac : $N \Rrightarrow N_1$, for example, can be defined inductively as follows:
$$ fac(n) = \left\{ \begin{array}{} 1 & \mbox{if $n=0$} \\
n \times fac(n-1) &\mbox{otherwise} \end{array} \right.$$


## Euler's Formula
![](https://i.imgur.com/3BEUfnX.png)

**Theorem** 
The number of vertices($V$), edges($E$), and faces($F$) in an arbitrary connected planar graph are related by the formula $V + F = E + 2$ 
**[Base Case]**
$V = 1, F = 1, E = 0\Rrightarrow 1 + 1 = 0 + 2$
$V = 2, F = 1, E = 1\Rrightarrow 2 + 1 = 1 + 2$

*Lemma* A tree with $V$ vertices has $V - 1$ edges.


## Gray Code
* A Gray code for $n$ objects is a binary-encoding scheme for naming the $n$ objects such that the $n$ names can be arranged in a circular list where **any two adjacent** names, or code words, differ by only **one bit**.

**Theorem**
There exist Gray codes of length $\frac{k}{2}$ for any positive even integer $k$.
要替$k$個物件命名，要用$\frac{k}{2}$個位元。
**[Base Case]** $k = 2$
**[Inductive Steps]** Constructing a Gray code of size $k = j + 2$, where $j$ is even from another of a smaller size $j$ *(induction hypothesis)*.

**Theorem**
There exist Gray codes of length $\log_{2}{k}$ for any positive integer $k$ that is a power of $2$.

**Theorem**
There exist Gray codes of length $log_{2}k$ for any positive even integer $k$.
奇數的 Gray Code不應該存在─ Open Gray Code.
2個Open Gray Code可以合成一個Closed Gray Code.

**Theorem**
There exist Gray codes of length dlog2 ke for any positive integer $k \ge 2$. The Gray codes for the **even** values of $k$ are **closed**, and the Gray codes for **odd** values of $k$ are **open**.


## Arithmetic vs. Geometric Mean
**Theorem**
If $x_1, x_2, ..., x_n$ are all positive numbers, then $$(x_1x_2...x_n)^{\frac{1}{n}} \le \frac{x_1+x_2+...x_n}{n}$$
**Theorem** (Reversed Induction Principle)
If a statement $P$, with a parameter $n$, is true for an **infinite** subset of the natural numbers, and if, for every $n \ge 1$, the truth of $P$ for $n$ implies its truth for $n − 1$, then $P$ is true for all natural numbers.

For all powers of $2$, i.e. $n = 2^k, k\gt 1$: by induction on $k$.
**[Base Case]:
$(x_1x_2)^{\frac{1}{2}} \le \frac{x_1+x_2}{2}$, squaring both sides,...
**[Inductive step]**
$(x_1x_2x_3...x_{2^{k+1}})^{\frac{1}{2^{k+1}}}\\=[(x_1x_2x_3...x_{2^{k+1}})^{\frac{1}{2^k}}]^{\frac{1}{2}}\\=[(x_1x_2x_3...x_{2^k})^{\frac{1}{2^k}}(x_{2^k+1}x_{2^k+2}...x_{2^{k+1}})^{\frac{1}{2^k}}]^{\frac{1}{2}}\\
\le\frac{(x_1x_2x_3...x_{2^k})^{\frac{1}{2^k}}(x_{2^{k}+1}x_{2^{k}+2}...x_{2^{k+1}})^{\frac{1}{2^k}}}{2} \qquad\mbox{   by Base Case}\\
\le\frac{\frac{(x_1x_2x_3...x_{2^k})}{2^k}\quad\frac{(x_{2^{k}+1}x_{2^{k}+2}...x_{2^{k+1}})}{2^k}}{2} \qquad\mbox{   by Induction Hypothesis}\\
=\frac{x_1+x_2+...+x_2^{k+1}}{2^{k+1}}$
![](https://i.imgur.com/VFkJneC.png)


## Loop Invariants
* An **invariant** at some point of a program is an assertion that holds whenever execution of the program reaches that point.
* Invariants are a bridge between the *static text* of a program and its *dynamic computation*.
* An invariant at the front of a while loop is called a loop invariant of the while loop.
* A loop invariant is formally established by induction.
    * Base case: the assertion holds right before the loop starts.
    * Inductive step: assuming the assertion holds before the $i$-th iteration $(i \ge 1)$, it holds again after the iteration.





