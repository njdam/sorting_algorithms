# Sorting algorithms & Big O

[Sorting algorithms]() are a fundamental part of computer science and are used to arrange elements in a specific order, typically in ascending or descending order. There are various sorting algorithms, each with different time complexities (Big O notation) and performance characteristics. The choice of the sorting algorithm depends on the specific requirements, input size, and the data distribution.

Here are some common sorting algorithms along with their average and worst-case time complexities (in Big O notation):

1. [Bubble Sort:]()

=> Average Case: `O(n^2)`
=> Worst Case: `O(n^2)`
Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process continues until the list is fully sorted.

2. [Selection Sort:]()

=> Average Case: `O(n^2)`
=> Worst Case: `O(n^2)`
Selection sort works by dividing the input into a sorted and an unsorted region. It repeatedly finds the minimum (or maximum) element from the unsorted region and places it at the end of the sorted region.

3. [Insertion Sort:]()

=> Average Case: `O(n^2)`
=> Worst Case: `O(n^2)`
Insertion sort builds the final sorted array one item at a time. It takes each element from the input and inserts it into the correct position in the sorted portion of the array.

4. [Merge Sort:]()

=> Average Case: `O(n log n)`
=> Worst Case: `O(n log n)`
Merge sort is a divide-and-conquer algorithm. It divides the input into halves, sorts each half recursively, and then merges the sorted halves to obtain the final sorted array.

5. [Quick Sort:]()

=> Average Case: `O(n log n)`
=> Worst Case: `O(n^2)` (when the pivot selection is not optimal)
Quick sort also uses a divide-and-conquer approach. It selects a pivot element, partitions the input around the pivot, and recursively sorts the subarrays.

6. [Heap Sort:]()

=> Average Case: `O(n log n)`
=> Worst Case: `O(n log n)`
Heap sort uses a binary heap data structure to sort elements. It first builds a max-heap (for ascending order) or a min-heap (for descending order) and then repeatedly extracts the root element to get the sorted array.

7. [Counting Sort:]()

=> Average Case: `O(n + k)` (when k is the range of input)
=> Worst Case: `O(n + k)`
Counting sort is efficient for sorting integers within a specific range. It counts the occurrences of each element and uses that information to place elements in the correct order.

[Note That:]() It's important to note that the time complexities mentioned above represent the worst-case scenarios. In some cases, sorting algorithms may perform better depending on the initial order of the elements. For example, Quick Sort and Merge Sort have average-case time complexities of O(n log n), but their performance may degrade to O(n^2) in the worst-case when the pivot selection is not optimal for Quick Sort, or when the merge step requires more time in Merge Sort. Therefore, understanding the average and worst-case complexities helps in choosing the appropriate sorting algorithm for a specific use case.

## Big Notation

[Big O notation](), commonly denoted as `O()`, is used in computer science and mathematics to describe the upper bound or worst-case complexity of an algorithm or function. It provides a way to express how the runtime or space requirements of an algorithm grow as the input size increases. The Big O notation is used to analyze and compare the efficiency of algorithms and to estimate their scalability.

In Big O notation, the letter "O" stands for "order of." When we say that an algorithm has a time complexity of `O(f(n))` or space complexity of `O(f(n))`, we mean that the growth rate of the algorithm's resource usage is proportional to the function `f(n)`, where "n" represents the input size.

Here are some common examples of Big O notations along with brief explanations:

1. [O(1) - Constant Time:]()
The algorithm's runtime or space requirements do not depend on the input size. It executes in constant time, making it very efficient.

2. [O(log n) - Logarithmic Time:]()
The algorithm's performance grows logarithmically with the input size. These algorithms are quite efficient and commonly seen in binary search or some divide-and-conquer algorithms.

3. [O(n) - Linear Time:]()
The algorithm's performance grows linearly with the input size. As the input increases, the execution time or space usage increases proportionally.

4. [O(n log n) - Linearithmic Time:]()
The algorithm's performance grows in-between linear and logarithmic time. This complexity is commonly found in efficient sorting algorithms like Merge Sort and Quick Sort.

5. [O(n^2) - Quadratic Time:]()
The algorithm's performance grows quadratically with the input size. These algorithms are less efficient and should be avoided for large inputs.

6. [O(n^k) - Polynomial Time (where k > 2):]()
The algorithm's performance grows polynomially with the input size. The efficiency decreases as the value of "k" increases.

7. [O(2^n) - Exponential Time:]()
The algorithm's performance grows exponentially with the input size. These algorithms are highly inefficient and become impractical for even moderate-sized inputs.

8. [O(n!) - Factorial Time:]()
The algorithm's performance grows factorially with the input size. These algorithms are extremely inefficient and are only practical for very small input sizes.

[Note That:]() It's important to choose algorithms and data structures with lower Big O complexities to ensure better performance and scalability for larger inputs. However, the actual implementation details, constant factors, and other considerations should also be taken into account when analyzing the real-world efficiency of an algorithm.

## Omega Notation

[Omega notation](), commonly denoted as `Ω()`, is another notation used in computer science and mathematics to describe the lower bound or best-case complexity of an algorithm or function. It is similar to Big O notation but represents the opposite perspective. While Big O notation provides an upper bound on the growth rate, Omega notation provides a lower bound.

In Omega notation, the letter "Ω" (capital omega) stands for "omega" which signifies "order of" like in Big O notation. When we say that an algorithm has a time complexity of `Ω(g(n))` or space complexity of `Ω(g(n))`, we mean that the growth rate of the algorithm's resource usage is at least proportional to the function `g(n)`, where "n" represents the input size.

Here are some common examples of Omega notations along with brief explanations:

1. [Ω(1) - Constant Lower Bound:]()
The algorithm's best-case runtime or space requirements are constant, independent of the input size. It means that the algorithm will take at least a constant amount of time or space to execute.

2. [Ω(log n) - Logarithmic Lower Bound:]()
The algorithm's best-case performance grows at least logarithmically with the input size. It means the algorithm will take at least logarithmic time to execute.

3. [Ω(n) - Linear Lower Bound:]()
The algorithm's best-case performance grows at least linearly with the input size. It means the algorithm will take at least linear time to execute.

4. [Ω(n log n) - Linearithmic Lower Bound:]()]
The algorithm's best-case performance grows at least in-between linear and logarithmic time. It means the algorithm will take at least linearithmic time to execute.

5. [Ω(n^2) - Quadratic Lower Bound:]()
The algorithm's best-case performance grows at least quadratically with the input size. It means the algorithm will take at least quadratic time to execute.

6. [Ω(n^k) - Polynomial Lower Bound (where k > 2):]()
The algorithm's best-case performance grows at least polynomially with the input size. It means the algorithm will take at least polynomial time with the exponent "k" as a lower bound.

[Note That:]() The Omega notation is useful for describing the best-case scenarios of an algorithm. Together with Big O notation, which describes the worst-case scenarios, they provide a more complete understanding of the algorithm's behavior across different inputs. Similar to Big O notation, the actual implementation details and constant factors should be taken into account when analyzing the real-world efficiency of an algorithm.

