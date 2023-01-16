class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res(k);

        priority_queue<vector<int>> maxHeap;

        for(auto p: points) {
            int x {p[0]}, y {p[1]};            
            maxHeap.push({x*x + y*y, x, y});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        for(int i = 0; i < k; ++i) {
            vector<int> popped = maxHeap.top(); maxHeap.pop();
            res[i] = {popped[1], popped[2]};
        }
        return res;
    }
};
