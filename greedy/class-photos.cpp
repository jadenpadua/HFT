#include <vector>
using namespace std;

bool canArrange(const vector<int>& frontArr, const vector<int>& backArr) {
  int n = frontArr.size();
  for(int i = 0; i < n; ++i) {
    if(frontArr[i] >= backArr[i]) return false;
  }
  return true;
}

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  sort(redShirtHeights.begin(), redShirtHeights.end());
  sort(blueShirtHeights.begin(), blueShirtHeights.end());

  return canArrange(redShirtHeights, blueShirtHeights) || canArrange(blueShirtHeights, redShirtHeights);
}
