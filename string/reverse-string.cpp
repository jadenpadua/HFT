class Solution {
public:
    void reverseString(vector<char>& s) {
        int left {}, right = s.size() - 1;
        while(left < right) swap(s[left++],s[right--]);
    }
};
