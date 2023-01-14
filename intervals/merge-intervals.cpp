class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res {intervals[0]};

        for(int i = 1; i < n; ++i) {
            int m = res.size();
            if(intervals[i][0] <= res[m-1][1]) {
                res[m-1][0] = min(res[m-1][0], intervals[i][0]);
                res[m-1][1] = max(res[m-1][1], intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        } 
        return res;
    }
};
