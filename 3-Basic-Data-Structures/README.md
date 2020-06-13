# Basic Data Structures:

## Linked list
- List of elements spread across the memeory with one way links between them.

- O(1) access to the first element and the last element

- O(1) adding to the beginning and the ending

- O(n) complexity for insertion and delition in the middle

- O(n) complexity to find an element in the list

- <p> Elements are represented as pairs of a value and a link, and the link is a pointer to the next element. We keep a pointer to the beginning of the list, so that we are able to access it.<br>
      We can also store an additional pointer to the end of the list to speed up adding to the end and accesing the last element, because they are common operation. <br>

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

- <p> Elements are represented as triplets of a value and two links, the links are pointers to the next and previous elements. We keep a pointes to the beginning and ending of the list.<br>

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
      
  In the general case the array representation is faster. A visual representation would look something like this:<br>

              ↓ ↑
          |   top   |
          |---------|                            |-------|     |-------|                |-------|
          | element |                            | value |     | value |                | value |
          |---------|               |------|     |-------|     |-------|                |-------|
              ...                   | top -----> | link -----> | link -----> ... -----> | link -----> nullptr
          |---------|               |------|     |-------|     |-------|                |-------|          
          | element |
          |---------|                                    Linked list representation
      
      Array representation
   
     <p align="center">
       <img src="https://cdn.programiz.com/sites/tutorial2program/files/stack.png">
     </p>

## Queue
- A data structure that allows access only to the least recently added element.

- O(1) complexity to add element.

- O(1) comlexity to remove element.

- O(1) complexity to get the first element (the least recently added one).

- <p> There are 2 ways to represent a stack:<br>
      - with an array<br>
      - with a linked list<br>
      
  In the general case the array representation is faster. A visual representation would look something like this:</p>
  
   <p align="center">
      <img src="https://miro.medium.com/proxy/0*TRbfsq86lqDoqW6b.png">
   </p>


## Min(Max) stack

## Min(Max) queue

## Heap
- A binary tree, that keeps it's elements in such a way that every node has a priority that is greater than all of his descendants<br>
(all the nodes in it's subtree). This way, the element with highest priority is always situated at the root node.<br>
We can use that data structure to keep track of the element with highest priority in a chainging set of elements.<br>
The supported operations are: adding and element, removing the top element, getting the top element.

- The priority of an element can be determined by different factors. Usually it is determined by the elements value.<br>
  The two most common cases are:
    - when the larger elements have higher priority, this is called max heap and the larges element is allways at the root;
    - when the smaller elements have higher priority, this is called max heap and the smallest element is allways at the root.
 
 - O(log n) complexity to add an element.
 
 - O(log n) complexity to remove the top element.
 
 - O(1) complexity to get the elemet with the highest priority (situated at the root node).
 
 - <p>We can maintain a binary tree with the needed properties with the help of the observation that for a node to be in it's place <br>
   it is enough for it to have a higher priorty than it's two children. We can use two methods to keep our tree in order:<br>
      
    - heapify(element) -> a given element is pushed down the tree until it reches a place where the condition is satisfied;<br>
    
    - pull_up(element) -> a given element is pulled up the tree until it reches a place where the condition is satisfied.<br>
    
   Pushing down and pulling up is done by swapping the respective values. Both methods have O(lon n) complexity since their
   complexity is bound to the height of the tree.<br>
   
   - Each time we add a new element, we add it as a leaf and call pull_up to pull it up in place.<br>
   
   - Each time we remove the top element we swap it with a leaf, remove the leaf and call hepify no the root node to push it down in   place.
   </p>
   
    <p align="center">
      <img src="https://www.geeksforgeeks.org/wp-content/uploads/MinHeapAndMaxHeap.png">
   </p>


## Hash table
  

