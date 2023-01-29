class Solution {
private:
    long long mPow(long long a, long long b, int mod) {
        long long res = 1;
        while(b) {
            if (b&1) res = (res*a) % mod;
            a = (a*a) % mod;
            b >>= 1;
        }
        return res;
    }
public:
    int monkeyMove(int n) {
        const int mod = 1e9 + 7;
        long long ans = mPow(2,n,mod);
        ans -= 2;
        
        if (ans < 0) ans = ans + mod;
        return ans;
    }
};
