// Name: Zaheer Safi
// Date: 09/04/2023
// CS_251 Project_1 : Linked List where the Nodes hold information of shapes as Nodes.

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("Shape class test") 
{
    
    SECTION("Constructor and accessor functions") 
    {
        Shape shape(3, 4);
        
        REQUIRE(shape.getX() == 3);
        REQUIRE(shape.getY() == 4);
    }

    SECTION("Copy function") 
    {
        Shape shape(3, 4);
        Shape* copy = shape.copy();

        REQUIRE(copy->getX() == shape.getX());
        REQUIRE(copy->getY() == shape.getY());

        delete copy;
    }

    SECTION("Setter and getter functions") 
    {
        Shape shape(3, 4);
        
        shape.setX(5);
        shape.setY(6);

        REQUIRE(shape.getX() == 5);
        REQUIRE(shape.getY() == 6);
    }

    SECTION("Print function") 
    {
        Shape shape(3, 4);
        
        REQUIRE(shape.printShape() == "It's a Shape at x: 3, y: 4");
        
        shape.setX(5);
        shape.setY(6);
        
        REQUIRE(shape.printShape() == "It's a Shape at x: 5, y: 6");

    }
}

TEST_CASE("Circle class") 
{
    Circle circle;

    SECTION("Default constructor") 
    {
        REQUIRE(circle.getX() == 0);
        REQUIRE(circle.getY() == 0);
        REQUIRE(circle.getRadius() == 0);
    }

    SECTION("Parameterized constructor") 
    {
        Circle circle(1, 2, 3);
        REQUIRE(circle.getX() == 1);
        REQUIRE(circle.getY() == 2);
        REQUIRE(circle.getRadius() == 3);
    }

    SECTION("Setter and Getter") 
    {
        circle.setX(4);
        circle.setY(5);
        circle.setRadius(6);
        REQUIRE(circle.getX() == 4);
        REQUIRE(circle.getY() == 5);
        REQUIRE(circle.getRadius() == 6);
    }

    SECTION("printShape") 
    {
        REQUIRE(circle.printShape() == "It's a Circle at x: 0, y: 0, radius: 0");
    }
}

TEST_CASE("Rect class") 
{
    Rect rect;

    SECTION("Default constructor") 
    {
        REQUIRE(rect.getX() == 0);
        REQUIRE(rect.getY() == 0);
        REQUIRE(rect.getWidth() == 0);
        REQUIRE(rect.getHeight() == 0);
    }

    SECTION("Parameterized constructor") 
    {
        Rect rect(1, 2, 3, 4);
        REQUIRE(rect.getX() == 1);
        REQUIRE(rect.getY() == 2);
        REQUIRE(rect.getWidth() == 3);
        REQUIRE(rect.getHeight() == 4);
    }

    SECTION("Setter and Getter") 
    {
        rect.setX(5);
        rect.setY(6);
        rect.setWidth(7);
        rect.setHeight(8);
        REQUIRE(rect.getX() == 5);
        REQUIRE(rect.getY() == 6);
        REQUIRE(rect.getWidth() == 7);
        REQUIRE(rect.getHeight() == 8);
    }

    SECTION("printShape Rectangle") 
    {
        REQUIRE(rect.printShape() == "It's a Rectangle at x: 0, y: 0 with width: 0 and height: 0");
    }
}

TEST_CASE("RightTriangle class") 
{
    RightTriangle triangle;

    SECTION("Default constructor") 
    {
        REQUIRE(triangle.getX() == 0);
        REQUIRE(triangle.getY() == 0);
        REQUIRE(triangle.getBase() == 0);
        REQUIRE(triangle.getHeight() == 0);
    }

    SECTION("Parameterized constructor") 
    {
        RightTriangle triangle(1, 2, 3, 4);
        
        REQUIRE(triangle.getX() == 1);
        REQUIRE(triangle.getY() == 2);
        REQUIRE(triangle.getBase() == 3);
        REQUIRE(triangle.getHeight() == 4);
    }

    SECTION("Setter and Getter") 
    {
        triangle.setX(5);
        triangle.setY(6);
        triangle.setBase(7);
        triangle.setHeight(8);
        
        REQUIRE(triangle.getX() == 5);
        REQUIRE(triangle.getY() == 6);
        REQUIRE(triangle.getBase() == 7);
        REQUIRE(triangle.getHeight() == 8);
    }

    SECTION("printShape Right Triangle") 
    {
        REQUIRE(triangle.printShape() == "It's a Right Triangle at x: 0, y: 0 with base: 0 and height: 0");
    }
}


TEST_CASE("Testing the canavasList class")
{
    
    SECTION("the cunstructor with no parameters")
    {
        CanvasList myCanvas;
        
        REQUIRE(myCanvas.size() == 0);
    }

    SECTION("Constructor with parameters")
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        
        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);
        
        CanvasList myCanvas(new_Canvas);
        
        REQUIRE(myCanvas.size() == 3);
            
    }
    
    SECTION("Copy assignment operator")
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        
        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);

        CanvasList canvasListCopy1(new_Canvas);
        CanvasList canvasListCopy2 = new_Canvas;

        REQUIRE(canvasListCopy1.size() == 3);
        REQUIRE(canvasListCopy2.size() == 3);
        
    }

    SECTION("Clear") 
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        
        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);

        REQUIRE(new_Canvas.size() == 3);

        ShapeNode* test_shape = new_Canvas.front();

        REQUIRE(test_shape->value->getX() == 10);
        REQUIRE(test_shape->value->getY() == 20);

        new_Canvas.clear();
        
        REQUIRE(new_Canvas.size() == 0);
        REQUIRE(new_Canvas.isempty() == true);
    }

    SECTION("pop front Function") 
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        
        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);
    
        delete new_Canvas.pop_front();

        REQUIRE(new_Canvas.front()->value->getX() == 0);
        REQUIRE(new_Canvas.front()->value->getY() == 9);
        REQUIRE(new_Canvas.size() == 2);    
    }

    SECTION("Pop_back Function, clear and  pop_front")
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        new_Canvas.push_back(new_shape);

        delete new_Canvas.pop_front();
        
        REQUIRE(new_Canvas.front() == nullptr);
        new_Canvas.clear();
    
    }

    SECTION("insertAt, removeAt and shapeAt function")
    {
        CanvasList new_Canvas;
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        Shape* new_shape3 = new Shape(5, 7);
        
        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);
        new_Canvas.push_back(new_shape3);

        new_Canvas.removeAt(1);


        REQUIRE(new_Canvas.shapeAt(1)->getX() == 1);
        REQUIRE(new_Canvas.shapeAt(1)->getY() == 2);
        REQUIRE(new_Canvas.size() == 3);

        Shape* insert_shape = new Shape(7, 11);

        new_Canvas.insertAfter(1, insert_shape);
        
        REQUIRE(new_Canvas.shapeAt(2)->getX() == 7);
        REQUIRE(new_Canvas.shapeAt(2)->getY() == 11);
        REQUIRE(new_Canvas.size() == 4);
            
    }
    
    SECTION("push_front")
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        new_Canvas.push_front(new_shape);
        
        REQUIRE(new_Canvas.shapeAt(0)->getX() == 10);
        REQUIRE(new_Canvas.shapeAt(0)->getY() == 20);
        REQUIRE(new_Canvas.size() == 1);
    }

    SECTION("RemoveEveryOther function")
    {
        CanvasList new_Canvas;
        
        Shape* new_shape = new Shape(10, 20);
        Shape* new_shape1 = new Shape(0, 9);
        Shape* new_shape2 = new Shape(1, 2);
        Shape* new_shape3 = new Shape(5, 7);
        Shape* new_shape4 = new Shape(-4, 0);
        Shape* new_shape5 = new Shape(18, 2);

        new_Canvas.push_back(new_shape);
        new_Canvas.push_back(new_shape1);
        new_Canvas.push_back(new_shape2);
        new_Canvas.push_back(new_shape3);
        new_Canvas.push_back(new_shape4);
        new_Canvas.push_back(new_shape5);

        new_Canvas.removeEveryOther();
    
        REQUIRE(new_Canvas.shapeAt(0)->getX() == 10);
        REQUIRE(new_Canvas.shapeAt(0)->getY() == 20);
        REQUIRE(new_Canvas.shapeAt(1)->getX() == 1);
        REQUIRE(new_Canvas.shapeAt(1)->getY() == 2);
        REQUIRE(new_Canvas.shapeAt(2)->getX() == -4);
        REQUIRE(new_Canvas.shapeAt(2)->getY() == 0);
        REQUIRE(new_Canvas.size() == 3);
    }


}


