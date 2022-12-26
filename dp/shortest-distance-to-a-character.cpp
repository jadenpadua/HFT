class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), p1 = -1; 
        vector<int> res(n, INT_MAX); 

        for(int i = 0; i < n; ++i) {
            if(s[i] == c) p1 = i;
            res[i] = min(res[i], p1 != -1 ? abs(p1 - i) : INT_MAX);
        }
        for(int i = n-1; i >= 0; --i) {
            if(s[i] == c) p1 = i;
            res[i] = min(res[i], abs(i - p1));
        }
        return res;
    }
};
