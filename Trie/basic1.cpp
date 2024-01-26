#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isEndOfWord = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isEndOfWord;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    TrieNode* remove(TrieNode* root, string key, int depth = 0) {
        if (!root)
            return NULL;

        if (depth == key.size()) {
            if (root->isEndOfWord)
                root->isEndOfWord = false;

            if (isEmpty(root)) {
                delete root;
                root = NULL;
            }

            return root;
        }

        int index = key[depth] - 'a';
        root->children[index] = remove(root->children[index], key, depth + 1);

        if (isEmpty(root) && root->isEndOfWord == false) {
            delete root;
            root = NULL;
        }

        return root;
    }

    void deleteWord(string word) {
        root = remove(root, word, 0);
    }

    bool isEmpty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Trie * t   = new Trie();  
    t->insertWord("abcd") ; 
    t->insertWord("abc")  ; 
    t->insertWord("rama") ; 
    cout<<"Present or not "<<t->search("abcd") <<endl ; 
    cout<<"Present or not "<<t->search("abc")<<endl  ; 
    cout<<"Present or not "<<t->search("ramayan") <<endl ; 
    cout<<"delete "<<endl ; 
    t->deleteWord("abc") ;
    cout<<"Present or not "<<t->search("abcd") <<endl ;
    cout<<"Present or not "<<t->search("abc") <<endl ;
    return 0;
}
