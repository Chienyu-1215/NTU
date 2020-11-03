###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: String Processing
## Data Compression
### Problem
Given a text (a sequence of characters), find an encoding for the characters that satisﬁes the preﬁx constraint and that minimizes the total number of bits needed to encode the text.  
更改檔案的編碼儲存形式。

* The **prefix constraint** states that the preﬁxes of an encoding of one character must not be equal to a complete encoding of another character. 
* Denote the characters by $c_1, c_2, ..., c_n$ and their frequencies by $f_1, f_2, ..., f_n$. Given an encoding $E$ in which a bit string $s_i$ represents $c_i$, the length (number of bits) of the text encoded by using $E$ is $\sum_{i = 1}^{n}{s_i} · f_i$. <- 想要Minimize

### A Code Tree
![](https://i.imgur.com/MsH0RO5.png)

### A Huffman Tree
![](https://i.imgur.com/BrTOEMf.png)
#### Huffman Encoding
![](https://i.imgur.com/jYFG0Fq.png)  
Frequency lowest -> lowest in the tree. 
*First create a **min** heap.*  

#### Time Complexity
$O(n \log{n})$ : The while loop requires $n$ iterations, as the heap $H$ initially contains $n$ elements and each iteration reduces its size by one (removing two elements and adding one new element). Each iteration takes $O(\log{n})$ time.


## String Matching
### Problem
Given two strings $A (= a_1a_2 ... a_n)$ and $B (= b_1b_2 ... b_m)$, find the first occurrence (if any) of $B$ in $A$. In other words, find the smallest $k$ such that, for all $i$, $1 \le i \le m$, we have $a_{k − 1 + i} = b_i$.  
A (non-empty) substring of a string $A$ is a consecutive sequence of characters $a_i a_{i + 1}...a_j (i \le j)$ from $A$. 
  
### Straight Forward Matching
![](https://i.imgur.com/1uDDj1e.png)  
#### Time Complexity
$B (= b_1b_2 ... b_m)$ may be compared against
* $a_1a_2 ... a_m$,
* $a_2a_3 ... a_{m + 1}$,
* ..., and
* $a_{n − m + 1}a_{n − m + 2} ... a_n$
* The time complexity is $O(m \times n)$.  
  
Why it's not efficient? Need a lot of comparisons through the every characters.


## Matching the Pattern Against Itself
In the example, when the ongoing matching fails at $b_{11}$ against $a_{16}$, we know that $b_1b_2... b_{10}$ equals $a_6a_7...a_{15}$.

* The next possible substring of $A$ that equals $B$ must start at a13, because $a_{13}a_{14}a_{15}$ is the longest suffix of $a_6a_7...a_{15}$ that equals a prefix of $b_1b_2...b_{10}$, namely $b_1b_2b_3$.  

*The reason can be restated as: $b_1b_2b_3$ is the longest proper prefix that is also a suffix of $a_6a_7...a_{15}$ (which equals $b_1b_2...b_{10}$). If we know this in advance, then we should next try b4 against $a_{16}$ (rather than $b_1$ against $a_7$).*

### The Values of *next*
![](https://i.imgur.com/1RdUbLZ.png)

* The value of $next[j]$ tells the length of the longest proper preﬁx that is equal to a suffix of $b_1b_2...b_{j − 1}$.
* If the ongoing matching fails at $b_j$ against $a_i$, then $b_{next[j] + 1}$ is the next to try against $a_i$.

### The KMP Algorithm
![](https://i.imgur.com/nkcbUXL.png)
* Case $j = 0$: 一開始就比錯了->從頭比，A從下一格看
![](https://i.imgur.com/Ef5Zv9o.png)
![](https://i.imgur.com/CBh6Ik5.png)

### Time Complexity
* Because of backtracking, ai may be compared against
    * $b_j$,
    * $b_{j − 1}$,
    * ..., and
    * $b_2$
* However, for these to happen, each of $a_{i − j + 2}, a_{i − j + 3},..., a_{i − 1}$ was compared against the corresponding character in $b_1b_2...b_{j − 1}$ **just once**.
* We may re-assign the costs of comparing ai against $b_{j − 1}, b_{j − 2},...,b_2$ to those of comparing $a_{i − j + 2}a_{i − j + 3}...a_{i − 1}$ against $b_1b_2 ...b_{j − 1}$.
* Every $a_i$ is incurred the cost of **at most two comparisons**.
* The time complexity is $O(n)$.


## String Editing
### Problem
Given two strings $A (= a_1a_2 ... a_n)$ and $B (= b_1b_2 ... b_m)$, find the minimum number of changes required to change $A$ character by character such that it becomes equal to $B$.  
Three types of changes (or edit steps) allowed: (1) insert, (2) delete, and (3) replace.  
![](https://i.imgur.com/T4fARAR.png)

### Algorithm
![](https://i.imgur.com/gD5t8b0.png)



