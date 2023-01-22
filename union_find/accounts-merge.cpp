class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int groupCount;

    UnionFind(int n): groupCount(n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
    }
    void init(int x) {
        parent[x] = x;
    }
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unify(int x, int y) {
        int xSet = find(x);
        int ySet = find(y);
        if(xSet == ySet) return;
        groupCount--;
        if(rank[xSet] < rank[ySet]) parent[xSet] = ySet;
        else if(rank[xSet] > rank[ySet]) parent[ySet] = xSet;
        else {
            parent[ySet] = xSet;
            rank[xSet] = rank[ySet] + 1;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string,int> umap {};
        
        for(int i = 0; i < n; ++i) {
            uf.init(i);
            auto& acc = accounts[i];
            for(int j = 1; j < acc.size(); ++j) {
                string& email = acc[j];
                auto iter = umap.find(email);
                if(iter == umap.end()) {
                    umap[email] = i;
                }
                else {
                    uf.unify(i, iter->second);
                }
            }
        }

        int m = uf.groupCount;
        unordered_map<int,int> groupId2Idx;
        vector<vector<string>> res(m);
        int nextIdx = 0;
        for(auto &pair: umap) {
            const string& email = pair.first;
            int groupID = uf.find(pair.second);
            auto iter = groupId2Idx.find(groupID);
            if(iter == groupId2Idx.end()) {
                groupId2Idx[groupID] = nextIdx;
                string &name = accounts[groupID][0];
                res[nextIdx].push_back(name);
                res[nextIdx].push_back(email);
                nextIdx++;
            }
            else {
                res[iter->second].push_back(email);
            }
        }

        for(int i = 0; i < res.size(); ++i) {
            vector<string> &emails = res[i];
            sort(emails.begin() + 1, emails.end());
        }
        return res;


    }
};
