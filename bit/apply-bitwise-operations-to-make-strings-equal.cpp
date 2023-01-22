class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') ++n;
        }
        int m = 0;
        for(int i = 0; i < target.size(); ++i) {
            if(target[i] == '1') ++m;
        }
        
        if(n == 0) return s == target;
        if(m == 0) return false;
        return true;
        
    }
};
