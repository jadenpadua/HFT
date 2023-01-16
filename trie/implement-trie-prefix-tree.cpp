class Trie {
private:
    array<unique_ptr<Trie>, 26> children;
    bool isWord = false;

public:
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word) {
            c -= 'a';
            if(!node->children[c]) node->children[c] = make_unique<Trie>();
            node = node->children[c].get();
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word) {
            c -= 'a';
            if(!node->children[c]) return false;
            node = node->children[c].get();
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix) {
            c -= 'a';
            if(!node->children[c]) return false;
            node = node->children[c].get();
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
