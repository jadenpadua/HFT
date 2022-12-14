/**
* @description:
* Step 1: 2 ptrs at start and end of string, if two values match then move pointers one point to the center until they meet
* Step 2: use !isalnum to completely disregard non alphanumeric characters, even spaces
* Step 3: need to tolower() both values of the 2 ptrs, if not equal then pointers are not in sync and return false
* Step 4: return true once pointers cross, which means that each char in the ptr comparisons are the same value, return true
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;
            if(tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
