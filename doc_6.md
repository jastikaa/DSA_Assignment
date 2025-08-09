
# Question 6: Max Heap and Min Heap Construction in C
## (a) Data structure defination
A binary heap is the main data structure relied on in this program; this orientation is based on arrays. Two kinds of heaps are built:
- Max Heap: It is a binary  heap where the parent node is always greater than or equal to its children.
- Min Heap: It is a binary heap where the parent  node is always less than or equal to its children.
In the Max Heap the array arr[] is used, and the Max Heap is constructed by copying it to another array arrMin[]. The two heaps are maintained in arrays since binary heaps could effectively be coded in arrays where:
The left child index = 2i+1
Right child index = 2i 2

## (b) Description of the Functions Implemented
1. swap(int *a, int *b)
- Purpose: Exchanges the values of two integers pointers.
- Usage: It is used (in heapify functions) to preserve heap properties.
2. mheapify(int arr[ ],int n, int i)
- Purpose:Maintains the Max Heap property of a subtree with root index i.
- Logic:
  Comparision of the parent with left and right children.
  In case the size of either child is larger than that of the parent, it interchanges and recursive heapifies the subtree.
3. bldmxHeap(int arr[], int n)
- Purpose: Builds a Max Heap out of an unsorted array..
- Logic:
  Heapifies from the last non-leaf node to the root.
4. miheapify(int arr[], int n, int i)
- Purpose: Maintains the Min Heap property of a subtree rooted at index i.
- Logic:
  It compares the parent with its left and right child.
  If the child is larger than the parent, it swaps and recursively heapifies the disturbed subtree.
5. bldminHeap(int arr[], int n)
- Purpose: Builds a Min Heap from an unsorted array.
- Logic:
  Identical to bldmxHeap, except that it uses miheapify to implement Min Heap conditions.
6. printArray(int arr[], int n)
- Purpose: Prints the array elements.
- Usage: Printing the original array, Max Heap, and Min Heap.

## (c) An Overview of How the main() Method Is Organized
The main() is organized in the following way:
1. Initialization:
A arrays of integer type arr[] is created and initialized.
The size n of it is calculated.
arr[ ] is duplicated into arrMin[] in order to create a Min Heap.

2. Show Original Array:
It prints the original array with printArray().

3. Max Heap: Build and Display:
arr[] is passed through bldmxHeap() call.
The obtained Max Heap is printed out.

4. Construct and Print Min Heap:
Theheap() function is applied onarrMin[].
The Min Heap is printed out.

5. Program Ends:
return 0; meaning runs successfully.

## (d) Output of a Complete Run of the Program
Original array:
34 23 12 3 17 8 9 15
Max Heap:
34 23 12 15 17 8 9 3
Min Heap:
3 15 8 23 17 12 9 34

## Conclusion
The algorithm uses heapify operations to create Max Heap and Min Heap out of the array. It demonstrates that binary heaps are effectively implemented using arrays and how significant they are in sorting and priority operation. Output can be used to check that the heap was built correctly and to solidify some important DSA concepts such as recursion and tree structure.