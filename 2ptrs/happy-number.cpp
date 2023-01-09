class Solution {
private: 
    int squareSum(int n) {
        int res {};
        while(n > 0) {
            int d = n % 10;
            res += d*d;
            n = n / 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        int slow = squareSum(n), fast = squareSum(squareSum(n));

        while(slow != fast && fast != 1) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        return fast == 1;
    }
};
