class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

void findClosest(BST *node, int target, int& minDiff, int& res) {
  if(!node) return;
  int currDiff = abs(node->value - target);
  
  if(currDiff < minDiff) {
    minDiff = currDiff;
    res = node->value;
  }

  if(node->right && target > node->value) {
    findClosest(node->right, target ,minDiff, res);
  }
  else if(node->left && target < node->value) {
    findClosest(node->left, target, minDiff, res);
  }
}

int findClosestValueInBst(BST *tree, int target) {
  int minDiff = INT_MAX;
  int res {};
  findClosest(tree, target, minDiff, res);
  return res;
}
