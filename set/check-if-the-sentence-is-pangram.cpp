class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> uniques;
        for(char c: sentence) uniques.insert(c);
        return uniques.size() == 26;
    }
};
