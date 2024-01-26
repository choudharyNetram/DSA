#include<iostream>
using namespace std ;
// implemetion of linked list 
// singly linked list 

/*
class Node{
    public :
    int data ;
    Node* next ;
    // constructer /  constructing a node 
    Node(int data){
        this -> data = data ;
        this -> next = NULL;
    }
    /// destructor a node 
    ~Node(){
        int value = this -> data ;
        // memory free 
        if(this -> next != NULL){
            delete next ;
            this -> next = NULL ;
        }
        cout<<" memory is free for Node with data "<< value <<endl ;
    }

};
void  insertionOfNodeAtHead(Node* &head , int data){
    Node* temp = new Node(data);  // creating new node 
    temp -> next = head ; // here we removing the null pointer and pointing the pointer of new Node to  head (next--->head)
    head  = temp ; // changing the value of head 
}

void insertAtTail(Node* &tail , int data ){
    Node* temp = new Node(data);
    tail -> next = temp ;
    tail = tail-> next ; // iska mtlb= previous tail ka next jis node pe ja rha h 
}

void print(Node* &head){
    Node*temp = head ;
    while (temp != NULL){
        cout<<temp -> data <<  " " ;
        temp = temp -> next ;  // here we update temp to new pointer
    }
}

// insertion at index position of linkedList 
void insertAtMiddle( Node* &head , int position, int data){
    if(position == 1 ){
        insertionOfNodeAtHead(head , data);
        return ;
    } 
    // this upper if condition required because for below code we must reqired two old nodes but at starting we don't have two nodes 
    // or the below code we required a node that come before the nodeToInsert 
    Node* temp = head ;
    int i = 1 ;
    while (i<position-1){
        temp = temp -> next ;
        i++  ; 
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp-> next ; // mean of this (temp -> next) is that *node where the temp node's pointer going 
    temp -> next = nodeToInsert ; /// temp node ka pointer kha ja rha ans = nodeToInsert node me ;
}

void deleteNodeByPosition(int position, Node* &head){
    if(position == 1){
        // first node 
        Node* temp = head ;
        head = head -> next ;
        temp -> next =  NULL ;
        delete temp ;
    }
    else{
        Node* prev = head ;           /// prev is previous node 
        Node* deleteNode = head ;       // this node is which  that we delete 
        int i = 1 ;
        while(i<position){
            prev = deleteNode ;
            deleteNode = deleteNode -> next ;
            i++ ;
        }
        prev -> next = deleteNode-> next ;
        deleteNode-> next = NULL ;   // here we delte deleteNode because we don't want any useless node who pointing in our LL 
        delete deleteNode ; 

    }


}
int main(){
    // creating a new node 

    Node* node1 = new Node(10);
    cout<<node1<<endl ; 
    
    Node* tail = node1 ;
    Node* head = node1; 
    print(head);
    cout<<endl ;
    insertAtTail(tail ,12);
    print(head);
    cout<<endl ;
    insertAtTail(tail ,15);
    print(head) ;
    cout<<endl;
    insertAtMiddle(head , 1, 44);
    print(head);
    cout<<endl;
    deleteNodeByPosition(1,head );
    print(head);
    return 0 ; 
}

*/
/*
class Node{
    public : 
    int data ; 
    Node* next ;
    Node* prev ;
    // constructer
    Node(int data){
        this -> data = data ;
        this -> next = NULL ;
        this-> prev = NULL ;
    }
    ~Node(){
        int value = this -> data ;
        // memory free 
        if(this -> next != NULL){
            delete next ;
            this -> next = NULL ;
        }
        cout<<" memory is free for Node with data "<< value <<endl ;
    }

};
void print(Node* & head){
    Node* temp = head ;
    while(temp != NULL){
        cout<< temp-> data <<" ";
        temp = temp -> next ;
    }
}
int getLength(Node* & head){
    Node* temp = head ;
    int length = 0 ;
    while(temp != NULL){
        length++ ; 
        temp = temp -> next ;
    }
    return length ;
}

void insertAtHead(Node* &head, Node* & tail , int data ){
    // if our head is NULL than how to insert a new Node ;
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp ; 
        tail = temp ;
    }
    else {
    Node* temp = new Node(data);
    temp -> next = head  ;
    head -> prev = temp ;
    head = temp ;
    }
}

void insertAtTail(Node* &tail , Node* &head ,int data){
    if(tail== NULL){
        Node* temp = new Node(data);
        head = temp ; 
        tail = temp ;
        return ; 
    }
    Node* temp = new Node(data);
    tail -> next = temp ;
    temp -> prev = tail ;
    tail = temp ;
}
void insertAtPosition(Node* &head , Node* &tail,int position, int data){
    Node* temp = head ;
    Node* nodeToInsert = new Node(data);
    if(position==1){
        nodeToInsert -> next = head ;
        head -> prev = nodeToInsert ;
        head = nodeToInsert ;
        return ; 
    }
    
    int i = 1 ;
    while (i<position-1){
        temp = temp -> next ;
        i++ ;
    }
    if(temp -> next == NULL){
        insertAtTail(tail, head , data);
        return ; 
    }
    nodeToInsert -> next = temp -> next ;
    temp -> next -> prev = nodeToInsert ;
    temp -> next = nodeToInsert ;
    nodeToInsert -> prev = temp ;
    
}
void delectionByPosition(Node* & head , Node* &tail, int position){
    
    
    int i = 1 ;
    if(position == 1){
        Node* deleteNode = head ; 
        Node* prevs = head ;  
        deleteNode-> next -> prev = NULL; 
        head = head -> next ;
        deleteNode -> next  = NULL ;
        delete deleteNode ; 
        return ; 
    }
    Node* prevs = NULL ;  
    Node* deleteNode = head ; 
    while(i<position){
        i++ ;
        prevs = deleteNode ; 
        deleteNode = deleteNode -> next ;
        
    }
    if(deleteNode -> next == NULL){
        prevs -> next = NULL ;
        deleteNode -> prev = NULL;
        tail = tail -> prev ;
        return ; 
    }
    prevs -> next = deleteNode -> next ;
    deleteNode-> next -> prev = deleteNode -> prev ;
    deleteNode  = NULL ;
    
    delete deleteNode;
    return ; 
}

int main(){
    Node* node1 = new Node(10);
    //Node * head  = node1 ;
   // Node * tail = node1 ;
    Node * head  = NULL;
    Node * tail = NULL ;
    print(head);
    cout<<endl ;
    cout<<getLength(head) << endl; 
    insertAtHead(head ,tail ,  11 );
    // at the up we inserting tail because at starting  the tail is NULL but when we a add Node than we should update  head and tail both 
    // and than our insertAtHead function taking  3 input that why we give  every time tail as a input 
    print(head);
    cout<<endl ;
    //cout<< tail->  data <<endl;
    insertAtHead(head ,tail,  12 );
    print(head);
    cout<<endl ;
    insertAtHead(head ,tail,  5);
    print(head);
    cout<<endl ;
    insertAtTail(tail ,head ,  70);
    print(head);
    cout<<endl;
    insertAtPosition(head, tail ,5, 89);
    print(head);
    cout<<endl ;
    delectionByPosition(head , tail,3);
    print(head);

    return 0 ;
}
*/



