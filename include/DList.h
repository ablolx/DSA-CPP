#ifndef DLIST_H
#define DLIST_H

// Node Structure
struct Node{
	public:
		int data;
		Node* next;
		Node* prev;
};
// Defining Node Pointer Type
typedef Node* Nodeptr;

// List Class Declaration
class DList
{
    public:
        // constructor
        DList();
        // destructor
        virtual ~DList();
        // copy constructor
        DList(const DList& other);

        // boolean function
        bool empty() const;
        // access head element
        int headElement() const;
        // access tail element
        int tailElement() const;
        // access element at specific index
        int getAt(int idx);
        // add to the head
        void addHead(int newdata);
        // delete the head
        void delHead();
        // add to the head
        void addTail(int newdata);
        // delete the head
        void delTail();
        // add to the head
        void addAt(int idx, int newdata);
        // delete the head
        void delAt(int idx);
        // Clear the list
        void Clear();

        // utility function to get length of list
        int length() const;
        // display the list
        void print() const;

    private:
        void createDummyHead();
        //Go to specific index and return poiter to node at that position
        Nodeptr goToIndex(int idx);
        //head pointer, pointing to dummy noce actually
        Nodeptr head;
};

#endif // DLIST_H

