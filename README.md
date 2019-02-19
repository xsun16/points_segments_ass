# Points covered by segments
## Using quick sort to design faster algorithms
This assignment asks you to implement the algorithm to solve the following problem:

<strong>Input</strong>: A set of S segments and a set of P points.

<strong>Output</strong>: For each point - the number of segments it is contained in.

As usual, first implement a naive version of the algorithm which works in time O(S*P).

Next, implement a version discussed in class, which uses a <em>quicksort</em>. You may use a built-in <code>qsort</code> function, for which you would need to implement the corresponding comparator. After sorting, the algorithm should perform O(S+P) steps, which makes the total running time of this algorithm O((S+P)log(S+P)).

As always, implement the stress test to compare your naive algorithm with the fast algorithm.
This time, however
Finally, implement a special test



