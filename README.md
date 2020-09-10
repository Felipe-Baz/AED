# ordering methods

In this repository, I will compromise all my codes proposed in the matter of AED 2.
All of these codes are written in C language, in which I will define various ordering methods and apply them to simple problems for testing.


- Merge Sort:

> The function will use the method of division and conquest, to sort the vector entered in the "list" parameter. That ordering works upon arrival in a trivial case, which the treated list would have only 1 element. After that arrival the algorithm will use the merge function to combine orderly and intelligently these elements, resulting in small ordered vectors that will be combined until we return the entire tree created by the mergeSort function recursion.

- Quick Sort:

> Quicksort adopts the strategy of division and conquest. The strategy is to rearrange the keys so that the "smaller" keys precede the "larger" keys. Then quicksort sorts the two sub-lists of major and minor keys recursively until the complete list is sorted. The steps are:

> Choose an element from the list, called a pivot;
Partition: rearrange the list so that all elements before the pivot are smaller than it, and all elements after the pivot are larger than it. At the end of the process, the pivot will be in its final position and there will be two unordered sub-lists. This operation is called a partition;

> Recursively order the sub-list of minor elements and the sub-list of major elements;
The base case of recursion are the zero or one size lists, which are always ordered. The process is finite, since with each iteration at least one element is put in its final position and will no longer be manipulated in the next iteration.

> The choice of the pivot and the steps of the Partition can be done in different ways and the choice of a specific implementation strongly affects the performance of the algorithm.

> For our code, we use the pivot choice method of the median of 3, with the median of the first, last and intermediate elements.

- Heap Sort:

> The heapsort algorithm is a generalist sorting algorithm, and is part of the family of selection sorting algorithms. It was developed in 1964 by Robert W. Floyd and J.W.J Williams.

> It has a very good runtime performance in randomly ordered sets, it has a well-behaved memory usage and its worst-case performance is practically the same as its performance in medium scenario.

> Some fast sorting algorithms perform spectacularly poorly in the worst case, either at runtime or memory usage. The heapsort works in place and the worst-case runtime to sort n elements is O (n lg n). Logarithm (or log) of "n" is read in base 2. For values of n, reasonably large, the term log n is almost constant, so that the ordering time is almost linear with the number of items to be sorted.

> Heapsort is not a stable sorting algorithm. However, it is possible to adapt the structure to be ordered in order to make the ordering stable. Each element of the adapted structure must be in the form of a pair (original element, original index). Thus, if two elements are the same, the tiebreaker will occur by the index in the original structure.

> The heapsort uses a data structure called a heap, to order the elements as you insert them into the structure. Thus, at the end of the insertions, the elements can be successively removed from the heap root, in the desired order, always remembering to keep the max-heap property.

> The heap can be represented as a tree (a binary tree with special properties) or as a vector. For a descending order, a minimum heap must be built (the smallest element is at the root). For an increasing order, a maximum heap must be built (the largest element is at the root).

- Counting Sort:

> Counting sort is a stable sorting algorithm whose complexity is O (n). The keys can take values between 0 and M-1. If there are k0 keys with a value of 0, then they occupy the first k0 positions of the final vector: from 0 to k0-1.

> The basic idea of counting sort is to determine, for each input x, the number of elements less than x. This information can be used to place the element x directly in its position in the output array. For example, if there are 17 elements less than x, then x belongs to position 18. This scheme should be slightly modified when there are several elements with the same value, since we do not want them to be placed in the same position.

> Features

> - Stable
> - Auxiliary memory required. So it's not in-place
> - Linear complexity

> Implementation:

> - Create cnt [M + 1] and b [max N]
- Initializes all positions from cnt to 0.

> - Run the vector ae, for each position i of a makes cnt [a [i] -1] ++ which means that, in the end, each position i of cnt contains the number of times the key i-1 appears in The.

> - The element added to the previous element accumulates in each cnt element: cnt [i] indicates the ordered position of the first key element i.

> - Stores in b the values of a ordered according to b [cnt [a [i] ++] = a [i]
Copy b to a.

> Counting-Sort works as an event counter within a program, specifically within a vector. When a given vector has repeated numbers, unique numbers and numbers that do not exist, another vector indicates the number of occurrences.

> This implementation has the disadvantage of requiring auxiliary vectors. Counting Sort exclusively orders whole numbers because their values ​​serve as indexes in the count vector.

- Radix Sort:

> Radix sort is a fast and stable sorting algorithm that can be used to sort items that are identified by unique keys. Each key is a string or number, and radix sort sorts these keys in any order related to lexicography.

> In computer science, radix sort is a sorting algorithm that sorts integers by processing individual digits. Since integers can represent strings composed of characters (such as names or dates) and specially formatted floating points, radix sort is not limited to integers only.

> Computers, for the most part, internally represent all types of data as binary numbers, so processing digits as integers in groups represented by binary digits becomes more convenient. There are two classifications of the radix sort, which are:

> - Least significant digit (LSD) radix sort;
> - Most significant digit (MSD) radix sort.

> The LSD radix sort starts from the least significant digit to the most significant, typically ordering as follows: short keys come before long keys, and keys of the same size are ordered lexicographically. This coincides with the normal order of representation of the integers, such as the sequence "1, 2, 3, 4, 5, 6, 7, 8, 9, 10". The values processed by the sorting algorithm are often called "keys", which can exist on their own or associated with other data. The keys can be strings of characters or numbers.

> Radix sort MSD works in the opposite direction, always using the lexicographic order, which is suitable for ordering strings, such as words, or representations of integers with fixed length. The sequence "b, c, d, e, f, g, h, i, j, ba" will be ordered lexicographically as "b, ba, c, d, e, f, g, h, i, j". If this sorting is used to sort representations of integers with variable length, then the representation of integers 1 to 10 will have the output "1, 10, 2, 3, 4, 5, 6, 7, 8, 9".

> The LSD radix sort operates in Big-O notation, in O (nk), where n is the number of keys, and k is the average key length. This performance can be guaranteed for keys with variable length by grouping all keys that have the same length and separately ordering each group of keys, from the shortest to the longest, in order to avoid processing an entire list of keys at each step of sorting.

> In many applications where speed is required, radix sort improves sorting by comparison, such as heapsort and mergesort, which require nlog n comparisons, where n is the number of items to be sorted. In contrast, ordering algorithms based on comparisons offer flexibility because they are able to order in ways other than lexicography. However, this ability is of little importance in many practical applications.

> The radix sort sorting algorithm was originally used to sort punch cards. A computational algorithm for the radix sort was invented in 1954 at MIT by Harold H. Seward.

References:

<https://pt.wikipedia.org/wiki/Quicksort>

<https://pt.wikipedia.org/wiki/Heapsort>

<https://pt.wikipedia.org/wiki/Counting_sort>

<https://pt.wikipedia.org/wiki/Radix_sort>

