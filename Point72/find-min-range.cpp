#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

std::pair<int,int> findMinRange(std::vector<int> arr, int n, int k){
    std::sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == k) {
            return std::pair<int,int>(arr[mid-1],arr[mid+1]);
        }
        else if(arr[mid] < k) {
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    
    if(right == -1) return pair<int,int>(arr[0], arr[1]);
    else if (left == n) return pair<int,int>(arr[n-2], arr[n-1]);
    
    return std::pair<int,int>(arr[right], arr[left]);
}

int main() {
    std::vector<int> values = {100,250,500,1000};
    int n = values.size();
    int k = 450;
    
    std::pair<int,int> range = findMinRange(values, n, k);
    
    cout << range.first << ":" << range.second << endl;

    return 0;
}
