# Overloading vs Overriding
 - Overloading is a compile-time mechanism in the same class where methods have the same name but different signatures (parameters).
 - Overriding is a runtime mechanism between superclasses and subclasses where a subclass redefines an inherited method with the same name and signature. 

### Conceptual Distinction
| Feature | Overloading | Overriding |
|---|---|---|
| Resolved at | Compile time | Run time |
| inheritance | Not required | Required |
| Same function name | Multiple function names with different parameters | Subclass redefines a method that already exists within its superclass. |
| Polymorhism involved | In a single class (static) | A superclass and a subclass |

### Why is Overloading a compile-time Convenience?
Overloading is a compile-time convenience because the compiler determines which specific method or function to invoke by analyzing the argument types, number, and order at compile time. It enhances code readability and reduces complexity by allowing multiple methods to share the same name, with the compiler handling binding early, rather than at runtime. 


### Why is Overriding a runtime contract?
Overriding is considered a runtime contract because the exact method implementation to be executed is determined during program execution based on the actual object type, not the refer

### Why do beginners confuse the two?
Beginners often confuse overriding and overloading due to similar terminology ("over-"), the shared requirement of having the same method name, and both being object-oriented concepts used for polymorphism.

### Why is that confusion dangerous?
it leads to runtime errors, unintended method behavior, and difficult-to-debug code. 


