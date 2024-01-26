// this file include love babbar series vedio number 51,52 //
// linked list problems 

// vedio 51 
// detect is a loop exist in a linked list or not 

// first approach 
/*  first we create a map and we take node as a key and boolean as value 
when any node is visited we mark as a true and than if we encounter any node 
which is already visited than we found that a loop exist in the linked list 
// map<node*, bool> visited ; 
*/
/*
#include<map>
bool detectloop(Node* head){
    if(head == NULL){
        return false ;
    }
    map<Node*,bool> visited ;
    int curr = head ;
    while(curr != NULL){
        if(visited[curr]==1){
            return true ;
        }
        visited[curr]=true ; 
        curr = curr->next ;
    }
    return false ;

}





// using floyd's cycle finding algorithms 
// in this method , we take two pointers one is slow and another one is fast 
// slow move one step  and fast move two moves 
// if in the linked list the cycle exist than slow or faster meet ones 
// leetcode 
// why slow and fast must meet: then they both are in the cycle than 
// by each iteration the  distance between fast and slow is decreasing by 1 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        if(head == NULL){
            return NULL ;
        }
        if((head -> next == NULL )  || (head ->next ->next == NULL)){
            return false ;
        }
        while((slow->next != NULL) && (fast->next != NULL)&& (fast->next ->next  != NULL)){
            slow = slow ->  next ;
            fast = fast->next ->next  ;
            if(slow == fast){
                return true ; 
            }
        }
        return false; 
    }
};


// find the node where the loop is starting 
// leetcode solution  
class Solution {
    private: 
    bool hasCycle(ListNode *head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        if(head == NULL){
            return false ;
        }
        if((head -> next == NULL )  || (head ->next ->next == NULL)){
            return false ;
        }
        while((slow->next != NULL) && (fast->next != NULL)&& (fast->next ->next  != NULL)){
            slow = slow ->  next ;
            fast = fast->next ->next  ;
            if(slow == fast){
                return true ; 
            }
        }
        return false; 
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(hasCycle(head)){
            ListNode* slow = head ;
            ListNode* fast = head ;
            
            
            while(true){
                slow = slow ->  next ;
                fast = fast->next ->next  ;
                if(slow == fast){
                    slow  = head ;
                    //int i = 0  ;
                    while(slow != fast){
                        slow = slow->next ;
                        fast = fast->next ;
                    } 
                    return fast ; 
                // cout<<"tail connects to  node index"<<i<<endl; 
                }
            }
            
        }
        
        else{
            return NULL ; 
        }
    }
};

// remove the loop from the linked list 
/// this  below code is only the psedo code 

void removeLoop(Node* head){
    if(head == NULL){
        return ;  
    }
    Node* temp  = firstNodeOfLoop;
    while(temp -> next != firstNodeofLoop ){
        temp = temp->next ;
    }
    temp->next = NULL ;

}
*/

