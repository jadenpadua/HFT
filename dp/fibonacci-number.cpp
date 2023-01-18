class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;

        pair<int,int> lastTwo = {1,0};
        for(int i = 2; i < n; ++i) {
            int temp = lastTwo.first;
            lastTwo.first = lastTwo.first + lastTwo.second;
            lastTwo.second = temp;
        }
        return lastTwo.first + lastTwo.second;
    }
};
