using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void preOrder(BinaryTree *node, int& res, int depth) {
  if(!node) return;

  res += depth;
  preOrder(node->left, res, depth + 1);
  preOrder(node->right, res, depth + 1);
}

int nodeDepths(BinaryTree *root) {
  int res {};
  preOrder(root, res, 0);
  return res;
}
