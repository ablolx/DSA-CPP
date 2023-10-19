//Functions Implementation For a Doubly Linked List

#include "DList.h"
#include <iostream>

using namespace std;

//Constructor
DList::DList() {
    createDummyHead();
}

//Destructor
DList::~DList() {
    // Clear The list
    Clear();
    // Delete Dummy Node
    delete head;
}

//Copy Constructor
DList::DList(const DList& other) {
    // Initialize current list
    createDummyHead();
    // Check if other list is empty (if empty do nothing)
    if (other.empty())
        return;
    // Iterate through all the nodes of other list and add all data elements to current list
    Nodeptr other_curr = other.head->next;
    while (other_curr != other.head) {
        addTail(other_curr->data);
        other_curr = other_curr->next;
    }
}

//Boolean Function to check if list is empty
bool DList::empty() const {
    return (head->next == head);
}

//Returns Data at Head Element
int DList::headElement() const {
    if (!empty())
        return head->next->data;
    else {
        cerr << "List is Empty";
        return -1; // or any default value
    }
}

//Returns Data at Tail Element
int DList::tailElement() const {
    if (!empty())
        return head->prev->data;
    else {
        cerr << "List is Empty";
        return -1; // or any default value
    }
}


//Returns Data at Specific Index Which is Provided
int DList::getAt(int idx) {
    Nodeptr pos = goToIndex(idx);
    if (pos != NULL) {
        return pos->data;
    } else {
        cerr << "Invalid Index";
        return -1; // or any default value
    }
}

//Add New Data at Head
void DList::addHead(int newdata) {
    Nodeptr curr = head->next;
    Nodeptr newNode = new Node;
    newNode->data = newdata;
    newNode->next = curr;
    newNode->prev = head;
    curr->prev = newNode;
    head->next = newNode;
}

//Delete Head Element
void DList::delHead() {
    if (empty())
        return;
    Nodeptr curr = head->next;
    head->next = curr->next;
    curr->next->prev = head;
    delete curr;
}

//Add New Data at Tail
void DList::addTail(int newdata) {
    Nodeptr curr = head;
    Nodeptr newNode = new Node;
    newNode->data = newdata;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
}

//Delete Tail Element
void DList::delTail() {
    if (empty())
        return;
    Nodeptr curr = head->prev;
    curr->prev->next = head;
    head->prev = curr->prev;
    delete curr;
}


//Add new data at a specific index
void DList::addAt(int idx, int newdata) {
    Nodeptr curr = goToIndex(idx);
    if (curr == NULL)
        return;
    Nodeptr newNode = new Node;
    newNode->data = newdata;
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
}

//Delete element at a specific index
void DList::delAt(int idx) {
    Nodeptr curr = goToIndex(idx);
    if (curr == NULL)
        return;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

//Returns the Length of list
int DList::length() const {
    int len = 0;
    Nodeptr curr = head->next;
    while (curr != head) {
        len++;
        curr = curr->next;
    }
    return len;
}

//Print the Data in the list
void DList::print() const {
    Nodeptr curr = head->next;
    cout << "[";
    if (!empty()) {
        cout << curr->data;
        curr = curr->next;
    }
    while (curr != head) {
        cout << ", " << curr->data;
        curr = curr->next;
    }
    cout << "]" << endl;
}

//Create a Dummy element to initiate a list
void DList::createDummyHead() {
    head = new Node;
    head->next = head;
    head->prev = head;
}

void DList::Clear() {
    while (!empty())
        delHead();
}

//Returns Address of a specific Index
Nodeptr DList::goToIndex(int idx) {
    if (idx >= length()) {
        cerr << "Error! Given index exceeds the size of the list";
        return NULL;
    }
    Nodeptr curr = head->next;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr;
}

