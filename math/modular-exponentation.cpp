class Solution {
public:
    long long mPow(long long a, long long b, int mod) {
        long long res = 1;
        while(b) {
            if (b&1) res = (res*a) % mod;
            a = (a*a) % mod;
            b >>= 1;
        }
        return res;
    }
};
