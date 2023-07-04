// self-referential structure
#include <iomanip>
#include <iostream>

using namespace std;

class Node {
private:
  int value;
  Node *prevPtr;
  Node *nextPtr;
  //  Node *pPtr; // for doubly linked list
public:
  Node(int x = 0);
  ~Node();
  int get_data();
  Node* get_prev();
  Node* get_next();
  void set_prev(Node* t);
  void set_next(Node* t);
  void print();
};

typedef Node *NodePtr; // synonym for Node*

Node::Node(int x) {
  value = x;
  nextPtr = NULL;
}

Node::~Node() { cout << value << " deleted" << endl; }

NodePtr Node::get_prev(){
  return prevPtr;  
}

void Node::set_prev(Node* t){
  this->prevPtr = t;
}

NodePtr Node::get_next() { return nextPtr; }

int Node::get_data() { return value; }

void Node::set_next(NodePtr t) {
  this->nextPtr = t; 
}

void Node::print(){
  cout << setw(3) << value;
}
