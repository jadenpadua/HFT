class Solution {
private:
    vector<int> getCounts(const string& W) {
        vector<int> counts(26,0);
        for(char c: W) ++counts[c-'a'];
        return counts;
    }
public:
    bool isItPossible(string word1, string word2) {
        vector<int> c1 = getCounts(word1);
        vector<int> c2 = getCounts(word2);
        
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < 26; ++j) {
                if(!c1[i] || !c2[j]) continue;
                ++c1[j]; --c1[i];
                ++c2[i]; --c2[j];
                
                int cnt1 = 0, cnt2 = 0;
                for(int k = 0; k < 26; ++k) {
                    cnt1 += (c1[k] > 0);
                    cnt2 += (c2[k] > 0);
                }
                if(cnt1 == cnt2) return true;
                
                --c1[j]; ++c1[i];
                --c2[i]; ++c2[j];   
            }
        }
        return false;
    }
};
