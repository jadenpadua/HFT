class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;
        for(int i = 0; i < s.size(); ++i) {
            // Odd length case
            int left = i, right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currLen = right - left + 1;
                if(currLen > resLen) {
                    res = s.substr(left, currLen);
                    resLen = currLen;
                }
                left--;
                right++;
            }
            // Even length case
            left = i, right = i+1;
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                int currLen = right - left + 1;
                if(currLen > resLen) {
                    res = s.substr(left, currLen);
                    resLen = currLen;
                }
                left--;
                right++;
            }
        }
        return res;
    }
};
