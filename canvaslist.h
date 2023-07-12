// *****************************************************************************************************
// Program 4 - CS 251 ; Spring 2023
// 
// Name: Srijita Banerjee
// netid: sbane4@uic.edu
// UIN: 675443340
// 
// - CanvasList class - 
// Implementation of CanvasList.h class to create a linked list of Shapes (separate implementation) 
// and performing various operations. 
//
// *****************************************************************************************************

#pragma once
#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront; // head of the linked list 

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
        ShapeNode* get_tail_node (); // added this member function to access the last node of the linked list
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const; // return listfront
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const; // returns null if out of bounds
        
        void draw() const;
        void printAddresses() const;
};

// Defining default constructor for class CanvasList
CanvasList::CanvasList () {
    listSize = 0;
    listFront = NULL;
} 



// Defining copy constructor for class CanvasList
CanvasList::CanvasList (const CanvasList &listNode) {
    listSize = listNode.listSize;
    listFront = listNode.listFront;
}

// Defining operator= overloading for class CanvasList
CanvasList& CanvasList::operator=(const CanvasList &listNode) {
    clear ();
    return *this;
    

}

// Defining destructor for class CanvasList
CanvasList::~CanvasList () {
    /* ShapeNode *current = listFront;

    while (current!=NULL) {
        ShapeNode* next = current->next;
        delete current->value; // deleting "value" member of ShapeNode's object
        delete current; // deleting each object of ShapeNode.
        current = next;
    }
    */ 
   clear ();
}

// Defining clear function
void CanvasList::clear () {
    listSize = 0; // setting size of list to 0

    ShapeNode* current = listFront; // keeps track of the current node in the list
    
    while (current != NULL) {
        delete current->value; // deleting the shape
        current->value = NULL; // set the node (or, shape) to null
        current = current->next; // going to consecutive nodes

    }
}

// Implementing insertAfter function
void CanvasList::insertAfter (int ind, Shape* node) {
    if (ind >= listSize || ind < 0) { // nothing is done when index given is out of range
        return;
    } else {
        
        ShapeNode* current = listFront;
        ShapeNode* next_node = new ShapeNode ();
        ShapeNode* new_node = new ShapeNode ();
        
        int ctr = 0; // counter to keep track of the correct index

        while (current != NULL) {
            if (ind != ctr) {
                current = current->next;
                ctr++;
            } else {
                next_node = current->next; 
                break;
            }
        }
        new_node = current->next;
        new_node->value = node;
        new_node->next = next_node;
    }
}

// Implementing push_front function
void CanvasList::push_front (Shape *node) {
    // allocating new node
    ShapeNode* new_node = new ShapeNode ();
    // assigning value in linked list in the first node
    new_node->value = node;
    // make next node of new node as head
    new_node->next = listFront;
    // make new node as head
    listFront = new_node;
    listSize++; // updating size of linked list
    return;
}

// Implementing push_back function
void CanvasList::push_back (Shape *node) {
    /* ShapeNode* new_node = new ShapeNode ();
    ShapeNode* temp = listFront;

    // traversing to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // changing the next of last node to temp
    temp->next = new_node;
    new_node->value = node;
    new_node->next = NULL; // since tail always points to NULL
    */

   if (listSize == 0) {
    ShapeNode* new_node1 = new ShapeNode ();
    new_node1->value = node;
    new_node1->next = NULL;
    listFront = new_node1;
    listSize++;
    } else {
        ShapeNode* tail = get_tail_node ();
        ShapeNode* new_node = new ShapeNode ();

        tail->next = new_node;
        new_node->value = node;
        new_node->next = NULL;
        listSize++; // updating size of the linked list
    }
}

void CanvasList::removeAt (int ind) {
    if (listFront->next == NULL) { // list will be empty after removing its head
        listSize = 0;
        listFront = NULL;
        return;
    } 
    ShapeNode* current = listFront;
    ShapeNode* new_node = new ShapeNode ();
    int ctr = 0;

    while (current != NULL) {
        if (ctr == ind) {
            new_node = current->next->next; 
            break;
        }
        ctr++;
        current = current->next;
    }

    listSize--; // updating listSize after removing a node

}

Shape* CanvasList::pop_front () {
    if (listFront == NULL) { // if there is no shape in the head node of the linked list
        return NULL;
    } 
    
    ShapeNode* ptr = listFront; // backup for the head of the linked list

   listFront = listFront->next;
   listSize--; // updating listSize after removing a node
   return ptr->value;
}

// Helper function to get the tail node of the linked list 
ShapeNode* CanvasList::get_tail_node () {
    if (listFront == NULL) { // if list is empty, return NULL
        return NULL;
    }

    ShapeNode* current = listFront;

    while (current->next != NULL) {
        current = current->next;
    }

    // the current node is the tail node
    return current;
}

// Implementing pop_back function
// come back to it
Shape* CanvasList::pop_back () {
    ShapeNode* tail = get_tail_node (); // getting tail node

    if (tail == NULL) {
        // if current node has no shape, return NULL
        return NULL;
    }

    /* ShapeNode* next_node = tail->next;

    if (next_node == NULL) {
        Shape* in_node = tail->value;
        tail->value = NULL; // release ownership of the shape from this node
        // delete this; // deallocate memory used by tail node

    }
    */ 

    ShapeNode* second_last = NULL; // stores the second last node of the linked list

    ShapeNode* current = listFront;

    if (current->next == NULL) {
        listFront = NULL;
        listSize = 0;
        return current->value;
    } 

    while (current != tail) {
        second_last = current;
        current = current->next;
    }

    
    second_last->next = NULL; // if second last node points to NULL, original tail is no longer part of the linked list
    listSize--; // updating listSize after removing a node

    return tail->value;
}

// Implementing front () function
ShapeNode* CanvasList::front () const {
    return listFront;
}

// Implementing isempty function
bool CanvasList::isempty () const {
    // if the head of the linked list is NULL, list is empty
    if (listFront == NULL) {
        return true;
    }
    return false;
}

// Implementing size function
int CanvasList::size () const {
    return listSize;
}

// Implementing find function
int CanvasList::find (int x, int y) const {
    int ind = -1; // to keep track of the index where the correct node is
    ShapeNode* current = listFront; // keeps track of the current node

    int curr_x = 0, curr_y = 0; // keeps track of the x and y values of the current node

    while (current != NULL) {
        // retrieving the current x and y values
        curr_x = current->value->getX ();
        curr_y = current->value->getY ();
        
        // If x and y values are found, return the current position, else continue traversing the list
        if (curr_x == x && curr_y == y) {
            return ind;
        }
        current = current->next;
        ind++; // keeping track of the current index
    }
    return ind; // -1 is returned if the node (or, shape) is not found
}

// Implementing shapeAt function
Shape* CanvasList::shapeAt (int pos) const {
    // return NULL for invalid index
    if (pos >= listSize || pos < 0) {
        return NULL;
    }
    ShapeNode* current = listFront; // for traversing through the linked list
    int ind = 0; // keeps track of the current index

    while (current != NULL) {
        if (pos == ind) {
            return current->value; // returning node in the particular position
        }
        current = current->next;
        ind++;
    }
    cout << "I did not expect to be here" << endl;
    return NULL;
}

// Implementing draw function
void CanvasList::draw () const {
    ShapeNode *current = listFront; // keeps track of the current shape in the linked list

    while (current != NULL) {
        current->value->printShape (); // printing the shapes 
        current = current->next;
    }
    return;
}

// Implementing printAddresses function
void CanvasList::printAddresses () const {
    ShapeNode* current = listFront; // keeps track of the current shape in the linked list

    while (current != NULL) {
        cout << "Node Address: " << &current << "\tShape Address: " << &current->value << endl;
        current = current->next;
    }
    return;
}

