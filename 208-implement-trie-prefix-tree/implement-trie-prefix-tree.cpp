class TrieNode{
    public:
    TrieNode* children[26];
    bool isend;
    TrieNode(){
        isend = false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
public:
TrieNode*root;
    Trie() {
    root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode*node = root;
        for(char ch:word){
            int index = ch-'a';
            if(node->children[index]==NULL){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
       node->isend=true;
    }
    
    bool search(string word) {
        TrieNode*node=root;
        for(char ch:word){
            int index = ch-'a';
            if(node->children[index]==NULL){
                return false;
            }
            node = node->children[index];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode*node=root;
        for(char ch:prefix){
            int index = ch-'a';
            if(node->children[index]==NULL){
                return false;
            }
            node = node->children[index];
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