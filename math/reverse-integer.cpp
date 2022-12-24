class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x != 0) {
            int last = x % 10;
            rev = rev * 10 + last;
            if(rev > INT_MAX || rev < INT_MIN) return 0;
            x /= 10;
        }
        return rev;
    }
};
