#include <any>
#include <vector>

using namespace std;

int productSum(vector<any> array, int depth = 1) {
  int res {};
  for(auto el: array) {
    if(el.type() == typeid(vector<any>)) {
      res += productSum(any_cast<vector<any>>(el), depth + 1);
    }
    else {
      res += any_cast<int>(el);
    }
  }
  return res * depth;
}
