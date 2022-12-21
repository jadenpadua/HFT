class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> umap = {
            {'0','0'},
            {'1','1'},
            {'6','9'},
            {'9','6'},
            {'8','8'}
        };
        
        int left = 0;
        int right = num.size() - 1;
        while(left <= right) {
            if(umap.count(num[left]) == 0 || umap[num[left]] != num[right]) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};
