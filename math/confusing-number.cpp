class Solution {
public:
    bool confusingNumber(int N) {
        int rev = 0, origin = N;
        while(N != 0) {
            int lastDigit = N % 10;
            if(lastDigit == 0 || lastDigit == 8 || lastDigit == 1) lastDigit = lastDigit;
            else if(lastDigit == 6) lastDigit = 9;
            else if(lastDigit == 9) lastDigit = 6;
            else return false;

            rev = rev * 10 + lastDigit;
            N /= 10;
        }
        return origin != rev;
    }
};
