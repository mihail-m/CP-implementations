# Sorting:

Problem: Sort an array with n elements.

## Selection sort
- O(n^2) complexity.

- <p>For each position of the array choose the correct element by finding the minimal element from the elements with positions greater than the current one and swaping it with the current one.<br>

     When we are at postition i we have already picked the correct elements for positions 0, 1, ..., i - 1, so the correct<br>
     element for postition i will be the minimal element in the rest of the array: min(arr[i + 1], arr[i + 2], ..., arr[n - 1]).<br>
 
     Once we do this for each postition we end up with a sorted array.</p>
     
     <p align="center">
       <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/SelectionSort.gif">
     </p>

## Bubble sort
- O(n^2) complexity.

- <p>The idea is that every time we find a pair of consecutive elements that are in the wrong order we swap them.<br>

     We preform n interations. On the ith iteration we start at the end of the array and interate backwards utill we reach position i - 1. Every time we encounter two consecutive elements that are in the wrong order, we swap them.<br>

     Once we do this for each position we end up with a sorted array.</p>
     
     <p align="center">
       <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/BubbleSort.gif">
     </p> <br>

- <p>
     There is an interesting thing we can observe here: After each iteration, the smallest (or the largest, depending on the order we are sorting in) elemen of the unsorted part of the array finds its place - it "swims" to the front. That's why it is called "Bubble sort". <br>
     
     However, if the largest element was in the front in the beginning (and we are sorting in ascending order), it will take lots of iterations to put it in it's place. That is why, a slight modification of Bubble Sort exists - `Shaker Sort`. The idea is absolutely the same, but instead of always going forward, we iterate forward, then backwards, then forward again and so on. This does not decrease the asimptotic time complexity of the algorithm, but provides a marginal improvement.
   </p>

     <p align="center">
       <img src="https://upload.wikimedia.org/wikipedia/commons/e/ef/Sorting_shaker_sort_anim.gif">
     </p> <br>

## Insertion sort
- O(n^2) complexity.

- <p>We insert each element in such a postion that the already processed part of the array in sorted.<br>

     When we are at postion i we must find the minimum j such that arr[i] > arr[j]. Then we shift all elements at positions:<br>
     j, j + 1, ..., i one postition to the right and insert(assign) the current element to postion j.<br>
     
     Once we do this for each position we end up with a sorted array.</p>
     
     <p align="center">
       <img src="https://thumbs.gfycat.com/DenseBaggyIbis-size_restricted.gif">
     </p>

## Quick sort
- O(n logn) average case complexity and O(n^2) worst case.

- <p>We will use the fact that we can choose a random element from an array and order the array in such a way that all smaller elements are before the chosen element and all bigger are after it. More importantly this can be done in linear time (O(n)).<br>
  
     This can be done by considering each element consecutively and if it is smaller than the chosen element we put it in the beginning of our array.<br>

     The idea behind quick sort is that we can choose a random element from our array and order the elements in the above mentioned way. This way we will split out array in 2 subarrays:
     <ul>
       <li> all elements smaller than the one we have chosen,
       <li> all elements bigger than the onew we have chosen.
     </ul><br>
     Then we repeat the prosedure for each of the created subarrays until we end up with small enough subarrays: of size 1 or 0.<br>
     
     <p align="center">
       <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Partition.gif">
     </p>

     This will lead to a sorted array, because for every subarray of size 3 the above prosedure sorts its elements. And for the case where the subarray is of bigger size the algorithms splits it into 2 smaller subarrays such that all element in the first one are smaller then all elements in the second one are bigger. When the first part that contains all the smaller elements is sorted and the second part that contains all the bigger elements is sorted the subarray that is a concatenation of them is also sorted. </p>

## Merge sort
- O(n log n) complexity.

- <p>The idea is that we can split the array into 2 subarray with equial sizes and sort them insted, then we can merge them in linear time.<br>

     We split each subarray into 2 smaller subarrays: subarr[l, r] = left_subarr[l, mid] + right_subarr[mid + 1, r].<br>

     Once we get subarrays with size 1 we stop splitting and star merging.<br>

     We can merge all subarrays of sizes 1 into sorted subarrays of size 2. Then we can merge all subarrays of size 2 into sorted subarrays of size 4 and so on. Lastly we end up with <br>
     2 sorted subarrays of size n / 2 and we merge them in to one sorted array => the sorted version of our original array. 
     
     ![alt-text](https://github.com/mihail-m/CP-implementations/blob/master/resources/MergeSort.png)

     The overall complexity comes from merging all the subarrays. 
     <ul>
       <li> We merge 2 subarrays with length n / 2 in time n.
       <li> We merge 2^2 subarrays with length n / 2^2 in time n.
       <li> ...
       <li> We merge 2^log2(n) subarrays with length 1 in time n.
     </ul><br>
     => We have n operations log2(n) times => O(n log n).</p>

## Heap sort
- O(n log n) complexity.

- <p>The idea is to use a heap of the elements of the array and get the top of the heap util we go trough all the elements.<br>

     Insertion into a heap in with log n complexity and we do it n times => O(n log n) to build the heap. Removing the top happens in O(1) and we do it n times => O(n) times => overall complexity is O(n lon n) + O(n) = O(n log n).</p>

## Counting sort
- O(n + largest number) complexity.

- <p>The idea is to count how much times each element is contained in the array and then constuct the sorted array form that information.<br>

     We can keep a second array count[] that keeps track of the number of occurences of each element and after we have couned all elements we traverse count and construct the sorted array.<br>
     
     We need to keep in mind that there might be negative numbers.<br>

     We traverse the array once to count the elements and then we must traverse count until the largest encountered number => O(n + largest number).</p>

## Radix sort
- O(n * log(largest number)) complexity.

- <p>In order to sort the array we perform a counting sort for each digit of the numbers of the array.<br>

     <ul>
       <li>First we sort the numbers by their last digit.<br>
       <li>Then we sort them by their second to last digit.</p>
       <li>...
       <li>Lastly we sort them by their first digit.
     </ul><br>
     This procedure will yield a sorted array for obvious reasons I beleive.<br>

     We perform a counting sort with comlexity O(n + 10) = O(n) for evert digit) => O(n * log10(largest number)) = O(n log(largest number)).</p>
  

