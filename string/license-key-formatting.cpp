#define all(x) begin(x), end(x)
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        s.erase(remove(all(s), '-'), end(s));

        for (int i = s.size() - 1; i >= 0; i -= 1) {
            s[i] = toupper(s[i]);
            
            if (res.size() % (k + 1) == k) {
                res += '-';
            } 
            res += s[i];
        }
        
        reverse(all(res));
        return res;
    }
};
