#include<iostream>
using namespace std ;

class Node{
    public :
    int data ;
    // constructur 
    Node* next ;
    Node(int data){
        this -> data = data ;
        this -> next = NULL ;
    }       
    // destructor 
    ~Node(){
        int value = this -> data ;
        if(this -> next != NULL){
            delete next  ;
            next = NULL ;
        }
        cout<<"memory is free for Node with data "<< value <<endl ;
    }
};

// in this insertion function we take a element and put new node after this *elements wali Node*
void insertNode(Node* & tail ,int element,  int data){
    Node* temp = tail ;
    Node* NodeToInsert = new Node(data);
    if(temp== NULL){
        temp = new Node(data);
        temp->  next = temp ;
        tail = temp ;
    }
    else{
    
    while ( element != temp-> data  ){
        temp = temp -> next ;
    }
    NodeToInsert-> next =  temp -> next ;
    temp->  next = NodeToInsert ;
    }
}

void print(Node* & tail){
    if(tail == NULL){
        cout<<" list is empty"<<endl ; 
    }
    else {
    Node * temp  = tail ;
    /*cout<<tail -> data << " ";
    while (temp->next != tail){
        cout<< temp-> data << " ";
        temp = temp -> next ;
    }
    cout<<endl ;*/
    // for this we can use do while loop 
    // dod while is excute at least once and further depend on the condition 
    do{
        cout<< temp-> data << " ";
        temp = temp -> next ;
    } while (temp!= tail);
    cout<<endl; 
    }
}

// deletion of a Node 
void deleteNode(Node* & tail, int element){
    if(tail == NULL){
        cout<<"list is empty, please check again"<<endl ;
        return ;
    }
    
    else {
    Node* prev = tail ;
    Node* Nodefordelete = prev->next ; 
    while (element != Nodefordelete->data){
        prev  = Nodefordelete ;
        Nodefordelete =  Nodefordelete -> next ;   
    }
    // for one node linked list 
    if(prev == Nodefordelete){
        tail = NULL ;  
    }
    else{
        if(Nodefordelete == tail){      // this is required when tail is also deleted with node so here we should update tail node 
            prev -> next = Nodefordelete->next ;
            tail = Nodefordelete->next  ; 
            Nodefordelete -> next = NULL ;
            delete Nodefordelete ; 
        }
        else {
            prev -> next = Nodefordelete->next ;
            Nodefordelete -> next = NULL ;
            delete Nodefordelete ; 
        }
    }
    }
}
int main(){
    Node* tail = NULL; 
    insertNode(tail, 5 , 10);
    print(tail);
    
    insertNode(tail, 10 , 20);
    print(tail);
    insertNode(tail, 20, 30);
    print(tail);
    //cout<<tail-> data <<endl ; 
    insertNode(tail, 30, 40);
    print(tail);
    insertNode(tail,40 , 50);
    print(tail);
    deleteNode ( tail, 10);
    print (tail);
    return 0 ;

}