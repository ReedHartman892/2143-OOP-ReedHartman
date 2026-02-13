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
### Write the correct constructor.
### Name the other situation where initalization lists are required (research-lite)

# Copy Constructor vs Assignment Operator
