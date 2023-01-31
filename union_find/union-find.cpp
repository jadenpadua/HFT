
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
