# Question 8: Sorting algorithm
The program takes the sorting of integers which are allocated in dynamic arrays.

Main Arrays:
arr: Original list of random generated integers.
copy: copy of arr to be used in sorting so that original isn not changed.
Merge Sort: Temporary Arrays:
L[] and R[]: The dynamically allocated subarrays which are employed in the merge process.
Global Counters:
int comp = 0; 
int swaps = 0;
Such arrangements enable the flexible use of various sizes of input values (N) without the problem of limiting the size of an array.

## (b) Description of the Functions Implemented
1. reset()
Purpose: Resets comp and swaps to 0 before comp starts.

2. print(int arr[ ], int n)
Purpose:Prints the position of the array elements in a line with spaces in between.

3. bubbleSort(int arr[],int n)
Purpose: Bubble Sort algorithm repeated swaps of successive elements as long as their arrangement needs correction.
Complexity: O(n 2 ) worst "Case, O(n) best case.

4. selectionSort(int arr[ ], int n)
Purpose: It carry out Selection Sort, locates the (new) minimum element in the unsorted part and brings it to the front.
Complexity: O(n 2) in general.

5. insertionSort(int arr[], int n);
Purpose:  Executes Insertion Sort algorithm by moving each element it to its correct position in the already sorted part of the array.
Complexity: O(n 2 ) worstCase, O(n) best case.

6. merge(int arr[],int l,int m,int r)
Purpose: It combines two sorted subarrays into one sorted array.
Description: makes use of dynamically allocated Run Length Encoding and Run Length Decoding arrays L and R to temporarily store the data and then merge it all back into arr.
7. mergeSort(int arr[], int l, int r )
Purpose: Recursively haldves the array and sorts them halves back with merge().
Complexity: O(n log n) in all the cases.

8. mergeSortWrapper(int arr[], int n)
Purpose: Resets counter and calls mergeSort() in OEIS so that they are easy to use in functional pointers.

## (c) An Overview of How the main() Method Is Organized
1. Input Phase:
Ask user to input the number of elements (N).
malloc arr and copy.

2. Data Generation:
Fill the array arr with random integers, such that 1 <= arr[i] <= 1000.
Initialise a copy of arr to copy to sort.

3. Display Phase:
Print the disorganized array.

4. User Selection:
Present it to the user and ask him/her to select one of the following sorting algorithms:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
To select quickly, store sorting function pointers are saved in an array.

5. Sorting Phase:
Call the selected sorting algorithm on copy.

6. Output Phase:
Sort an array and display it.
Provide the number of comparisons and exchanges.
s
7. Cleanup:
Dynamically allocated memory free all.

## (d) Output of a Complete Run of the Program
Enter N: 8
Generating 8 random numbers [1-1000]
Before: 180 535 401 378 312 778 598 420
Choose:1.Bubble 2.Selection 3.Insertion 4.Merge
Choice: 3
Using Insertion Sort
After: 180 312 378 401 420 535 598 778
Comparisons: 17, Swaps: 10

## Conclusion
This program is useful in comparing four sorting algorithms and their performance in terms of comparisons and swaps. This program is very user-friendly, easy-to-use, to find out the operation of various sorting algorithms and how efficient they are.

