// Name: Zaheer Safi
// Date: 09/04/2023
// CS_251 Project_1 : Linked List where the Nodes hold information of shapes as Nodes.

#include "canvaslist.h"
#include <iostream>
using namespace std;

// default constructor for CanvasList class
CanvasList::CanvasList()
{
    listFront = nullptr;
    listSize = 0;
}

// Constructor with a parameter of another CanvasLsit class
CanvasList::CanvasList(const CanvasList &other)
{
    listFront = nullptr;
    
    ShapeNode* current = other.listFront; // hold the values of listfront of other class in the current veriable
    
    // go through each node untill you get to the null which indicates the end 
    while (current != nullptr)
    {
        push_back(current->value->copy()); // take a copy of the value and add that to our class
        current = current->next; // increment the pointer to point to the next node
    }
    listSize = other.size(); // update the size
    
}

// copy assingment operator that takes another CanvasList class
CanvasList& CanvasList::operator=(const CanvasList &other)
{
    clear(); // clear our class delete every node 
    
    // copy all the elemnts from other class in the same fashion as above
    ShapeNode *current = other.listFront;
    while (current != nullptr)
    {
        push_back(current->value->copy());
        current = current->next;
    }
    // return our class
    return *this;
}
        
// destructor that calls the clear function 
CanvasList::~CanvasList()
{
    clear();
}

// clear function that delete all the allocated data for the class or the linked list
void CanvasList::clear()
{
    // go through each node
    while (listFront != nullptr)
    {
        // delete every shape which in this case is value and then delete the pointer
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp->value;
        delete temp;
    }
    listSize = 0; // reset the size
}
         
// insert a node after a given position parameters are given position by the user and the shape or value that they want to add as a node
void CanvasList::insertAfter(int position, Shape* myShape)
{
    // handle if the position is out of range or less then zero show the message and return
    if (position < 0 || position > listSize)
    {
        std::cout << "Invalid position for insertion" << std::endl;
        return;
    }
    
    // allocate memeory for a new node
    ShapeNode* newNode = new ShapeNode();
    newNode->value = myShape; // for the value of the node make it equal to myShape from the user
    
    // if you want to insert after the first position
    if (position == 0)
    {
        // if listSize is zero means it has no node then return 
        if (listFront == nullptr)
        {
            std::cout << "Invalid position for insertion" << std::endl;
            return;
        }
        // otherwise point the newNode to the node in the index 1
        newNode->next = listFront->next;
        listFront->next = newNode; // point the head of the lsit to the newNdoe
    }
    
    else
    {
        // set an iterator to go through each node
        ShapeNode* current = listFront;
        
        // skip the nodes untill you get to the given position
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        newNode->next = current->next; // point the newNode to the the next node after the position 
        current->next = newNode; // and point the current to the newNode
    }
    listSize++; // increment the listSize
}

// function to add element to front of the linked list which takes a shape as a parameter
void CanvasList::push_front(Shape* myShape)
{
    // Create a new node with the given shape
    ShapeNode* newNode = new ShapeNode();
    newNode->value = myShape;
    
    // If the list is empty, make the new node the front of the list
    if (listFront == nullptr)
    {
        listFront = newNode;
        newNode->next = nullptr;
        listSize++;
        return;
    }
    
    // Make the new node the new front of the list
    newNode->next = listFront;
    listFront = newNode;
    listSize++;
}

// function to add element to back of the linked list which takes a shape as a parameter
void CanvasList::push_back(Shape* myShape)
{
    // Create a new node with the given shape
    ShapeNode* new_Node = new ShapeNode;
    new_Node->value = myShape;
    new_Node->next = nullptr;

    // If the list is empty, make the new node the front of the list
    if (listFront == nullptr)
    {
        listFront = new_Node;
    }
    else
    {   
        // Traverse the list to find the last node and make it point to the new node
        ShapeNode* current = listFront;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_Node;
    }
    listSize++;
}

// function to remove a element or value at a given position
void CanvasList::removeAt(int position)
{
    // Check if the position is valid
    if (position < 0 || position > listSize - 1)
    {
        cout << "Position cannot be accessed" << endl;
        return;
    }

    // Remove the element at the specified position
    if (position == 0)
    {
        ShapeNode *temp = listFront;
        listFront = listFront->next;
        delete temp->value;
        delete temp;
    }
    else
    {
        ShapeNode *current = listFront;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        ShapeNode *temp = current->next;
        current->next = temp->next;
        delete temp->value;
        delete temp;
    }
    listSize--;
}

// function to remove every other element which starts from 1 then 3 then 5 and so on
void CanvasList::removeEveryOther()
{
    // Check if the list is empty or contains only one element
    if (listFront == nullptr || listSize == 1)
    {
        cout << "List is empty or only has one element" << endl;
        return;
    }

    // Traverse the list and remove every other element
    ShapeNode* current = listFront;
    ShapeNode* previous = nullptr;
    int position = 0;
    
    while (current != nullptr)
    {
        if (position % 2 == 1)
        {
            // Remove the element at odd positions
            if (previous)
            {
                previous->next = current->next;
                delete current->value;
                delete current;
                current = previous->next;
                listSize -= 1;
            }
            else
            {
                ShapeNode* temp = listFront;
                listFront = listFront->next;
                delete temp->value;
                delete temp;
                current = listFront;
                listSize -= 1;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
        position++;
    }
}

// remove an element from the front of the linked list
Shape* CanvasList::pop_front()
{
    // Check if the list is empty
    if (listSize == 0)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    
    // Remove the front element and return its shape
    ShapeNode *temp = listFront;
    Shape *value = temp->value;
    listFront = listFront->next;
    delete temp;
    listSize--;
    return value;
}

// remove an element fromt back of an element opposite of push_back
Shape* CanvasList::pop_back()
{
    // Check if the list is empty
    if (listSize == 0)
    {
        std::cout << "List is empty" << std::endl;
        return nullptr;
    }
    if (listSize == 1)
    {
        // Remove the only element in the list and return its shape
        Shape *value = listFront->value;
        delete listFront;
        listFront = nullptr;  // Set listFront to nullptr after removing the only node.
        listSize = 0;
        return value;
    }

    // Remove the last element and return its shape
    ShapeNode *current = listFront;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    ShapeNode *temp = current->next;
    Shape *value = temp->value;
    current->next = nullptr;
    delete temp;
    listSize--;
    return value;
}

// functiont that return the front of the list or most commonly returns the head
ShapeNode* CanvasList::front() const
{
    // Return a pointer to the front element of the list
    return listFront;
}

// function to check if a linked list is empty
bool CanvasList::isempty() const
{
    // Check if the list is empty
    return listSize == 0;
}

// function to return the size of the linked list
int CanvasList::size() const
{
    // Return the size of the list
    return listSize;
}

// function ot find the given x and y cordinate shape which are values in the linked list
int CanvasList::find(int x, int y) const
{
    // Check if the list is empty
    if (listFront == nullptr)
    {
        cout << "The list is empty" << endl;
        return -1;
    }

    ShapeNode* current = listFront;
    int size = 0;
    while (current != nullptr)
    {
       if (current->value->getX() == x && current->value->getY() == y)
       {
            // Return the position of the element with the given (x, y) coordinates
            return size;
       }
       current = current->next;
       size++;
    }

    // Return -1 if the element is not found
    return -1;
}

// function to reutnrn a shape at a givne position
Shape* CanvasList::shapeAt(int position) const
{
    // Check if the position is valid
    if (position < 0 || position >= listSize)
    {
        std::cout << "Invalid position" << std::endl;
        return nullptr;
    }

    ShapeNode *current = listFront;
    for (int i = 0; i < position; i++)
    {
        current = current->next;
    }

    // Return the shape at the specified position
    return current->value;
}

// function to draw which means to ouput all the information about the shpaes using the print shape funciton
void CanvasList::draw() const
{
    ShapeNode *current = listFront;
    string to_return;
    while (current != nullptr)
    {
        // Print the information of each shape in the list
        to_return = current->value->printShape();
        cout << to_return << endl;
        current = current->next;
    }
}

// function to print the memeory addresses of nodes and their values
void CanvasList::printAddresses() const
{
    ShapeNode *current = listFront;
    while (current != nullptr)
    {
        // Print the memory addresses of each node and its associated shape
        cout << "Node Address: " << current << "     Shape Address: " << current->value << endl;
        current = current->next;
    }
}

