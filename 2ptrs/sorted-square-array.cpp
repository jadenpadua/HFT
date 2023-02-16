#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  int n = array.size();
  vector<int> res(n, 0);
  int p1 = 0, p2 = n - 1;
  
  for(int i = n - 1; i >= 0; --i) {
    if(abs(array[p1]) > abs(array[p2])) {
      res[i] = array[p1] * array[p1];
      p1++;
    }
    else {
      res[i] = array[p2] * array[p2];
      p2--;
    }
  }
  return res;
}
