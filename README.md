# Algorithme-FordJohnson
This is a C++ project that implements a sorting algorithm using a divide-and-conquer approach. The program takes a list of integers, pairs them, and recursively sorts and merges the pairs to produce a fully sorted list.


### How It Works
1. Pairing Elements: The program splits the list of integers into pairs, leaving one element unpaired if there’s an odd number of integers.
2. Comparing Pairs: It performs a comparison for each pair to determine the larger element.
3. Recursive Sorting: The program recursively sorts the larger elements from each pair, using the algorithm from the start until only 1 or 2 elements remain. This results in a sorted list of the larger elements in ascending order.
4. Inserting the Smallest Element's Pair: The element paired with the first and smallest element is inserted at the start of the sorted list.
5. Final Insertion: The remaining elements are inserted into the sorted list, one at a time, following a specific order based on the Fibonacci sequence and using binary search to determine each insertion position.


Users can pass the list of integers via command-line arguments:
```Bash
./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`)
```
