#include "node.h"
#include "iostream"

using namespace std;

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  void printListR();
  ~LL();
/* With doubly linked list*/
/*
 void printListR();
*/
};

LL::LL() {
  this->hol = nullptr;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t = hol;
  int i;
  while(t != nullptr){
    NodePtr temp = t;
    t = t->get_next();
    delete temp;
  }
}

// insert a new value into the list in sorted order
void LL::insert(int value) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value); // create node & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
                                          
    } // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
        newPtr->set_next(hol);
        newPtr->set_prev(previousPtr);
        hol = newPtr;
       
      }  // end if
    else { 
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      
      newPtr->set_next(currentPtr);
      newPtr->set_prev(previousPtr);
      
      if(currentPtr){
        currentPtr->set_prev(newPtr);
      }
    } // end else
    ++size;
  }
  else {
    cout << value << " not inserted. No memory available." << endl;
  }
}


int LL::deletes(int value) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  if(isEmpty()){
    return '\0';
  }
  NodePtr t = hol;
  while (t != nullptr && t->get_data() != value) {
    t = t->get_next();
  }

  if (t == nullptr) {
    cout << value << " not found." << endl;
    return '\0';
  }

  if (t->get_prev() != nullptr) {
    t->get_prev()->set_next(t->get_next());
  } else {
    hol = t->get_next();
  }

  if (t->get_next() != nullptr) {
    t->get_next()->set_prev(t->get_prev());
  }

  int deletedValue = t->get_data();
  delete t;
  size--;

  return deletedValue;
} // end function delete

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty

void LL::printListR(){
  NodePtr currentPtr = hol;
  
  if (size == 0) {
    cout << "List is empty." << endl;
  }
  else {
    while(currentPtr != NULL){
      currentPtr = currentPtr->get_next();
    }
    cout << "The reversed list is:" << endl;
    for(int i = 0; i < size; i++){
      currentPtr->print();
      cout << " ->";
      currentPtr = currentPtr->get_prev();
    }
  }
    
}
// print the list
void LL::printList() {
  NodePtr currentPtr = hol;
  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;

    // while not the end of the list
    // while ( currentPtr != NULL ) {
    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_next();
    } // end while

    puts("NULL\n");
  } // end else
} // end function printList
