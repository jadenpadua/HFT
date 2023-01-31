class UnionFind {
private:
    vector<int> parents, rank;

public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        parents.resize(n);
        for (int i = 0; i < n; ++i) parents[i] = i;
    }
    
    int find(int x) {
        if (x == parents[x]) return x;
        else return parents[x] = find(parents[x]);
    }
    
    void unify(int x, int y) {
        int parX = find(x), parY = find(y);
        if (parX == parY) return;
        if (rank[parX] > rank[parY]) swap(parX, parY);

        parents[parX] = parY;
        if (rank[parX] == rank[parY]) rank[parY]++;
    }
    

};


class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int n = source.size();
        UnionFind uf(n);
        for (const auto& swap : allowedSwaps) uf.unify(swap[0], swap[1]);
        
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) components[uf.find(i)].push_back(i);

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
