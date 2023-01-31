class UnionFind {
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if (x == f[x]) return x;
        else return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if (rank[fx] == rank[fy]) rank[fy]++;
    }
    
private:
    vector<int> f, rank;
};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int n = source.size();
        UnionFind uf(n);
        for (const auto& v : allowedSwaps) uf.Union(v[0], v[1]);
        
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) components[uf.Find(i)].push_back(i);

        int res = 0;
        for (const auto& it: components) {
            vector<int> indexes = it.second;
            unordered_map<int,int> umap;

            for(int idx: indexes) umap[source[idx]]++;
            for(int idx: indexes) {
                if(umap[target[idx]] > 0) umap[target[idx]]--;
                else res++;
            }
        }
        return res;
    }
};
