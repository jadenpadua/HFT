#include <vector>
using namespace std;

int calcMaxTotalSpeed(const vector<int>& arr1, const vector<int>& arr2) {
  int right = arr1.size() - 1;
  int res {};
  for(int i = 0; i < arr1.size(); ++i) {
    res += max(arr1[i], arr2[right]);
    right--;
  }
  return res;
}

int calcMinTotalSpeed(const vector<int>& arr1, const vector<int>& arr2) {
  int res {};
  for(int i = 0; i < arr1.size(); ++i) {
    res += max(arr1[i], arr2[i]);
  }
  return res;
}

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    
  if(fastest) {
    return calcMaxTotalSpeed(redShirtSpeeds, blueShirtSpeeds);
  }
  else {
    return calcMinTotalSpeed(redShirtSpeeds, blueShirtSpeeds);
  }
}
