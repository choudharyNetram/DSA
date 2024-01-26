 /*
 Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
 */
 
 /*One way to use the standard Trie class and find the how many child it has 
 another way is make a new variable in class TrieNode 'childCount', it gives  number of childs
*/

#include<iostream> 
using namespace std ; 
#include<vector>
#include<string> 
class TrieNode {
    public : 
        char data ; 
        TrieNode * children[26] ; 
        int childCount ; 
        bool isTerminal ; 
        TrieNode(char ch){
            data = ch ; 
            for(int i = 0 ; i<26 ;i++){
                children[i] = NULL ; 
            }
            childCount = 0 ; 
            isTerminal = false  ; 
        } 
} ; 

class Trie{
    public: 
        TrieNode* root ; 
        Trie(char ch){
            root = new TrieNode(ch) ; 
        }
        
    
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
                root->childCount++; 

                 root->children[index]  = child ; 
            }
            insertUtil( child , word.substr(1)) ; 
        }
        void insertWord(string word){
            insertUtil(root, word) ; 
        }
        void lcp(string str, string&ans){
           
            for(int i = 0 ;i<str.length() ;i++){
                char ch = str[i]  ; 
                
                if(root->childCount == 1){
                    ans.push_back(ch)  ; 
                    int index = ch-'a' ; 
                    root = root->children[index] ; 
                }
                else {
                    break;  
                }
                if(root->isTerminal){
                    break ; 
                }

            }
        }
        
       
        
} ;
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie * t   = new Trie('\0');  
    for(int i = 0 ;i<n ;i++){
        t->insertWord(arr[i]) ;
    }
    string str  = arr[0] ; 
    string ans = "" ; 
    t->lcp(str, ans) ; 
    return ans ; 
   
}


 /*
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
        string prefixSizeUtil(TrieNode* root, int size, string&s){
            
            // searching how many children it has 
            int count = 0 ; TrieNode* child ; int index = -1 ; 
            for(int i = 0 ;i<26 ;i++){
                if(root->children[i] != NULL){
                    count++; 
                    index = i ; 
                    child = root->children[i] ; 
                }
            }
            if(count==0 ||  count>1){
                return s ; 
            }
            char ch = 'a'+index; 
            s = s+ch ; 
            return prefixSizeUtil(child, size+1, s) ;    
        }
        string prefixSize(){
            // checking that how many child root has 
            string s = "" ; 
            int count = 0 ; TrieNode* child ; int index = -1 ; int size = 0 ; 
            for(int i = 0 ;i<26 ;i++){
                if(root->children[i] != NULL){
                    count++; 
                    index = i ; 
                    child = root->children[i] ; 
                }
            }
            if(count==0 ||  count>1){
                return s ; 
            }
            char ch = 'a'+index; 
            s = s+ch ; 
            return prefixSizeUtil(child, 1, s) ;
        }
        
} ;
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie * t   = new Trie();  
    for(int i = 0 ;i<n ;i++){
        t->insertWord(arr[i]) ;
    }
    
   return t->prefixSize() ; 
}

*/

