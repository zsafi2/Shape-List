// Name: Zaheer Safi
// Date: 09/04/2023
// CS_251 Project_1 : Linked List where the Nodes hold information of shapes as Nodes.

#include "shape.h"
#include <iostream>

// default constructor
Shape::Shape()
{
    x = 0;
    y = 0;
} 

// constructor
Shape::Shape(int x, int y) 
        : x(x), 
          y(y) 
{ 
    
}

// destructor becuase we are not allocating any memory it should be empty
Shape::~Shape()
{
    //nothing here..
}

//function that return a copy of this class
Shape* Shape::copy()
{
    return new Shape(*this);
}

// function to access the value of x
int Shape::getX() const
{
    return x;
}

// function to access the value of y
int Shape::getY() const
{
    return y;
}

// function to change the value of x
void Shape::setX(int X)
{
    x = X;
}

// function ot change the value of y
void Shape::setY(int Y)
{
    y = Y;
}
        
// function to output the details of this class x and y values
string Shape::printShape() const
{
    return "It's a Shape at x: " + to_string(x) + ", y: " + to_string(y);; 
}

// Circle class which is a child class of the parent Shape class default constructor
Circle::Circle()
    : radius(0)
{
}

// constructor wiht only radius provided
Circle::Circle(int r)
    : radius(r)
{
}

// constructor with new x and y values and also the r
Circle::Circle(int x, int y, int r)
    : Shape(x, y), radius(r)
{
}

// destructor empty becuase we are not allocating any memeory
Circle::~Circle()
{
}

// return a copy of this class
Circle* Circle::copy()
{
    return new Circle(*this);
}


// radius accessor outside the class
int Circle::getRadius() const
{
    return radius;
}

// radius setter outside the class
void Circle::setRadius(int r)
{
    radius = r;
}

// this is circle version of printShape virtusl function to print the details of circle class
string Circle::printShape() const 
{
    return "It's a Circle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
           ", radius: " + to_string(radius);
}

// Rect class again a child  class of Shape
Rect::Rect()
    : width(0), height(0)
{
}

// constructor
Rect::Rect(int w, int h)
    : width(w), height(h)
{
}

// another constructor
Rect::Rect(int x, int y, int w, int h)
    : Shape(x, y), width(w), height(h)
{
}

// destructor
Rect::~Rect()
{
}

// returns a copy of this class
Rect* Rect::copy()
{
    return new Rect(*this);
}

// width accessor
int Rect::getWidth() const
{
    return width;
}

// height accessor
int Rect::getHeight() const
{
    return height;
}

// width setter
void Rect::setWidth(int w)
{
    width = w;
}

// Height setter
void Rect::setHeight(int h)
{
    height = h;
}

// prints the details of the rectangle class
string Rect::printShape() const 
{
    return "It's a Rectangle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
           " with width: " + to_string(width) + " and height: " + to_string(height);
}

// RightTriangle class agian a child class
RightTriangle::RightTriangle()
    : base(0), height(0)
{
}

// All of the functionality follows the trend above with accessor, mutataors, destructor and printing the details.

RightTriangle::RightTriangle(int b, int h)
    : base(b), height(h)
{
}

RightTriangle::RightTriangle(int x, int y, int b, int h)
    : Shape(x, y), base(b), height(h)
{
}

RightTriangle::~RightTriangle()
{
}

RightTriangle* RightTriangle::copy()
{
    return new RightTriangle(*this);
}

int RightTriangle::getBase() const
{
    return base;
}

int RightTriangle::getHeight() const
{
    return height;
}

void RightTriangle::setBase(int b)
{
    base = b;
}

void RightTriangle::setHeight(int h)
{
    height = h;
}

string RightTriangle::printShape() const
{
    return "It's a Right Triangle at x: " + to_string(getX()) + ", y: " + to_string(getY()) +
           " with base: " + to_string(base) + " and height: " + to_string(height);
}
