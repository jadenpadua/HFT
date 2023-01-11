class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int commonIdx = strs[0].size();

        for(int i = 1; i < strs.size(); ++i) {
            int j = 0;
            while(j < strs[i].size() && strs[i][j] == strs[0][j]) ++j;
            commonIdx = min(commonIdx, j);
        }
        return strs[0].substr(0, commonIdx);
    }
};
