class Solution {
public:
    int distinctIntegers(int n) {
        set<int> set {};
        queue<int> q {};
        q.push(n);
        while(!q.empty()) {
            int popped = q.front(); q.pop();
            set.insert(popped);
            for(int i = 1; i <= popped; i++) {
                if(popped % i == 1 && set.count(i) == 0) {
                    q.push(i);
                } 
            }
        }
        return set.size();
    }
};
