/**
* @description: 
* Step 1: We know that if the mid element is greater than the right element in bsearch, the pivot exists there, so cut down the already sorted half
* Step 2: if its not greater, then pivot exists in left half, so we cut down the right half
* Step 3: Repeat the process until left and right meet, then your left pointer will always be on the min element when we cut down to one element
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[left];
    }
};
