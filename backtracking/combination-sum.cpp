class Solution {
private:
    void dfs(vector<int>& candidates, int i, vector<int>& curr, int target, vector<vector<int>>& res, int total) {
        if(total == target) {
            res.push_back(curr);
            return;
        }
        if(i >= candidates.size() || total > target) return;

        curr.push_back(candidates[i]);
        dfs(candidates, i, curr, target, res, total + candidates[i]);
        curr.pop_back();
        dfs(candidates, i+1, curr, target, res, total);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res {};
        vector<int> curr {};

        sort(candidates.begin(), candidates.end());

        dfs(candidates, 0, curr, target, res, 0);
        return res;
    }
};
