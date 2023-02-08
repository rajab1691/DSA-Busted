### Linked List

- A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. 
- The elements in a linked list are linked using pointers 
- Doubly Linked List-A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer, together with 
                     next pointer and data which are there in singly linked list.
- Circular Linked List-Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end.


- Advantages over arrays 
  * Dynamic size 
  * Ease of insertion/deletion

- Disdvantages
  * Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with 
  linked lists efficiently with its default implementation 
  * Extra memory space for a pointer is required with each element of the list. 
  * Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists.
