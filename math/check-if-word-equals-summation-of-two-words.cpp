class Solution {
    int calcNumValue(string word) {
        int numValue {0};
        for(char c: word) {
            int letterValue {int(c) - 'a'};
            numValue = numValue*10 + letterValue;
        }
        return numValue;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return calcNumValue(firstWord) + calcNumValue(secondWord) == calcNumValue(targetWord);
     }
};
