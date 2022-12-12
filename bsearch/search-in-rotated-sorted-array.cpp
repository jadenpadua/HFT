/**
* @description: 
* Step 1: Find min number in sorted array
* Step 2: Find which half to manually cut based on if the target is between the min element and the right element
* Step 3: Once the half is cut, just perform regular binary search because that's where the target is located
*/
class Solution {
public:
    int findMinIdx(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1; 
    }
    int search(vector<int>& nums, int target) {
        int minIdx = findMinIdx(nums);

        int left = 0;
        int right = nums.size() - 1;
        if(nums[minIdx] <= target && target <= nums[right]) {
            left = minIdx;
        }
        else {
            right = minIdx - 1;
        }

        int res = binarySearch(nums, left, right, target);
        return res;
    }
};
