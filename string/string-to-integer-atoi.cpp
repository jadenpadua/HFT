class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;

        int i = str.find_first_not_of(' ');
        if(i == -1) return 0;

        if(str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ? 1 : -1;

        while(i < str.length() && isdigit(str[i])) {
            int d = str[i++] - '0';
            res = res * 10 + d;
            if(res * sign > INT_MAX) return INT_MAX;
            if(res * sign < INT_MIN) return INT_MIN;
        }
        return res * sign;
    }
};
