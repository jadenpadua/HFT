#include <vector>
using namespace std;

void updateResIfNumIsAtLeastThirdLargest(vector<int> &res, int num);
void shiftAndUpdate(vector<int> & res, int num, int idx);

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> res(3, INT_MIN);
  for(int num: array) {
    updateResIfNumIsAtLeastThirdLargest(res, num);
  }
  return res;
}

void updateResIfNumIsAtLeastThirdLargest(vector<int> &res, int num) {
  if(num > res[2]) {
    shiftAndUpdate(res, num, 2);
  }
  else if (num > res[1]) {
    shiftAndUpdate(res, num, 1);
  }
  else if(num > res[0]) {
    shiftAndUpdate(res, num, 0);
  }
}

void shiftAndUpdate(vector<int>& res, int num, int idx) {
  for(int i = 0; i <= idx; i++) {
    if(i == idx) {
      res[i] = num;
    }
    else {
      res[i] = res[i+1];
    }
  }
}
