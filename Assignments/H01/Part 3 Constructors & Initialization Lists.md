# Initalization Lists or Else!
Given:

class Widget{
private:
	const int id;
  std::string name;

public:
  Widget(int id, std::string name);
};

### Why **must** this constructor use an initialization list?
 - because the devil told me to do it /j
 - In actuality, because you can't redefine private variables past-initalization if you never assign them a value. Many compliers are designed to know and detect nullpointers before running to make programming/debugging easier. Essentially, Constructors are like a first initalization.

### What happens if you try to assign id inside the constructor body?
 - You'd get a compilation error.
 - The constructor body is its own scope, technically.
 - Assignment is taking place, but constant variables can only be initialized.

### Write the correct constructor.
 - Widget(3, "name");

### Name the other situations where initalization lists are required (research-lite)
 - Constant Data Members (this one)
 - Reference Members: References must be initialized when declared and cannot be reassigned.
 - Base Classes Without Default Constructors: If a base class requires arguments, its parameterized constructor must be explicitly called in the derived class's initialization list.
 - Member Objects without Default Constructors: If a member object type lacks a default constructor, the initialization list must specify which constructor to use.
 - Performance Optimization: While not strictly required, initialization lists are preferred for performance to avoid double-initialization (default constructor + assignment).

### Copy Constructor vs Assignment Operator
| Feature | Copy-Constructor | Assignment Operator |
|---|---|---|
| Purpose | Initializes a brand new object with data from an existing object. | Replaces the data of an already initialized object with data from another existing object. |
| Object state | Object is uninitalized before the copy process begins | The left-hand object already exists and may hold resources that need cleanup |
| Return value | NO return value | returns a reference to the left-hand side object, which allows for chained assignments (e.g. a = b = c) |
| Dynamic Memory | Allocates new memory for the new object and performs a deep copy if user-defined. | Must first deallocate the left-hand object's existing dynamic memory, then allocate new memory and perform a deep copy if user-defined. |


