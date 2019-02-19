# Points covered by segments
## Using quick sort to design faster algorithms
This assignment asks you to implement the algorithm to solve the following problem:

<strong>Input</strong>: A set of S segments and a set of P points.

<strong>Output</strong>: For each point - the number of segments it is contained in.

<strong>Input format:</strong>
<pre><code>
2 3     // the first line contains the total number of segments and the total number of points
0 5     // the number of segments is 2 - the next 2 lines contain start-end of each segment
7 10
1 6 11  // the last line contains coordinates of 3 points
</code>
</pre>

Multiple inputs are generated for you in files `input1.txt`, `input2.txt`, and `input3.txt`.

The code which reads the inputs and parses required integers is provided in file `test.c`.

First, implement a naive version of the algorithm which works in time O(S*P).

Next, implement a version discussed in class, which uses a <em>quicksort</em>. You may use a built-in <code>qsort</code> function, for which you would need to implement the corresponding comparator. After sorting, the algorithm should perform O(S+P) steps, which makes the total running time of this algorithm O((S+P)log(S+P)).

Finally, in file `test.c` add the code which runs your algorithms with inputs and compares the resulting arrays of counts. 

Please provide a single `make` file which compiles all the files into a single executable called `test`.



