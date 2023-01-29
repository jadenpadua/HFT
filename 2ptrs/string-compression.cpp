class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int i = 0;
        while(i < chars.size()) {
            int j = i;
            while(j < chars.size() && chars[j] == chars[i]) j++;
            chars[idx] = chars[i];
            idx++;
            
            int count = j - i;
            if(count > 1) {
                string s = to_string(count);
                for(int i = 0; i < s.size(); ++i) {
                    chars[idx] = s[i];
                    idx++;
                }
            }
            i = j;
        }
        return idx;
    }
};
