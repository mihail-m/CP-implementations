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

## Queue

## Min(Max) stack

## Min(Max) queue

## Heap

## Hash table
  

