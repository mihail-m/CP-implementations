# Searching:

  - Binary search:
  
    - Search for an element in a sorted array.
    - Search for the minimal/maximal value for which a given monotonous function statisfies some condition.
    - O(log n) complexity.
    - The general idea is that when we have some interval defined by [l, r] and we are searching for a value v in the interval.
      We can simply check in which half of the interval v resides. If m is the middle of the interval [l, r], there are 3 cases: 
        1. v is at m (we have nothing more to do here), 
        2. v is in [l, m - 1] (the interval has shrunk in half),
        3. v is in [m + 1, r] (the interval has shrunk in half).
      After shrinking out interval enough times it will consist of only a single value. It is easy to see that we will shrink the interval at most log2 (r - l + 1) times, 
      because after every shrink the size is halved, hense we have (r - l + 1), (r - l + 1) / 2, (r - l + 1) / 2^2, ..., (r - l + 1) / 2^log2 (r - l + 1) = 1 => O(log2 (r - l + 1)).

  ## Jump search:
  
    - Search for an element in a sorted array.
    - O(sqrt(n)) complexity.
    - The idea is that we can split out array in blocks of size sqrt(n), where n is the size of the array. This way we can check if the value we are searching for is smaller than the last element of every block. 
      The first block that has a bigger last element is the only block that can be containg the value, because all elements in the following blocks are certainly bigger and all elements in the previous blocks
      are certainly smaller, because we know that the array is sorted. This allow us to find the correct block in O(sqrt(n)), because we have to check only the last element of every block (which are sqrt(n)). And after
      that O(sqrt(n)) more steps to find if the value is in the chosen block, because we know that every block also has a size of sqrt(n) => O(sqrt(n) + sqrt(n)) = O(sqrt(n)). 
    
  ## Exponential search:
  
    - Search for an element in a sorted array.
    - Search for the maximal value for which a given monotonous function statisfies some condition.
    - O(log n) complexity.
    - The idea is that we split our array in blocks of size 2^i, for i = 1, 2, 3, ..., log2(n) and possibly some smaller last block and after that we can find which block contains the value we are searching for,
      by checking the last element from it. When we find the needed block we can use binary search in it to check for our value. There will be at most log2(n) + 1 blocks and the complexity of the binart search is
      also O(log2(n)) => O(log2(n)) overall. This search is usefull when we are searching for the maximal value for which the function satisfies some condition but we don't know how big that value can be.

  ## Ternary search:
  
    - Search for an element in a sorted array.
    - Search for the minimal/maximal value for which a given unimodal function statisfies some condition.
    - O(log n) complexity.
    - The idea is almost the same a the binary search, but we split the interval in 3 parts, hense we can also work with unimodal fucntions.	

  ## Quick select:
  
    - Search for the k-th smallest element in an array.
    - n average case complexity but n^2 worst case (happens rarely enough).
    - We will use the fact that we can choose a random element from an array and order the array in such a way that all smaller elements are before the chosen element and all bigger are after it. More importantly
      this can be done in linear time (O(n)). The idea is that we can choose a random element from our array and order the element in the above mentioned way. This way we will split out array in 2 subarrays:
        1. all elements smaller than the one we have chosen,
        2. all elements bigger than the onew we have chosen.
    - Then we have 3 cases to look at:
        1. The element we have chosen is the kth-smallest (then we are done),
        2. The element we have chosen is bigger than the k-th smalles (then we need only the first subarray),
        3. The element we have chosen is smaller than the k-th smalles (then we need only the second subarray).
    - We can continue to do this for each subbaray until we find the k-th smallest element. For each time this will take us linear time to do, but each time the subarray will be smaller. On average the prosedure
      will comlete after O(n) operations, but in the worst case scenario it will take O(n^2). The worst case happens rarely enough that this method is prefered over the sort and take the element an index k which
      takes O(n log n) time.
      
      
