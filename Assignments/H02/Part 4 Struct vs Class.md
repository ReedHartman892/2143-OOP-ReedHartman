# Struct vs Class
(Same machine code, different intent)

#### What is a Struct?
A struct (structure) is a way to group several related variables of different data types under a single name.
 - I assume structs are good for smaller-scale things in a program. They read as the lesser of two evils, with class being ultimate evil.
 - Realistically a good candidate for a struct would be something like, a thing that has both X and Y coordinates, that also has a name. Thats two different data types associated with the same object. That would be good for a struct (I hope.)

#### What is a Class?
A class is a blueprint or prototype from which objects are created, combining fields (data) and methods (functions) into a single, well-encapsulated unit.
 - Classes read like they're used to make whole modules within a program. Superior evil, given they combine data and functions.
 - I've already heard of things like subclasses and superclasses, and because I have not heard of substructs or superstructs, I assume classes are intrinsically more complex than structs. That higher complexity is probably good for program abstraction.
 - main is a class. The main class. It's the class that the program always runs after compilation.



### What is the only language-level difference between struct and class?
Default accessibility.
 - Structs default to public access for members and base classes.
 - Classes default to private access for members and base classes.

Class and structs are interchangeable, technically speaking. Both can have methods, constructors, and inheritance. Their only difference is default access level.

### Why does C++ even allow both?
A few reasons:
 - Backwards compatability, specifically with the C programming language (C++ branches from C, and C++ inherits features from C, and one of those features is structs)
 - Expressing Intent/Conversion: Although functionally almost identical in C++, the two keywords are used by convention to communicate the intended use to other programmers. This is mainly a intuition/culture thing, I believe. You use structs for simple stuff, and classes for complex stuff.

### When does choosing struct communicate intent better thn class?
when you want to represent a single, immutable, and self-contained value (value semantics)

### Why does intent matter more than syntax in large systems?
Intent matters more than syntax in large systems because it captures the, "why" and, "what" of complex goals rather than just the "how," enabling flexibility, scalability, and resilience against rapidly changing environments. 




