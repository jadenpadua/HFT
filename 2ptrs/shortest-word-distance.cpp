class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int p1 {-1}, p2 {-1}, shortestDist = wordsDict.size();
        for(int i = 0; i < wordsDict.size(); ++i) {
            if(wordsDict[i] == word1) {
                if(p2 != -1) shortestDist = min(shortestDist, i - p2);
                p1 = i;
            } 
            else if(wordsDict[i] == word2){
                if(p1 != -1) shortestDist = min(shortestDist, i - p1);
                p2 = i;
            }
        } 
        return shortestDist;
    } 
};
