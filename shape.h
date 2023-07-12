// *****************************************************************************************************
// Program 4 - CS 251 ; Spring 2023
// 
// Name: Srijita Banerjee
// netid: sbane4@uic.edu
// UIN: 675443340
// 
// - Shape class - 
// Implementation of Shape class to create shapes with their details which will be implemented as nodes in 
// a linked list (using CanvasList class)
//
// *****************************************************************************************************


#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};

// Defining default constructor
Shape::Shape () {
    x = 0;
    y = 0;
}

// Defining parameterized constructor
Shape::Shape (int x, int y) {
    this->x = x;
    this->y = y;
}

// Implementing destructor (what is "virtual"?)
Shape::~Shape () {

}

// Implementing copy constructor (again, what is "virtual"?)
Shape* Shape::copy () {
    // Allocating memory on heap for new object
    Shape* new_shape = new Shape ();
    new_shape->x = this->x;
    new_shape->y = this->y;
    return new_shape;
}

// Implementing getX function
int Shape::getX () const {
    return x;
}

// Implementing getY function
int Shape::getY () const {
    return y;
}

// Implementing setX function
void Shape::setX (int x) {
    this->x = x;
    return;
}

// Implementing setY function
void Shape::setY (int y) {
    this->y = y;
    return;
}

// Implementing printShape function - printing appropriate shape details
void Shape::printShape () const {
    cout << "It's a Shape at x: " << this->x <<" , y: " << this->y << endl;
    return;
}
// Defining default constructor for Circle class
Circle::Circle () {
    x = 0;
    y = 0;
    radius = 0;
}

// Defining parameterized constructor for Circle class: radius given as input
Circle::Circle (int r) {
    x = 0;
    y = 0;
    radius = r;
}

// Defining parameterized constructor for Circle class: x, y, radius given as input
Circle::Circle (int x, int y, int r) {
    this->x = x;
    this->y = y;
    radius = r;
}

// Defining destructor for Circle class
Circle::~Circle () {
    // what is virtual?
}

// Defining copy constructor for Circle class
// how do I do that?
Circle* Circle::copy () {
    // Allocating memory on heap for new object for Circle class
    Circle* new_circle = new Circle ();
    new_circle->x = this->x;
    new_circle->y = this->y;
    new_circle->radius = this->radius;
    return new_circle;
}

// Defining function getRadius
int Circle::getRadius () const {
    return radius;
}

// Defining function setRadius
void Circle::setRadius (int r) {
    radius = r;
    return;
}

// Implement printShape function
void Circle::printShape () const {
    cout << "It's a Circle at x: " << this->x << ", y: " << this->y << ", radius: " << radius << endl;
}

// Defining default constructor for Rectangle class
Rectangle::Rectangle () {
    width = 0;
    height = 0;
    x = 0;
    y = 0;
}

// Defining parameterized constructor for Rectangle class: width and height given as input
Rectangle::Rectangle (int w, int h) {
    width = w;
    height = h;
    x = 0;
    y = 0;
}

// Defining parameterized constructor for Rectangle class: width, height, x, and y given as input
Rectangle::Rectangle (int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    width = w;
    height = h;
}

// Implementing destructor for Rectangle class
Rectangle::~Rectangle () {

}

// Defining copy constructor for Rectangle class
Rectangle* Rectangle::copy () {
    Rectangle* new_rectangle = new Rectangle ();
    
    new_rectangle->x = this->x;
    new_rectangle->y = this->y;
    new_rectangle->width = this->width;
    new_rectangle->height = this->height;

    return new_rectangle;
    
}

// Defining function getWidth
int Rectangle::getWidth () const {
    return width;
}

// Defining function getHeight
int Rectangle::getHeight () const {
    return height;
}

// Defining function setWidth
void Rectangle::setWidth (int w) {
    width = w;
    return;
} 

// Defining function setHeight
void Rectangle::setHeight (int h) {
    height = h;
    return;
}

// Defining printShape function for Rectangle class
void Rectangle::printShape () const {
    cout << "It's a Rectangle at x: " << this->x << ", y: " << this->y << " with width: " << width << " and height: " << height << endl;
    return;
}

// Defining default constructor for RightTriangle class
RightTriangle::RightTriangle () {
    base = 0;
    height = 0;
    x = 0;
    y = 0;
}

// Defining parameterized constructor for RightTriangle class: base and height provided
RightTriangle::RightTriangle (int b, int h) {
    base = b;
    height = h;
    x = 0;
    y = 0;
}

// Defining parameterized constructor for RightTriangle class: x, y, base, and height provided
RightTriangle::RightTriangle (int x, int y, int b, int h) {
    base = b;
    height = h;
    this->x = x;
    this->y = y;
}

// Defining destructor for class RightTriangle
RightTriangle::~RightTriangle () {

}

// Defining copy constructor for class RightTriangle
RightTriangle* RightTriangle::copy () {
    RightTriangle* new_rt = new RightTriangle ();

    new_rt->base = this->base;
    new_rt->height = this->height;
    new_rt->x = this->x;
    new_rt->y = this->y;
    
    return new_rt;
}

// Defining function getBase
int RightTriangle::getBase () const {
    return base;
}

// Defining function getHeight 
int RightTriangle::getHeight () const {
    return height;
}

// Defining printShape function for class RightTriangle 
void RightTriangle::printShape () const {
    cout << "It's a Right Triangle at x: " << this->x << ", y: " << this->y << " with width: " << base << " and height: " << height << endl;
}
