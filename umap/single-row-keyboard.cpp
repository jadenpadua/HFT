class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map <char,int> umap;
        for(int i = 0; i < keyboard.size(); i++) {
            umap[keyboard[i]] = i;
        }

        int res = umap[word[0]];
        for(int i = 1; i < word.size(); i++) {
            res += abs(umap[word[i - 1]] - umap[word[i]]);
        }
        return res;
    }
};
