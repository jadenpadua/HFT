#include <vector>
using namespace std;
//recursive
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
    array->push_back(this->name);
    for(int i = 0; i < this->children.size(); ++i) {
      children[i]->depthFirstSearch(array);
    }
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

#include <vector>
#include <stack>
using namespace std;
// iterative 
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
    vector<string> res {};
    stack<Node*> s;
    s.push(this);
    while(!s.empty()) {
      Node* popped = s.top(); s.pop();
      res.push_back(popped->name);

      int n = popped->children.size();
      for(int i = n-1; i >= 0; --i) {
        s.push(popped->children[i]);
      }
    }
    return res;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
