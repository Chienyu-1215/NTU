###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: Searching and Sorting
## Searching a Sorted Sequence
### Problem
Let $x_1, x_2, ... , x_n$ be a sequence of real numbers such that $x_1 \le x_2 \le ... \le x_n$. Given a real number $z$, we want to ﬁnd whether $z$ appears in the sequence, and, if it does, to ﬁnd an index $i$ such that $x_i = z$.

*Idea*

cut the search space in half by asking only one question. $$\left\{\begin{array}{} T(1) = O(1) \\ T(n) = T(\frac{n}{2}) + O(1), n \ge 2 \end{array}\right.$$
Time complexity: $O(\log n)$ (applying the master theorem with $a = 1, b = 2, k = 0$, and $b^k = 1 = a$).

### Algorithm
![](https://i.imgur.com/igcY9aa.png)
![](https://i.imgur.com/JAvcqQ0.png)
* 考慮 $z$ 在陣列中出現的機率。


## Searching a Cyclically Sorted Sequence
### Problem
Given a cyclically sorted list, ﬁnd the position of the minimal element in the list (we assume, for simplicity, that this position is unique).

### Example
* Example 1:
[ 1 2 3 4 5 6 7 8 ]
[ 5 6 7 0 1 2 3 4 ]
The $4th$ is the minimal element.
* Example 2:
[ 1 2 3 4 5 6 7 8 ]
[ 0 1 2 3 4 5 6 7 ]
The $1st$ is the minimal element.

++To cut the search space in half, what question should we ask?++

### Algorithm
![](https://i.imgur.com/2MoaR6E.png)
![](https://i.imgur.com/befjRAF.png)


## Fixpoints
### Problem
Given a sorted sequence of distinct integers $a_1, a_2,..., a_n$, determine whether there exists an index $i$ such that $a_i = i$.

### Example
* Example 1:
[  1 2 3 4 5 6 7 8 ]
[ −1 1 2 4 5 6 8 9 ]
$a_4 = 4$ (there are more ...).
* Example 2:
[  1 2 3 4 5 6 7 8  ]
[ −1 1 2 5 6 8 9 10 ]
There is no $i$ such that $a_i = i$.

Again, can we cut the search space in half by asking only one question?

### Algorithm
![](https://i.imgur.com/6vuHbhB.png)
![](https://i.imgur.com/im6F7XI.png)


## Stuttering Subsequence
### Problem
Given two sequences $A (= a_1a_2 ...a_n)$ and $B (= b_1b_2 ...b_m)$, find the maximal value of i such that $B_i$ is a subsequence of $A$.
* If $B = xyzzx$, then $B^2 = xxyyzzzzxx$, $B^3 = xxxyyyzzzzzzxxx$, etc.
* $B$ is a subsequence of $A$ if we can embed $B$ inside $A$ in the same order but with possible holes.
* For example, $B^2 = xxyyzzzzxx$ is a subsequence of $xxzzyyyyxxzzzzzxxx$.
* If $B_j$ is a subsequence of $A$, then $B^i$ is a subsequence of $A$, for $1 \le i \le j$.
* The maximum value of $i$ cannot exceed $[\frac{n}{m}]$ (or $B_i$ would be longer than $A$). 

### Solution
Two ways to ﬁnd the maximum $i$:
* Sequential search: try $1, 2, 3,$ etc. sequentially.
    Time complexity: $O(nj)$, where $j$ is the maximum value of $i$.
* Binary search between $1$ and $[\frac{n}{m}]$.
    Time complexity: $O(n \log{\frac{n}P{m}} )$
 
 
## Interpolation Search 內插法 
![](https://i.imgur.com/Hvp5DIP.png)  
![](https://i.imgur.com/Vn0oghK.png)  
![](https://i.imgur.com/Ay2Z5yB.png)

### Algorithm 
![](https://i.imgur.com/2CVCMCr.png)  
![](https://i.imgur.com/ZIPOwUp.png)  


## Sorting
### Problem
Given $n$ numbers $x_1, x_2,..., $x_n$, arrange them in increasing order. In other words, ﬁnd a sequence of distinct indices $1 \le i_1, i_2, ... , i_n \le n$,
such that $x_{i_1} \le x_{i_2} \le ... \le x_{i_n}.

A sorting algorithm is called **in-place** if no additional work space is used besides the initial array that holds the elements. 

### Using Balanced Search Trees
Balanced search trees, such as AVL trees, may be used for sorting:
1. Create an empty tree.
2. Insert the numbers one by one to the tree. $O(n\log{n})$ *Not in-place*
3. Traverse the tree and output the numbers. $O(n)$
* Time Complexity $O(n \log{n})$

### Radix Sort 基數排序
![](https://i.imgur.com/NKN0vUS.png)  
![](https://i.imgur.com/rooveOk.png)
* *GQ := Global Queue*
* http://notepad.yehyeh.net/Content/Algorithm/Sort/Radix/Radix.php
* https://rust-algo.club/sorting/radix_sort/

### Merge Sort
![](https://i.imgur.com/izVaKjm.png)
![](https://i.imgur.com/O0JZA3b.png)
![](https://i.imgur.com/HikG3Qj.png)

### Quick Sort
![](https://i.imgur.com/Jz9LMrY.png)
![](https://i.imgur.com/fp36qRG.png)
![](https://i.imgur.com/9yb3wGP.png)
![](https://i.imgur.com/kt7spP5.png)
* L:= Left + 1;
![](https://i.imgur.com/EDbmaaB.png)
* https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html

#### Average-Case Complexity
![](https://i.imgur.com/lWmwPXi.png)

### Heap Sort
![](https://i.imgur.com/p4iUm9F.png)
![](https://i.imgur.com/6PjoIOe.png)
![](https://i.imgur.com/uFjQLvh.png)
![](https://i.imgur.com/pTYdJhZ.png)

#### Building a Heap Bottom Up
![](https://i.imgur.com/YWRT7VX.png)

### A Lower Bound for Sorting
* A lower bound for a particular problem is a proof that *no algorithm* can solve the problem better.
* We typically deﬁne a *computation model* and consider only those algorithms that ﬁt in the model.
* **Decision trees** model computations performed by *comparison-based* algorithms.

**Theorem**  
Every decision-tree algorithm for sorting has height $\Omega(n \log{n})$.

![](https://i.imgur.com/qRE2dOF.png)


## Order Statistics: Minimum and Maximum
### Problem
Find the maximum and minimum elements in a given sequence.
* The obvious solution requires $(n − 1) + (n − 2) (= 2n − 3)$ comparisons between elements.


## Order Statistics: $K$th-Smallest
### Problem
Given a sequence $S = x_1, x_2,..., x_n$ of elements, and an integer $k$ such that $1 \le k \le n$, find the kth-smallest element in S.

### Algorithm
![](https://i.imgur.com/39mu2hk.png)
![](https://i.imgur.com/LKMkBKK.png)
![](https://i.imgur.com/OGusR56.png)


## Finding a Majority
### Problem
Given a sequence of numbers, find the majority in the sequence or determine that none exists.
* A number is a majority in a sequence if it occurs more than $\frac{n}{2}$ times in the sequence.  

**Idea**
Compare any two numbers in the sequence. What can we conclude if they are not equal?