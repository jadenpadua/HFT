class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int>& currList, vector<int> candidates, int remainder, int ptr) {
        if(remainder < 0) return;
        else if(remainder == 0) res.push_back(currList);
        else {
            for(int i = ptr; i < candidates.size(); ++i) {
                currList.push_back(candidates[i]);
                backtrack(res, currList, candidates, remainder - candidates[i], i);
                currList.pop_back();
            }
        }
    }
public: 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res {};
        vector<int> currList {};
        sort(candidates.begin(), candidates.end());
        backtrack(res, currList, candidates, target, 0);
        return res;
    }
};
