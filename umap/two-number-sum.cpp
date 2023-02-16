#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  unordered_map<int, int> umap {};
  for(int i = 0; i < array.size(); ++i) {
    int prefixSumToFind = targetSum - array[i];
    if(umap.find(prefixSumToFind) != umap.end()) {
      return {prefixSumToFind, array[i]};
    }
    umap[array[i]] = true;
  }
  return {};
}
