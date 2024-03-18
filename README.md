
1.	Header Files: The code doesn't include header files but should have #include <iostream> for cout and cin, #include <cstdlib> for rand(), #include <ctime> for clock(), and #include <algorithm> for swap().
2.	generate Function:
•	generate function takes an array arr[] and its size s as parameters.
•	It populates the array with random integers using the rand() function.
3.	tt Function:
•	tt function calculates the time taken to perform the selection sort algorithm on the given array.
•	It takes an array arr[] and its size s as parameters.
•	It declares a variable t of type clock_t to store the start time of the algorithm.
•	It initializes a variable k to 0 for iterating over the array.
•	It starts a while loop which runs until k reaches s.
•	Inside the while loop, there's a nested for loop starting from k + 1 to s - 1 to compare elements.
•	Within the nested loop, it swaps the elements if the current element (arr[k]) is greater than the next element (arr[j]).
•	It updates the key variable with the current value of arr[j].
•	It increments k after each iteration.
•	The time taken to sort the array is calculated by subtracting the start time from the current time using clock().
4.	main Function:
•	main function:
•	Declares a variable size to store the size of the array.
•	Takes input for the size of the array.
•	Declares an array arr[] of size size.
•	Calls the generate function to populate the array with random integers.
•	Calls the tt function to sort the array and measure the time taken.
•	Prints the time taken in clock cycles.
5.	Explanation of Selection Sort:
•	The selection sort algorithm sorts an array by repeatedly finding the minimum element from the unsorted part and moving it to the beginning.
•	In this code, the selection sort algorithm is implemented using nested loops.
•	The outer loop (while) iterates over each element of the array.
•	The inner loop (for) iterates over the remaining unsorted elements to find the minimum element and swap it with the current element (arr[k]).
•	This process continues until the array is fully sorted.



 

Time Complexity of the Algorithm:
For every ith element the next (n-i) are iterated, therefore the time complexity of the algorithm is O(n2).

2) Sum of n Numbers
1.	generate Function:
•	The generate function populates an array arr[] of size s with random integers using the rand() function.
•	It takes two parameters: the array arr[] and its size s.
•	It iterates through the array indices from 0 to s-1 and assigns a random integer to each element using rand().
2.	calculateSum Function:
•	The calculateSum function calculates the sum of all elements in an array.
•	It takes two parameters: the array arr[] and its size s.
•	It initializes a variable sum to store the sum and sets it to 0.
•	It iterates through the array and adds each element to the sum.
•	Finally, it returns the sum.
3.	main Function:
•	The main function:
•	Declares a variable size to store the size of the array.
•	Takes input for the size of the array.
•	Declares an array arr[] of size size.
•	Calls the generate function to populate the array with random integers.
•	Measures the time taken to calculate the sum of the array elements.
•	It initializes a variable start_time to store the starting time using clock().
•	It calculates the sum of the array using the calculateSum function.
•	It then captures the end time using clock() and calculates the time taken by subtracting start_time from end_time.
•	Prints the sum of the array and the time taken in clock cycles.

Graph:
 

Time Complexity:
As the complete array is being iterated over, n elements are being traversed, therefore the time complexity is O(n).
 
3) Binary search
1.	Binary Search Function:
•	The BinarySearch function performs a binary search on a sorted vector.
•	It takes four parameters: the vector arr, the left index l, the right index r, and the target value x.
•	It recursively divides the search space in half until the target value x is found or the search space is exhausted.
•	If the target value x is found, it returns the index of x. Otherwise, it returns -1.
2.	generate Function:
•	The generate function populates a vector arr of size n with sorted integers starting from 0.
•	It takes two parameters: the vector arr and the size n.
•	It iterates from 0 to n-1 and assigns each element in arr with the corresponding index.
3.	input_generator1 Function:
•	The input_generator1 function generates inputs for the best-case scenario of binary search.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of inputs.
•	It iterates over different input sizes from 100 to 1,000,000 in powers of 10.
•	For each input size i, it generates a sorted vector of integers using the generate function.
•	It then performs binary search 10 times for the middle element i/2 of the array and measures the time taken using high_resolution_clock.
•	It calculates the average time taken over the 10 iterations and multiplies it by 10^7 for better visualization.
•	It stores the input size i and the corresponding time taken in the store vector.
4.	input_generator2 Function:
•	The input_generator2 function generates inputs for the worst-case scenario of binary search.
•	It follows a similar procedure to input_generator1, but instead of searching for a number that is present in the array, it searches for a number i+2 that is not present in the array.
•	This scenario ensures that the binary search algorithm completes the full search space without finding the target value.
•	It measures the time taken using high_resolution_clock and stores the input size i and the corresponding time taken in the store vector.
5.	main Function:
•	The main function:
•	Calls input_generator1 to generate inputs and print the time taken for the best-case scenario.
•	Prints a header indicating the time taken and the number of inputs.
•	Prints the input size and the corresponding time taken for each scenario.
•	Calls input_generator2 to generate inputs and print the time taken for the worst-case scenario.
•	Prints a header indicating the time taken and the number of inputs.
•	Prints the input size and the corresponding time taken for each scenario.


4) Linear search
1.	Search Function:
•	The search function recursively searches for an element x in a given vector arr.
•	It takes three parameters: the vector arr, the current index i, and the target value x.
•	If the current index i equals the size of the array arr, it means the element was not found, so it returns -1.
•	If the element at index i in the array equals the target value x, it returns x.
•	Otherwise, it recursively calls itself with the next index i+1.
2.	input_generator Function:
•	The input_generator function generates inputs for the best-case scenario of the search function.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of inputs.
•	It iterates over different input sizes from 100 to 10,000 with a step size of 100.
•	For each input size n, it generates a sorted vector of integers from 1 to n-1.
•	It performs the search function 10 times for an element n+2, which ensures the search will fail (as it's not present in the array).
•	It measures the time taken using high_resolution_clock and stores the input size n and the corresponding time taken in the store vector.
3.	main Function:
•	The main function:
•	Calls the input_generator function to generate inputs and store the time taken for the best-case scenario.
•	Prints a header indicating the number of inputs and the time taken.
•	Prints the input size and the corresponding time taken for each scenario.

5) Towers of Hanoi
1.	TOH Function:
•	The TOH (Tower of Hanoi) function is a recursive function that solves the Tower of Hanoi problem.
•	It takes four parameters: n (the number of disks), A, B, and C (the names of the pegs).
•	The base case of the recursion is when n is less than 1, indicating there are no disks left to move.
•	In the recursive case, it moves n-1 disks from peg A to peg C using peg B as an auxiliary peg.
•	It then moves the remaining largest disk from peg A to peg B.
•	Finally, it moves the n-1 disks from peg C to peg B using peg A as an auxiliary peg.
2.	input_generator Function:
•	The input_generator function generates inputs for the Tower of Hanoi problem.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of disks.
•	It iterates over different numbers of disks from 10 to 50 with a step size of 5.
•	For each number of disks n, it performs the Tower of Hanoi algorithm 10 times.
•	It measures the time taken using high_resolution_clock and calculates the average time over the 10 iterations.
•	It prints the number of disks n and the corresponding average time taken.
3.	main Function:
•	The main function:
•	Calls the input_generator function to generate inputs and store the time taken for each number of disks.
•	Prints a header indicating the number of inputs and the time taken.
•	Prints the number of disks and the corresponding average time taken for each scenario.



Graph:
 

Time Complexity:
The number of moves required for n disks can be represented by the recurrence relationT(n) = 2T(n-1) + 1.
Solving this recurrence relation we get =>T(n) = 2n – 1.
Therefore, the time complexity is O(2n).


Program- 06: Permutation Generator
1.	PG Function (Permutation Generation):
•	The PG function recursively generates all permutations of the elements in the input array arr.
•	It takes two parameters: the vector arr and the current index i.
•	If i equals the size of the array arr, it means all elements have been permuted, so it prints or processes the permutation and returns.
•	Otherwise, it iterates over the remaining elements starting from index i.
•	For each index idx starting from i, it swaps the elements at indices idx and i to generate a new permutation.
•	It then recursively calls PG with the next index i+1.
•	After the recursive call, it swaps back the elements at indices idx and i to backtrack and explore other permutations.
2.	input_generator Function:
•	The input_generator function generates inputs for the permutation generation process.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of inputs (size of the array).
•	It iterates over different input sizes from 1 to 20.
•	For each input size n, it generates an array arr containing integers from 1 to n.
•	It performs the permutation generation process 10 times for each input size.
•	It measures the time taken using high_resolution_clock and calculates the average time over the 10 iterations.
•	It prints the input size n and the corresponding average time taken.
3.	main Function:
•	The main function:
•	Calls the input_generator function to generate inputs and store the time taken for each input size.
•	Prints a header indicating the number of inputs and the time taken.
•	Prints the input size and the corresponding average time taken for each scenario.



Graph:
 

Time Complexity:
Since, the total number of permutations of n elements is n!, therefore the time complexity is O(n!).
Recursive Relation =>P(n) = n*P(n-1)




7) Horners rule
1.	Horners Function:
•	The Horners function implements Horner's method to evaluate a polynomial represented by an array arr of coefficients.
•	It takes three parameters: the vector arr, the current index i, and the value of x.
•	The base case of the recursion is when i equals the size of the array arr, indicating that all coefficients have been processed.
•	At each recursive step, it evaluates the polynomial using the formula arr[i] + x * Horner(arr, i + 1, x).
•	It returns the result of the polynomial evaluation.
2.	input_generator Function:
•	The input_generator function generates inputs for evaluating the polynomial using Horner's method.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of inputs (size of the coefficient array).
•	It iterates over different input sizes from 10 to 10,000 with a step size of 500.
•	For each input size i, it generates a vector arr of coefficients using generate function with random numbers.
•	It performs the polynomial evaluation using Horner's method 10 times for each input size.
•	It measures the time taken using high_resolution_clock and calculates the average time over the 10 iterations.
•	It prints the input size i and the corresponding average time taken.
3.	main Function:
•	The main function:
•	Calls the input_generator function to generate inputs and store the time taken for each input size.
•	Prints a header indicating the number of inputs and the time taken.
•	Prints the input size and the corresponding average time taken for each scenario.



8) Kth smallest number
1.	Partition Function:
•	The Partition function partitions the array arr around a pivot element chosen from the array.
•	It takes three parameters: the vector arr, the low index low, and the high index high.
•	It initializes two pointers i and j pointing to the low and high indices respectively.
•	It selects the pivot element as the element at index low.
•	It iterates while i is less than j.
•	In each iteration, it moves i to the right until it finds an element greater than the pivot, and moves j to the left until it finds an element less than or equal to the pivot.
•	If i is less than j, it swaps the elements at indices i and j.
•	After the while loop, it swaps the pivot element with the element at index j and returns j, which is the final position of the pivot after partitioning.
2.	kthPartition Function:
•	The kthPartition function finds the kth smallest element in the array using the Quickselect algorithm.
•	It takes four parameters: the vector arr, the low index low, the high index high, and the value of k.
•	It recursively partitions the array around a pivot and checks if the pivot is the kth smallest element.
•	If the pivot is found at index k, it returns the element at that index.
•	If k is less than the pivot index, it recursively calls kthPartition on the left subarray.
•	If k is greater than the pivot index, it recursively calls kthPartition on the right subarray.
3.	input_generator Function:
•	The input_generator function generates inputs for finding the kth smallest element using the Quickselect algorithm.
•	It takes a vector of pairs store as a parameter to store the time taken and the number of inputs (size of the array).
•	It iterates over different input sizes from 10 to 10,000 with a step size of 1000.
•	For each input size i, it generates a vector arr of random integers.
•	It performs the kth smallest element search 10 times for each input size.
•	It measures the time taken using high_resolution_clock and calculates the average time over the 10 iterations.
•	It stores the input size i and the corresponding average time taken in the store vector.
4.	main Function:
•	The main function:
•	Calls the input_generator function to generate inputs and store the time taken for each input size.
•	Prints a header indicating the number of inputs and the time taken.
•	Prints the input size and the corresponding average time taken for each scenario.




9) Power of the number

1.	Power Function:
•	The Power function calculates the value of x raised to the power of n.
•	It takes two parameters: x (the base) and n (the exponent).
•	It uses a recursive approach to compute the power efficiently.
•	If n is 0, it returns 1 (base case).
•	If n is 1, it returns x.
•	Otherwise, it recursively calculates the power using the formula Power(x, n / 2), and based on whether n is even or odd, it calculates the final result accordingly.
2.	main Function:
•	The main function initializes a variable i with an initial value of 100,000.
•	It enters a do-while loop that iterates until i becomes equal to 10,000,000.
•	Inside the loop:
•	It sets the base x to 2.
•	It sets the exponent n to the value of i.
•	It measures the time taken by the Power function to compute x raised to the power of n for 100 iterations using the clock function.
•	It calculates the average time taken per iteration and prints it.
•	It increments i by 10 in each iteration of the loop.


Time Complexity:
Since the loop is being executed for ‘n’ times i.e., power, the time Complexity using this method comes out to be O(n).


10) Merging 2 list
1.	randomnumbers Function:
•	This function generates n random numbers and appends them to the input vector arr.
•	It takes two parameters: arr (the vector to which random numbers are added) and n (the number of random numbers to generate).
•	It iterates n times, generating random numbers between 0 and 99 using rand() % N, where N is 100, and appends them to arr.
•	Finally, it returns the modified vector arr.
2.	print Function:
•	This function prints the elements of the input vector arr.
3.	Mergelists Function:
•	This function merges two sorted lists arr1 and arr2 into a single sorted list arr3.
•	It takes two parameters: arr1 and arr2, which are assumed to be sorted.
•	It initializes an empty vector arr3 to store the merged list.
•	It initializes two pointers start1 and start2 to the beginning of arr1 and arr2, respectively.
•	It iterates as long as both start1 and start2 are within their respective vector sizes.
•	During each iteration, it compares the elements pointed by start1 and start2, and appends the smaller one to arr3, incrementing the corresponding pointer.
•	After one of the lists is exhausted, it appends the remaining elements of the other list to arr3.
•	Finally, it returns the merged vector arr3.
4.	main Function:
•	The main function initializes an empty vector merged to store the merged lists.
•	It iterates over different input sizes from 1000 to 1000000 with a step size of 20000.
•	For each input size, it generates random numbers using the randomnumbers function and splits them into two vectors arr1 and arr2.
•	It measures the time taken by the Mergelists function to merge arr1 and arr2 for 100 iterations using the clock function.
•	It calculates the average time taken per iteration and prints it for each input size.


The time complexity of the merge operation in the Mergelists function is O(n), where n is the total number of elements in both lists combined.


11)Magic square
1.	generateMagicSquare Function:
•	This function generates a magic square of size n.
•	It initializes a 2D vector magicSquare of size nxn with all elements initialized to 0.
•	It initializes two variables i and j to the middle column and last row respectively.
•	It iterates from 1 to nxn to fill in the magic square.
•	It handles the edge cases when i or j goes out of bounds by wrapping them around to the other side of the square.
•	If the current cell is already filled, it moves two cells down and one cell to the right to place the next number.
•	Otherwise, it places the current number in the cell and moves one cell up and one cell to the right.
2.	main Function:
•	The main function initializes input_size to 3.
•	It enters a while loop that continues until input_size is less than 9999.
•	Inside the loop, it measures the time taken to generate the magic square 100 times for the current input_size.
•	It calculates the average time taken per generation and prints it along with the input size.
•	It increments input_size by 200 in each iteration.
This code provides insights into the time complexity of generating magic squares of different sizes. The time complexity of generating a magic square using this algorithm is generally considered to be �(�)O(n), where �n is the size of the square


12) Exact position of elements
1.	print Function:
•	This function prints the elements of a vector arr.
2.	randomnumbers Function:
•	This function generates n random numbers and appends them to the input vector arr.
•	It takes two parameters: arr (the vector to which random numbers are added) and n (the number of random numbers to generate).
•	It iterates n times, generating random numbers between 0 and 99 using rand() % N, where N is 100, and appends them to arr.
•	Finally, it returns the modified vector arr.
3.	exactPositionPivot Function:
•	This function performs a partitioning operation on the input array arr where the pivot element is placed at its exact position.
•	It takes one parameter: arr (the vector to be partitioned).
•	It initializes two pointers low and high to the beginning and end of the array respectively, and a variable pivotIndex to store the index of the pivot element (initially set to the first element).
•	It iterates while low is less than high.
•	During each iteration, it moves low to the right until it finds an element greater than the pivot and moves high to the left until it finds an element less than or equal to the pivot.
•	If low is less than high, it swaps the elements at indices low and high.
•	After the while loop, it swaps the pivot element with the element at index high, placing the pivot at its exact position.
•	Finally, it returns the modified array arr.
4.	main Function:
•	The main function initializes an empty vector arr.
•	It iterates over different input sizes from 1000 to 1000000 with a step size of 20000.
•	For each input size, it generates random numbers using the randomnumbers function and measures the time taken to perform the partitioning operation 100 times for the current input size.
•	It calculates the average time taken per operation and prints it along with the input size.



13) Max Min of elements
1.	MaxMin Function:
•	This function takes a vector arr, start index start, end index end, and references to variables max and min.
•	If start is equal to end, it means there's only one element in the array, so both max and min are set to that element.
•	If start is end - 1, it means there are two elements in the array. It compares these two elements and assigns the maximum to max and the minimum to min.
•	Otherwise, if there are more than two elements, it calculates the middle index mid and recursively calls MaxMin for the left half (start to mid) and the right half (mid + 1 to end).
•	After getting the maximum and minimum values from both halves, it updates max and min based on these values.
2.	Main Function:
•	In the main function, a sample array arr is initialized with some values.
•	It initializes variables max_val and min_val to store the maximum and minimum values respectively, and initializes them with the maximum and minimum possible integer values using INT_MIN and INT_MAX.
•	It then calls the MaxMin function with the array, start index 0, end index n - 1 (where n is the size of the array), and references to max_val and min_val.
•	Finally, it prints the maximum and minimum values found




This algorithm divides the array into halves recursively, reducing the problem size by half at each step. Therefore, the time complexity of this algorithm is O(n), where \n is the size of the array.


14) Quick sort
1)	Choose Pivot: Select a pivot element from the array. This pivot will be used to partition the array.
2)	Partitioning: Rearrange the array elements such that all elements smaller than the pivot are moved to its left, and all elements greater than the pivot are moved to its right.
3)	Recursion: Recursively apply the above steps to the sub-arrays on the left and right of the pivot.
4)	Base Case: The recursion terminates when the sub-array size becomes 1 or 0.
5)	Combine: No explicit combination step is needed as the array is sorted in place during the partitioning step.
6)	Repeat: Repeat steps 1-5 for each sub-array until the entire array is sorted.

Graph:
 

Time Complexity:
The recursive relation for quick sort is :T(n)=T(k)+T(n−k−1)+O(n)
Therefore on solving this we get the time complexity: O(nlogn)


15) Iterative Quick Sort
Choose a Pivot: Choose a pivot element from the array. This can be done in various ways, such as selecting the first, last, or middle element.
Partitioning:
Partition the array into two subarrays: elements less than the pivot and elements greater than or equal to the pivot. This is done by rearranging the elements so that all elements less than the pivot are on its left and all elements greater than or equal to the pivot are on its right.
Push Ranges to Stack:
Instead of making recursive calls to sort the subarrays, we keep track of the ranges of subarrays using a stack. Initially, we push the range of the entire array onto the stack.
Iterative Process:
While the stack is not empty:
Pop a range from the stack.
Partition the subarray within this range using the pivot element.
If there are subarrays on the left and right of the pivot, push their ranges onto the stack.
Repeat until the stack is empty.
Complete Sort:
Once the stack is empty, all subarrays have been partitioned and sorted. The array is now fully sorted.

Graph:




Time Complexity :O(nlogn)



16) Merge Sort
Divide: Divide the unsorted array into two halves recursively until each sub-array has only one element. Split the array into halves by finding the middle index.
Conquer: Sort each sub-array recursively by applying Merge Sort to each half of the array.
Merge: Merge the sorted sub-arrays back into one sorted array by comparing the elements of the two sub-arrays and merging them in sorted order.

Graph:
 

Time Complexity:
The recursive relation for merge sort is: T(n) = 2T(n/2) + O(n)
Solving this recursive relation, we get time complexity : O(nlogn).


17) Knapsack 
1.	obj class:
•	This class represents an object/item with attributes profit, weight, and profitByWeight.
•	The constructor initializes the object with the provided profit and weight, and calculates the profit-to-weight ratio.
2.	cmpProfit function:
•	This is a comparison function used to sort objects based on their profit in descending order.
3.	cmpWeight function:
•	This comparison function is used to sort objects based on their weight in descending order.
4.	cmpProfitbyWeight function:
•	This comparison function is used to sort objects based on their profit-to-weight ratio in descending order.
5.	greedyKnapsack function:
•	This function takes a vector of objects objList and the maximum weight maxWeight as input.
•	It sorts the objects in objList based on their profit-to-weight ratio in descending order.
•	It iterates through the sorted list of objects and greedily selects objects as long as there is capacity in the knapsack (maxWeight) to accommodate them.
•	If an object cannot be fully included in the knapsack, it takes a fraction of it based on the remaining capacity.
•	Finally, it prints the maximum profit earned.
6.	main function:
•	In the main function, a vector objList is initialized with objects representing items, each with a profit and weight.
•	The maximum weight constraint (maxWeight) for the knapsack is also initialized.
•	The greedyKnapsack function is called with objList and maxWeight as arguments.

time complexity O(m)

18) Prims algo
1.	findMinCostVertex function:
•	This function finds the vertex with the minimum cost edge from the current set of vertices. It iterates through all vertices and checks if the cost of the edge to the nearest vertex (near[i]) is less than the current minimum cost.
•	Time complexity: O(V), where V is the number of vertices.
2.	minCostedge function:
•	This function finds the edge with the minimum cost in the given cost matrix.
•	It iterates through all elements of the cost matrix.
•	Time complexity: O(V^2), where V is the number of vertices.
3.	primAlgorithm function:
•	This function implements Prim's algorithm.
•	It starts by selecting an edge with the minimum cost (minCostedge function) and initializes the minimum cost and the near array.
•	Then, it iterates through all vertices to find the next vertex to add to the minimum spanning tree.
•	Inside the loop, it calls the findMinCostVertex function and updates the minimum cost and near array accordingly.
•	Time complexity: O(V^2), where V is the number of vertices.
4.	Main Function:
•	The main function takes input for the number of vertices and edges, constructs a graph, and calls the primAlgorithm function to find the minimum cost of the spanning tree and the edges in the spanning tree.
•	Time complexity: It depends on the time complexity of the primAlgorithm function.
Overall, the time complexity of the Prim's algorithm implementation in this code is O(V^2), where V is the number of vertices in the graph.


19) Multistage graph
1.	number_stages function:
•	This function calculates the number of stages in the graph. It iterates through the cost matrix and counts the number of stages where there is at least one non-zero cost edge.
•	Time complexity: O(V^2), where V is the number of vertices.
2.	calculateNumStages function:
•	This function calculates the number of stages in the graph. It iterates through the cost matrix and finds the maximum stage index (0-based) encountered.
•	Time complexity: O(V^2), where V is the number of vertices.
3.	fcost function:
•	This function calculates the minimum cost path using dynamic programming.
•	It initializes arrays to store the cost (fcost) and the predecessor (d) for each vertex.
•	It iterates through the vertices in reverse order and calculates the minimum cost path from each vertex to the destination.
•	Time complexity: O(V^2), where V is the number of vertices.
4.	Main Function:
•	The main function initializes the cost matrix and calls the fcost function to find the minimum cost path.
•	Time complexity: It depends on the time complexity of the fcost function, which is O(V^2).
