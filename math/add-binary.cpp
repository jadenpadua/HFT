class Solution {
public:
    string addBinary(string a, string b) {
        int p1 = a.size() - 1, p2 = b.size() - 1, carry {};
        string res;

        while(p1 >= 0 || p2 >= 0 || carry == 1) {
            if(p1 >= 0) carry += a[p1--] - '0';
            if(p2 >= 0) carry += b[p2--] - '0';

            res += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
