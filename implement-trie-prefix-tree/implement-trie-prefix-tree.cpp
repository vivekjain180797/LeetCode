class Trie {
private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;    

public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->next.find(ch)==node->next.end()) { 
                node->next[ch] = new Trie(); 
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->next.find(ch)==node->next.end()) 
                return false; 
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (node->next.find(ch)==node->next.end()) 
                return false;
            node = node->next[ch];
        }
        return true;
    }
};