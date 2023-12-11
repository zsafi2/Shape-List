// Name: Zaheer Safi
// Date: 09/04/2023
// CS_251 Project_1 : Linked List where the Nodes hold information of shapes as Nodes.

#pragma once
#include <string>

using namespace std;

// Shape a base or parent class that hold the cartesion cordinates for the shape x and y
class Shape
{
    protected:
        int x;
        int y;

    // functions to access, mutate and print the shape
    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual string printShape() const;
};

// child class that adds a radius with addition of x and y cordinates
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
        
        virtual string printShape() const;
};

// again a child class that adds the width and height aspect because it is a rectangle 
class Rect : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rect();
        Rect(int w, int h);
        Rect(int x, int y, int w, int h);
        
        virtual ~Rect();
        virtual Rect* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual string printShape() const;
};

// Another chid class that has the base and hight private memebers added to it.
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

        virtual string printShape() const;
};


// DO NOT REMOVE - USED BY AUTOGRADER
#include "moreshapes.h"
