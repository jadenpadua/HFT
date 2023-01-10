class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 {};
        for(int i = 0; i < t.size(); ++i) {
            if(s[p1] == t[i]) ++p1;
        }
        return p1 == s.size();
    } 
};
