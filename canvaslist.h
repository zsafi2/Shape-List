// Name: Zaheer Safi
// Date: 09/04/2023
// CS_251 Project_1 : Linked List where the Nodes hold information of shapes as Nodes.

#pragma once

#include "shape.h"

using namespace std;

// ShapeNode class used as nodes in linked list
// implemented akin to a struct as all data is public
class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

// The CanvasList class implements the functionality of a linked list.
// This linked list can contain all types of Shape and its derived classes.
class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList& operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        void removeEveryOther();
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;

};
