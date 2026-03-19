# Operator Overloading
(Where ADTs Start Feeling Real)

## Rules I Don't Get To Ignore
### 1. Why can't C++ Overload:
   - (sizeof)
   - (::)
   - (.)

Mainly because they're all baked into C++'s core functionality. Specifically, however, its because of compile-time evaulation, fundamental language rules and memory management, plus syntactical and design constraints. Trying to overload any of these violates the program's core functionality.

### 2. Why should operator+ not mutate the left-hand operand?
It violates the fundamental and widely expected meaning of the addition operator

### 3. Why is operator<< almost never a member function?
It is almost never a member function because it requires a std::ostream& as the left-hand operand, not your class type. Making it a member function forces the syntax obj << cout, whereas a non-member function allows the correct cout << obj syntax. 
