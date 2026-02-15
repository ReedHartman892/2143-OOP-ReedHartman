// Reed Hartman
// Terry Griffin
// Object-Oriented Programming
// Feburary 15th, 2026
/*****************************/
#include <iostream>
#include <stdexcept>

class Point2D {
private:
    int x_;
    int y_;

public:
    // Constructor
    Point2D(int x = 0, int y = 0) : x_(x), y_(y) {}
    
    // Getters
    int x() const { return x_; }
    int y() const { return y_; }

    // += operator
    Point2D& operator+= (const Point2D& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }

    // + operator
    Point2D operator+ (const Point2D& other) const {
        Point2D temp = *this;
        temp += other;
        return temp;
    }

    // - operator
    Point2D& operator-= (const Point2D& other) {
        x_ -= other.x_;
        y_ -= other.y_;
        return *this;
    }

    Point2D operator- (const Point2D& other) const {
        Point2D temp = *this;
        temp -= other;
        return temp;
    }

    // Output operator
    friend std::ostream& operator << (std::ostream& os, const Point2D& p) {
        return os << "(" << p.x_ << ", " << p.y_ << ")";
    }

    // comparison operator
    bool operator==(const Point2D& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
};

int main()
{
    Point2D a(3, 4);
    Point2D b(1, 2);

    Point2D c = a + b;
    Point2D d = a - b;

    if (c == Point2D(4, 6)) {
        std::cout << "Math still works.\n";
    }

    std::cout << a << std::endl;
    std::cout << d << std::endl;
}
