// Trie is a tree like structure 
// we are making a dictionary 
 
// Insertion in Trie: Let say we have to add the "RAM" 
// two cases: is there a R in the children of root, if Yes then go ahead 
// if no R in children of  root then make a R child 
// like that then we seach for the A and then M 

//  TrieNode class 
/* TrieNode {
    char data ; 
    TrieNode * children[26] ; 
    bool isTerminal ; 
}*/
// we have to which node is terminal node 
// if (last_node_of_string == a terminal node) { then "Yes" string is found}

#include<iostream> 
using namespace std ; 

class TrieNode {
    public : 
        char data ; 
        TrieNode * children[26] ; 
        bool isTerminal ; 
        TrieNode(char ch){
            data = ch ; 
            for(int i = 0 ; i<26 ;i++){
                children[i] = NULL ; 
            }
            isTerminal = false  ; 
        } 
} ; 





class Trie{
    public: 
        TrieNode* root ; 
        Trie(){
            root = new TrieNode('\0') ; 
        }
        
        /* */
        void insertUtil(TrieNode* root, string word){
            // base case 
            if(word.length() == 0){
                root->isTerminal = true ; 
                return ; 
            }
            // assumption, word will be in small letter
            int index = word[0]-'a'  ; 
            TrieNode *child ; 
            //  is word[0]  is present in the children of root 
            if(root->children[index] != NULL){
                child = root->children[index]  ; 
            }
            else {
                 child = new TrieNode(word[0])  ; 
                 root->children[index]  = child ; 
            }
            insertUtil( child , word.substr(1)) ; 
        }
        void insertWord(string word){
            insertUtil(root, word) ; 
        }

        bool searchUtil(TrieNode* root, string word){
            if(word.length()==0){
                return root->isTerminal ; 

            }

            int index = word[0]-'a'  ; 
            TrieNode* child ; 
            if(root->children[index] != NULL){
                child = root->children[index] ; 
            }
            else {
                return false ; 
            }
            return  searchUtil(child, word.substr(1)) ;   
        }
        bool search(string word){
            return searchUtil(root, word)  ; 
        }
        void deleteUtil(TrieNode* root, string  word){
            if(word.length()==0){
                if(root->isTerminal == false){
                    cout<<"there is no such  word"<<endl ;
                }
                root->isTerminal = false ; 
                return ; 
            }
            int index  = word[0]-'a' ;
            if(root->children[index] != NULL){
                TrieNode* child = root->children[index] ; 
                deleteUtil(child, word.substr(1)) ;
            }
            else {
                cout<<"there is no such  word"<<endl ;
                return ; 
            }
        }
        void deleteWord(string word){
            deleteUtil(root, word) ; 
        }
} ;
int main(){
    //cout<<"Present or not "<<endl ;
   Trie * t   = new Trie();  
    t->insertWord("abcd") ; 
    t->insertWord("abc")  ; 
    t->insertWord("rama") ; 
    cout<<"Present or not "<<t->search("abcd") <<endl ; 
    cout<<"Present or not "<<t->search("abc")<<endl  ; 
    cout<<"Present or not "<<t->search("ramayan") <<endl ; 
    cout<<"delete "<<endl ; 
    t->deleteWord("abcd") ;
    cout<<"Present or not "<<t->search("abcd") <<endl ;
    cout<<"Present or not "<<t->search("abc") <<endl ;
    return 0 ; 
}


