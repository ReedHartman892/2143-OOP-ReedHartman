# What Are Stacks and Queues, and Arrays and Lists?
 - Stacks and Queues are abstract data types (ADTs) that define specific behaviors or data access and modification.
 - Arrays and Lists are the concrete structures used to implement stacks and queues.

### 1 - Array-based vs List-based
| Feature | Array-based | List-based |
|---|---|---|
| Memory Layout | Block in memory, less memory usage, waste space if mostly empty. (Contiguous) | Dynamic in memory, linked by pointers (non-contiguous). Less efficient per element, (pointers), memory use based on data stored. |
| Resizing Behavior | Fixed size, limited on initialization | Dynamic size, no limit on initialization |
| Cache Friendliness | High, nearby data is loaded into cache | Low due to dynamic memory making cache misses common |

##### What is Cache Friendliness?
 - I believe it is just a very fancy way of stating "how good is a data structure at storing data in a computer, compactly and locally?"

##### What does Contiguous Mean?
 - Refers to data elements stored in adjacent, unbroken sequential memory locations, with no gaps between them.

### 2 - std::vectors fit for a stacks, but are awkward for queues
 - std::vector is ideal for stacks (LIFO) because its push and pop operations are 
O(1) amortized time, matching the behavior of adding/removing from the top of a stack.
 - std::vector is awkward for queues (FIFO) because removing the front element requires shifting all remaining elements, resulting in inefficient O(n) time.

##### What Is The O(n) Thing?
 - Means linear time operation. Refers to accessing, searching for, or manipulating elements that are not at the immediate top (stack) or front queue.
 - Basically, I think it's just computer lingo for how a computer finds and accesses stack/queue elements. It's clunkier for queues because the elements arent neatly compacted like stacks are, which remain close where they are initalized in memory.
 - You have to spend more resources looking and manipulating which elements are a part of which queue using linear time operations.

### 3 - Stack and Queue Invariants
 - Invariants are the fundamental, unchanging rules governing how stacks and queues have data added, removed, and accessed.
 - Stacks: Last-in, First-out (LIFO). Elements are added (push) and removed (pop) from only one end, called the top.
 - Queues: First-in, First-out (FIFO). Elements are added (enueue) at the rear and removed (dequeue) from the front.
