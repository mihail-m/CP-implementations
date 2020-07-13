# Basic Data Structures:

## Linked list
- List of elements spread across the memeory with one way links between them.

- O(1) access to the first element and the last element

- O(1) adding to the beginning and the ending

- O(n) complexity for insertion and delition in the middle

- O(n) complexity to find an element in the list

- <p> Elements are represented as pairs of a value and a link, and the link is a pointer to the next element. We keep a pointer to the beginning of the list, so that we are able to access it.<br>
      We can also store an additional pointer to the end of the list to speed up adding to the end and accesing the last element, because they are common operations. <br>

      |-------------------------------|
      | pointer to the last element  -----------------------------------------
      |-------------------------------|                                      |
                                                                             |
                                                                             |
                                            |-------|     |-------|          |     |-------|
                                            | value |     | value |          |---> | value |
      |-------------------------------|     |-------|     |-------|                |-------|
      | pointer to the first element -----> | link -----> | link -----> ... -----> | link -----> nullptr        
      |-------------------------------|     |-------|     |-------|                |-------|
  </p>

## Doubly linked list
- List of elements spread across the memeory with two way links between them.

- O(1) access to the first element and the last element

- O(1) adding to the beginning and the ending

- O(n) complexity for insertion and delition in the middle

- O(n) complexity to find an element in the list

- <p> Elements are represented as triplets of a value and two links, the links are pointers to the next and previous elements. We keep pointers to the beginning and ending of the list.<br>

      |-------------------------------|
      | pointer to the last element  -----------------------------------------
      |-------------------------------|                                      |
                                                                             |
                                                                             |
                                            |-------|     |-------|          |      |-------|
                                            | value |     | value |          |----> | value |
      |-------------------------------|     |-------|     |-------|                 |-------|
      | pointer to the first element -----> | next -----> | next -----> ...  -----> | next -----> nullptr        
      |-------------------------------|     |-------|     |-------|                 |-------|
                                            |       |     |       |                 |       |
                                nullptr <----- prev | <----- prev | <-- ... <--------- prev |
                                            |-------|     |-------|                 |-------|
  </p>

## Stack
- A data structure that allows access only to the most recently added element.

- O(1) complexity to add element.

- O(1) comlexity to remove element.

- O(1) complexity to get the top most element (the most recently added one).

- <p> There are 2 ways to represent a stack:<br>
      - with an array<br>
      - with a linked list<br>
      
  In the general case the array representation is faster.</p>
   
     <p align="center">
       <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Stack.png">
     </p>

## Queue
- A data structure that allows access only to the least recently added element.

- O(1) complexity to add element.

- O(1) comlexity to remove element.

- O(1) complexity to get the first element (the least recently added one).

- <p> There are 2 ways to represent a queue:<br>
      - with an array<br>
      - with a linked list<br>
      
  In the general case the array representation is faster.</p>
  
   <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/Queue.png">
   </p>


## Min(Max) stack
- A stack supporting min element retreival in O(1) time.

- <p>The idea is that we can store a single value representing the minimum element in the stack. Each time we add a new element to the stack we update the minumim if the newly added element is smaller.<br>
     
     What happens when we need to remove the minimum element from the stack? The naive approach is to iterate over all elements in the
     stack an update the minimum value, but can it be done faster? The answer is yes. <br>
     
     One approach will be to keep a second stack containing the minimum element at the top. Each time we add an element that is the
     new minumum, we add it to the second stack, and when we remove the curren minumum it will be at the top of the second stack, so we
     remove it from there too. The new top element will be the new minimum element in our original stack.<br>
     
     A better approach that does not require additional memory is to isert a modified value in the stack each time a new minimum is pushed. Every time we push a number that will become the new minimum, we store it as the minumum in our variable and push<br>
     2 * new_min - old_min instead. Since new_min < old_min => 2 * new_min - old_min < new_min.
     
     When we remove an element, if that element is smaller than the minimum, then this is the modified value that we iserted instead, so we need to update the minimum. The new minimum can be calculated as: 2 * minimum - top_element.
     
     If a top requiest is being processed and the top element is smaller than the curren mnimum we must return the minimum instead, because the stack has the modified value instead of the real one at the top.</p>
 
## Min(Max) queue
- A queue supporting min element retreival in O(1) time.

- <p>In order to acheive the required time we can use a doubly_linked_list in addition to our queue. The list will keep track of the minimum elements in the order they are in the queue. This way the front of the list will be the current minumum.<br>
      
     When we add a new element, we remove all elements from the back of the list that are bigger, since they will be removed from the queue before our new element and will never become the minumum. Then we add our new element to the back of the list.<br>
     
     When we remove an element from the queue, if that element is the same as the front of the list, we remove the front of the list too since it is the minumum.<br>
     
     When a request for the minumum is received, we simply return the front of the list since it is the current mimumum.</p>

## Heap
- A binary tree, that keeps its elements in such a way that every node has a priority that is greater than all of his descendants<br>
(all the nodes in its subtree). This way, the element with highest priority is always situated at the root node.<br>
We can use that data structure to keep track of the element with the highest priority in a chainging set of elements.<br>
The supported operations are: adding an element, removing the top element, getting the top element.

- The priority of an element can be determined by different factors. Usually it is determined by the element's value.<br>
  The two most common cases are:
    - larger elements have higher priority, this is called max heap and the larges element is allways at the root;
    - smaller elements have higher priority, this is called max heap and the smallest element is allways at the root.
 
 - O(log n) complexity to add an element.
 
 - O(log n) complexity to remove the top element.
 
 - O(1) complexity to get the elemet with the highest priority (situated at the root node).
 
 - <p>We can maintain a binary tree with the needed properties with the help of the observation that for a node to be in its place <br>
   it is enough for it to have a higher priorty than its two children. We can use two methods to keep our tree in order:<br>
      
    - heapify(element) -> a given element is pushed down the tree until it reches a place where the condition is satisfied;<br>
    
    - pull_up(element) -> a given element is pulled up the tree until it reches a place where the condition is satisfied.<br>
    
   Pushing down and pulling up is done by swapping the respective values. Both methods have O(lon n) complexity since their
   complexity is bound by the height of the tree.<br>
   
   - Each time we add a new element, we add it as a leaf and call pull_up to pull it up in place.<br>
   
   - Each time we remove the top element we swap it with a leaf, remove the leaf and call hepify at the root node to push it down in place.
   </p>
   
    <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/HeapImage.png">
   </p>


## Hash table
- Add element in O(1) time.

- Check if an element is contained in the table in O(1) time.

- <p> We will encode elements by their reminder when divided by some prime number MOD. This will be our hashing function.<br>
      
     If two numbers have the same reminder when divided by MOD we have a collision. Chosing a prime number helps to minimise the number of collisions, but they are inevitable when we try to encode a large ammount of numbers as a small set of values (hashes).<br>
     
     One way to deal with collistions is to use the bucket approach. Istead of just edcoding and keeping the hash value, we can instead keep a list of all values encoded as a specific hash in a bucket (list) containtin all those values.<br>
     
     When we add a new number to the hash table we add it to the bucket (list) of numbers coresponding to is encoded (hash) value.<br>
     
     When we check if a given number is contained in the hash table we check if it is contained in the bucket (list) coresponding to it's encoded (hash) value.<br>
     
     </p>
     
    <p align="center">
      <img src="https://github.com/mihail-m/CP-implementations/blob/master/resources/HashTableImage.png">
   </p>     

      

