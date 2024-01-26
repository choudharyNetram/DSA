#include <iostream>
#include <vector>

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, const std::string& word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        // assumption: word will be in small letters
        int index = word[0] - 'a';
        TrieNode* child;
        // check if word[0] is present in the children of root
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(const std::string& word) {
        insertUtil(root, word);
    }

    void phonDirectUtil(TrieNode* root, std::vector<std::vector<std::string>>& ans, std::vector<std::string>& word, char lastChar) {
        // iterate over all children
        int index = lastChar - 'a';
        if (root->isTerminal) {
            ans.push_back(word);
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                char ch = i + 'a';
                word.push_back(std::string(1, ch));
                phonDirectUtil(root->children[i], ans, word, ch);
                word.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> phoneDirect(const std::string& queryStr) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> word;
        for (int i = 0; i < queryStr.size(); i++) {
            char ch = queryStr[i];
            int index = ch - 'a';
            word.push_back(std::string(1, ch));
            if (root->children[index] == NULL) {
                return ans;
            } else {
                root = root->children[index];
            }
        }
        int size = queryStr.size();
        char lastChar = queryStr[size - 1];
        phonDirectUtil(root, ans, word, lastChar);
        return ans;
    }
};

std::vector<std::vector<std::string>> phoneDirectory(std::vector<std::string>& contactList, const std::string& queryStr) {
    Trie* t = new Trie();
    for (int i = 0; i < contactList.size(); i++) {
        t->insertWord(contactList[i]);
    }
    return t->phoneDirect(queryStr);
}

int main() {
    std::vector<std::string> contacts = { "john", "jane", "doe" };
    std::string query = "jo";
    std::vector<std::vector<std::string>> result = phoneDirectory(contacts, query);
    for (const auto& entry : result) {
        for (const auto& word : entry) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
