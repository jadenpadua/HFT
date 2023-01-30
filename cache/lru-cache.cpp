class LRUCache {
    int capacity_;
    list<int> keys_;
    unordered_map<int, pair<int, list<int>::iterator>> umap_;

public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if(umap_.find(key) != umap_.end()) {
            keys_.erase(umap_[key].second);
            keys_.push_front(key);
            umap_[key].second = keys_.begin();
            return umap_[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(umap_.find(key) != umap_.end()) {
            keys_.erase(umap_[key].second);
            keys_.push_front(key);
            umap_[key] = {value, keys_.begin()};
        }
        else {
            if(umap_.size() >= capacity_) {
                umap_.erase(keys_.back());
                keys_.pop_back();
            }
            keys_.push_front(key);
            umap_[key] = {value, keys_.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
