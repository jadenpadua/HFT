class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res {};
        int p1 {}, n = intervals.size();

        while(p1 < n && newInterval[0] > intervals[p1][1]) res.push_back(intervals[p1++]);
        
        while(p1 < n && newInterval[1] >= intervals[p1][0]) {
            newInterval[0] = min(intervals[p1][0], newInterval[0]);
            newInterval[1] = max(intervals[p1][1], newInterval[1]);
            ++p1;
        }
        res.push_back(newInterval);

        while(p1 < n) res.push_back(intervals[p1++]);

        return res;
    }
};
