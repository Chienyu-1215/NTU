###### tags: `IM2009 Algorithms` `Notes`
# Algorithms: A Supplement
## Heaps
* A (max binary) heap is a complete binary tree whose keys satisfy the heap property:
    the key of every node is greater than or equal to the key of any of its children.
* It supports the two basic operations of a ==priority queue==:
    * Insert($x$): insert the key x into the heap.
    * Remove(): remove and return the largest key from the heap.
* A complete binary tree can be represented implicitly by an array $A$ as follows:
    1. The root is stored in $A[1]$.
    2. The left child of $A[i]$ is stored in $A[2i]$ and the right child is stored in $A[2i + 1]$.
![](https://i.imgur.com/hItuBbH.png)
![](https://i.imgur.com/Bo4AKiG.png)


## AVL Trees
### Definition
An AVL tree is a binary search tree such that, for every node, the difference between the heights of its left and right subtrees is at most $1$ (the height of an empty tree is deﬁned as $0$).

* 左右子樹高度差$1$

![](https://i.imgur.com/O4I5jE6.png)


## Union - Find
* There are $n$ elements $x_1, x_2,..., x_n$ divided into groups. Initially, each element is in a group by itself.
* Two operations on the elements and groups:
    * $find(A)$: returns the name of $A$’s group.
    * $union(A, B)$: combines $A$’s and $B$’s groups to form a new group with a unique name.
* To tell if two elements are in the same group, one may issue a $find$ operation for each element and see if the returned names are the same.

![](https://i.imgur.com/sELVvWw.png)
* $B, F$ in the same group.
* $A, C, G, D$ in one group. 


## Balancing
* The root also stores the number of elements in (i.e., the size of) its group.
* To balance the tree resulted from a union operation, let the smaller group join the larger group and update the size of the larger group accordingly.

**Theorem**
If balancing is used, then any tree of height $h$ must contain at least $2^h$ elements

* Any sequence of $m$ ﬁnd or union operations (where $m /ge n$) takes $O(m /log n)$ steps.

![](https://i.imgur.com/LWwZop3.png)

**Theorem**
If both balancing and path compression are used, any sequence of $m$ find or union operations (where $m \ge n$) takes $O(m \log∗ n)$ steps.

The value of $\log∗ n$ intuitively equals the number of times that one has to apply $\log$ to $n$ to bring its value down to $1$.

![](https://i.imgur.com/OUtgkhB.png)
![](https://i.imgur.com/kEFjMlU.png)
![](https://i.imgur.com/eJEY57c.png)
