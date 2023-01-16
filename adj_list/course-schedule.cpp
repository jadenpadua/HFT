class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        set<int> currPath {};

        for(int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        function<bool(int)> dfs = [&](int curr) {
            if(currPath.find(curr) != currPath.end()) return false;
            if(adj[curr].size() == 0) return true;
            
            currPath.insert(curr);
            for(auto pre: adj[curr]) {
                if(!dfs(pre)) return false;
            }
            currPath.erase(curr);
            adj[curr] = {};

            return true;
        };

        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(i)) return false;
        }
        return true;
    }   
};
