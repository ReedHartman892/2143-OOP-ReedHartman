# What Are Stacks and Queues, and Arrays and Lists?
 - Stacks and Queues are abstract data types (ADTs) that define specific behaviors or data access and modification.
 - Arrays and Lists are the concrete structures used to implement stacks and queues.

### Stacks and Queues
 - Stacks: Last-in, First-out (LIFO). Elements are added (push) and removed (pop) from only one end, called the top.
 - Queues: First-in, First-out (FIFO). Elements are added (enueue) at the rear and removed (dequeue) from the front.

### What is Cache Friendliness?
 - I believe it is just a very fancy way of stating "how good is a data structure at storing data in a computer, compactly?"

### Array-based Versus List-based
| Feature | Array-based | List-based |
|---|---|---|
| Memory Layout | Block in memory, less memory usage, waste space if mostly empty. (Contiguous) | Dynamic in memory, linked by pointers (non-contiguous). Less efficient per element, (pointers), memory use based on data stored. |
| Resizing Behavior | Fixed size, limited on initialization | Dynamic size, no limit on initialization |
| Cache Friendliness | High, nearby data is loaded into cache | Low due to dynamic memory making cache misses common |
