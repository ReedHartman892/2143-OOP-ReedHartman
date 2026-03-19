# Friend or Design Smell?

### What does the friend keyword actually do?
The friend keyword in C++ is a mechanism that allows a function, a member function of another class, or an entire class to access the private and protected members of the class that declares it as a friend. This creates a tightly coupled relationship and provides a way to selectively bypass the normal access control rules of object-oriented programming for specific, trusted components. 

### Why is operator<< commonly declared as a friend?
operator<< is commonly declared as a friend in C++ because it must be implemented as a non-member function to allow the left-hand operand to be std::ostream rather than the class itself, while still requiring access to the class's private or protected data members for printing. This avoids exposing internal data via public getters. 

### Why is excessive use of friend a red flag?
Excessive use of friend in C++ is a red flag because it breaks encapsulation by allowing external classes or functions to access private/protected members, leading to tightly coupled, disorganized, and harder-to-maintain code. While useful for specific, closely related classes (e.g., iterators), it should be used sparingly, as overuse makes code fragile and violates core object-oriented principles. 

### One legitmiate use case and one illegitimate one.
 - A legitimate use of friend in C++ is overloading operators (e.g., <<, +) to allow symmetric, non-member access to private data.
 - An illegitimate use is bypassing encapsulation to allow arbitrary, unrelated functions to modify private members, which breaks object-oriented design principles and increases coupling. 
