class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};
        int n = ransomNote.size(), m = magazine.size();
        for(int i = 0; i < m; ++i) {
            ++freq[magazine[i]- 'a'];
        }
        for(int i = 0; i < n; ++i) {
            if(freq[ransomNote[i]- 'a']-- == 0) return false;
        }
        return true;
    }
};
