// it is type of encoding that build with 0s and 1s (if we goes to left child means 0 and right means 1)
// first thing is that how to build the tree
// first take two smallest frequency number make two nodes of them and 
// also make a parent of this two nodes, the data of this node is sum of both child frequency 
// 
// after doing the above operation then pick those two element their values is smallest
// and also select from the new nodes also
// do the same operation 

/// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

#include<iostream>
using namespace std  ; 
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue> 
class Node{
    public: 
        Node*left ; 
        Node*right ; 
        int data ; 
        Node(int d){
            data = d ; 
            left = NULL ; 
            right = NULL ;
        }
};
class compare{
    public : 
        bool operator()(Node*a, Node*b){
            return a->data > b->data ; 
        }
};
class Solution
{
	public:
	    void traverse(Node*root, vector<string>&ans, string str){
	        if(root->left == NULL && root->right == NULL){
	            ans.push_back(str) ; 
	            return ; 
	        }
	        // go on left side  
	        traverse(root->left, ans, str+"0") ; 
	        // go in right side 
	        traverse(root->right, ans, str+"1") ; 
	        
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, compare>pq ; 
		    for(int i = 0 ;i<N ; i++){
		        Node* temp = new Node(f[i]) ; 
		        pq.push(temp) ; 
		    }
		    while(pq.size()>1){
		        Node* left = pq.top() ; 
		        pq.pop() ; 
		        Node*right = pq.top() ; 
		        pq.pop() ; 
		        
		        // make parent node 
		        Node* parentNode = new Node(left->data + right->data) ; 
		        parentNode->left = left ; 
		        parentNode->right = right ; 
		        pq.push(parentNode) ; 
		    }
		    Node* root = pq.top() ; 
		    vector<string>ans ;
		    string str = "" ; 
		    traverse(root, ans, str) ;
		    return ans ; 
		}
};
