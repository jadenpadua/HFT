class Solution {
public:        
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int,int>> v;
        int n = mat.size();

        for(int i = 0; i < n; ++i) {
            auto soldiers = accumulate(begin(mat[i]), end(mat[i]),0);
            v.push_back(make_pair(soldiers, i));
        }
        sort(v.begin(), v.end());

        for(int i = 0; i < k; ++i) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
