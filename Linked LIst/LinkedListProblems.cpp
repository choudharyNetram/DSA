#include<iostream>
using  namespace std ;
// how to reverse a linked list 
/*
 Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
/*
Node* reverseLinkedList(Node *head)
{
    if(head ==NULL || head-> next == NULL){
        return head ;
    }
    Node* prev = NULL;
        Node* curr = head;
    Node* forward =   NULL ;
        while(curr != NULL){
            forward = curr->next ; 
            curr-> next = prev ;
            prev = curr ;
            curr = forward;
           
        }
        return prev ;
}
*/
//  malloc fundtion-> it is used  for dynamic memory allocation 
// it allocates memory at run time 
// malloc take the size of the input in bytes 
// *** for using malloc  we must add a header  file called <stdlib.h>



// problem-> find a middle of linked list 
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head ; 
        int k = 0; 
        while(curr!= NULL){
            k++ ; 
            curr = curr -> next ;
        }
        curr = head ;
        for(int i = 1 ;i<=k/2 ; i++){
            
            curr = curr->next ;
            
        }
        return curr ;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head-> next == NULL) {
            return head ; 
        }
        // when 2 node 
        if(head -> next -> next == NULL) {
            return head-> next ;
        }
        ListNode* curr1 = head ;
        ListNode* curr2 = head ;
        while(curr2 != NULL &&  curr2->next != NULL){
             curr2 = curr2-> next->next ;
             curr1 = curr1 -> next ;
            
            //curr2 = curr2-> next ;
        }
        return curr1 ;
    }
};

*/



// reverse a linked list in group of k 
// example-> reverse a linked list in grouop of 2 ==> 1,2,3,4,5,6 
// answer of this question must be ==> 2,1,4,3,6,5 
// If the number of nodes is not a multiple of number of group then left-out nodes, in the end, should remain as it is. 

// when the k si in the multiple of length 
/* /// codestudio 
Node* kReverse(Node* head, int k) {
    if(head == NULL){
        return NULL ;
    }
    Node* next = NULL ;
    Node* curr = head ;
    Node* prev = NULL ;
    int count = 0 ;  
   while( curr!= NULL && count < k){
       next = curr ->  next ;
       curr-> next = prev ;
       prev = curr; 
       curr = next   ;
       count ++ ; 
   }
    if(curr != NULL){
        head-> next =  kReverse(curr, k);
    }
    return prev ; 
    
}
 // leetcode 
/*
// when k can be or not be in the multiple of length 
 ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* te = head ; 
    for(int i = 0 ; i< k ; i++){
        
        if(te == NULL){
            return head ;
        }
        te = te -> next; 
    }
    ListNode* next = NULL ;
    ListNode* curr = head ;
    ListNode* prev = NULL ;
    int count = 0 ;  
   while( curr!= NULL && count < k){
       next = curr ->  next ;
       curr-> next = prev ;
       prev = curr; 
       curr = next   ;
       count ++ ; 
   }
    if(curr != NULL){
        head-> next =  reverseKGroup(curr, k);
    }
    return prev ; 
    
}
};
*/