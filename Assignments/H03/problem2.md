## Problem 2 Solution

```cpp
#include <string>
using namespace std;

class Player {
    private:
    string name;
    int level;
    int score;

    public:
    // constructors
    Player(){} // default constructor
    Player(string n, int l) : name(n), level(l) {} // parameterized constructor

    // getters
    string getName(){return name;}
    int getLevel(){return level;}
    int getScore(){return score;}

    // setters
    void setName(string n){name = n;}
    void setLevel(int l){level = l;}
    void setScore(int s){score = s;}

};
```
