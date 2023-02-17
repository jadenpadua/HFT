#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());
  int currChange {};

  for(const int c: coins) {
    if(c > currChange + 1) {
      return currChange + 1;
    }
    currChange += c;
  }
  return currChange + 1;
}
