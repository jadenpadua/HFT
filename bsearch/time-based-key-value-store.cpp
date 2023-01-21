typedef pair<int, string> PIS;

class TimeMap {
private:
    unordered_map<string, vector<PIS>> umap_;
public:
    TimeMap() : umap_({}) {}
    
    void set(string key, string value, int timestamp) {
        umap_[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!umap_.count(key)) return "";

        vector<PIS> v = umap_[key];

        int left = 0, right = v.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(v[mid].first == timestamp) return v[mid].second;

            else if(v[mid].first > timestamp) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left > 0 && left <= v.size() ? v[left-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
