
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq {};
        for (const char& c: tasks) ++freq[c];

        priority_queue<pair<int, char>> pq;
        for (const auto& it: freq) pq.push({it.second, it.first});
        
        int res = 0;
        int cycle = n + 1;
        while(!pq.empty()) {
            int time = 0;
            vector<pair<int,char>> temp;
            for(int i = 0; i < cycle; ++i) {
                if(!pq.empty()) {
                    pair<int,char> popped = pq.top(); pq.pop();
                    temp.push_back(popped);
                    ++time;
                }
            }
            for(const auto& pair: temp) {
                int newFreq = pair.first - 1;
                if(newFreq > 0) pq.push({newFreq, pair.second});
            }

            res += !pq.empty() ? cycle : time;
        }
        return res;
    }
};
