class Solution {        
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        long long res {};
        double CONST_3 = 3.0;
        
        for(int n : nums) maxHeap.push(n);
        
        while(k > 0) {
            int max_element = maxHeap.top();
            res += max_element;
            
            maxHeap.pop();
            maxHeap.push(ceil(max_element / CONST_3));
            --k;
        }
        return res;
    }
};
