class Trie {
public:
    Trie() : children(26, nullptr), endOfWord(false) {}
    
    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new Trie();
            }
            curr = curr->children[c - 'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for (int i = 0; i < prefix.length(); ++i) {
            char c = prefix[i];
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c - 'a'];
        }
        return true;
    }
private: 
    vector<Trie*> children;
    bool endOfWord;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */