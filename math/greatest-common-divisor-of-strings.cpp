class Solution {
public:
    bool isValidGCD(string shorter, string larger, int k) {
        // return false if our current prefix len k does not divide our 2 strings
        if (shorter.size() % k > 0 || larger.size() % k > 0) return false;

        string prefix = shorter.substr(0, k);
        // let m1, m2 be the number of multiples of prefix k within the shorter, larger strings
        int m1 = shorter.size() / k, m2 = larger.size() / k;
        // return true if we can build m1,m2 multiples of prefix k within shorter, larger strings
        return shorter == repeatString(prefix, m1) && larger == repeatString(prefix, m2);
    }
    string repeatString(string str, int k) {
        string res = "";
        for(int i = 0; i < k; ++i) {
            res += str;
        }
        return res;
    }
    string gcdOfStrings(string str1, string str2) {
        string shorter = (str1 < str2) ? str1 : str2;
        string larger = (str1 > str2) ? str1 : str2;
        // decrement down from shorter string's len to try and find valid prefix that is a GCD
        for(int i = shorter.size(); i >= 1; --i) {
            // if gcd is valid we return substr of length r which is our decrementing prefix
            if(isValidGCD(shorter, larger, i)) return shorter.substr(0, i);
        }
        return "";
    }
};
