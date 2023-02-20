using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  if(!linkedList || !linkedList->next) return linkedList;
  
  LinkedList* p1 = linkedList;
  LinkedList* p2 = linkedList->next;

  while(p2 != nullptr) {
    if(p1->value == p2->value) {
      p1->next = p2->next;
      p2 = p1->next;
    }
    else {
      p1 = p1->next; p2 = p2->next;
    }
  }
  return linkedList;
}
