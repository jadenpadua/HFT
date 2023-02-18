using namespace std;

// This is the class of the input root. Do not edit it.
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

void dfs(BinaryTree *node, vector<int>& res, int runningSum) {
  if(!node) return;
  
  runningSum += node->value;
  // leaf 
  if(!node->left && !node->right) {
    res.push_back(runningSum);
    return;
  }
  dfs(node->left, res, runningSum);
  dfs(node->right, res, runningSum);
}

vector<int> branchSums(BinaryTree *root) {
  vector<int> res {};
  dfs(root, res, 0);
  return res;
}
