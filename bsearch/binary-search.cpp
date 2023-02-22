#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  int left = 0, right = array.size() - 1;
  while(left <= right) {
    int mid = left + (right - left) / 2;
    if(target == array[mid]) return mid;
    else if(target > array[mid]) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}
