class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sign = 1, ans = 0;
        for (char c: s) {
            int y = c - '0';
            ans += sign * y;
            sign *= -1;
        }
        return ans;
    }
};
