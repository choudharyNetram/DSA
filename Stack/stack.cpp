#include<iostream>
//#include<stack>
using namespace std;
/*int main(){
    stack<int>s ;
    s.push(1);
    s.push(2);
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl; // checking is stack  is empty or not 
    cout<<s.size()<<endl ; // size of the stack
    s.pop();
    cout<<s.top()<<endl;

    return 0 ;
}*/

// stack implemention using array
/*
class stack {
    public:
    // properties 
    int *arr ;
    int top ; /// this is the (top)th index 
    int size ;
    // behavior 
    stack(int size){
        this -> size =  size ;
        arr = new int[size];
        top = - 1 ; 
    }
    void push (int element){
        if(top<size-1){
            top++ ; 
            arr[top] =  element ;
        }
        else {
            cout<<"stack overflow"<<endl; 
        }
    }
    void pop(){
        if(top != -1){
            //arr[top] = ' ' ;
            top -- ;  
        }
        else {
            cout<<" stack underflow " ; 
        }
    }
    int  peek(){
        if(top >= 0 & top <= size-1){
            return arr[top] ;
        }
        else {
            cout<<" stack is empty" ;
            return  -1;
        }
    }
    bool isEmpty(){
        if(top == -1){
        return true ; 
        }
        else {
            return false ; 
        }
    }
    // time complexity of all the function O(1) 
};

int main(){
    stack st(5) ;
    //top = -1 ;

    st.push(2);
    st.push(8);
    st.push(30);
    st.push(34);
    cout<<st.peek()<<endl ;
    st.pop() ; 
    cout<<st.peek()<<endl;
    st.pop() ; 
    cout<<st.peek()<<endl;
    st.pop() ; 
    cout<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;

    return 0 ; 
}


//******* two stack in an array********
// here is the logic is that we use two top interger one for first stack
// and the other one for second stack 
// we start iterating first stack from 0 and second stack from n-1 ;

// 
class TwoStack {

public:
    int *arr ;
    int top1, top2 ;
    int size ;
    // Initialize TwoStack.
    TwoStack(int s) {
        
        this->size = s ;
        top1 = -1 ;
        top2 = s ;    
        arr = new int[s];
         
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1<top2-1){
            top1++ ;
            arr[top1] = num ;
        }
        
        
    }

    // Push in stack 2.
    void push2(int num) {
        
        if(top1<top2-1){
            top2-- ;
            arr[top2] = num ;
        }
       
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
       
        if(top1 >= 0){
            top1 -- ;
            int ans = arr[top1+1];
            return ans ; 
            
        }
        else {
            
            return -1 ; 
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
       
        if(top2 < size){
            top2++;
            int ans = arr[top2-1] ;
            return ans ;
        }
        else {
            
            return -1 ; 
        }
    }
};*/
// second method for above questions is that 
//  we divide array into two part and take each size is n/2 
// but in this method space can be wasted so it is not effieient way


// stacks implemation using linked list 
/*
struct Node 
{
    int  data ;  
    Node* next  ;  
};
Node* top = NULL ;

bool isempty(){
    if(top == NULL){
        return true ;
    }
    else {
        return false ;
    }
}

void push(int data){
    Node*  ptr = new Node();
    ptr -> data = data ;
    ptr -> next = top ;
    top = ptr ;
}

void pop(){
    if(isempty()){
        cout<<"stack is already empty";
    }
    else {
        Node* temp = top ; 
        top = top -> next ;
        free(temp);
    }
}

int peek(){
    if(isempty()){
        cout<<"the stack is empty";
        return -1 ; 
    }
    else{
        return top-> data ;
    }
}
int main()
{
    
    // Push the elements of stack
    cout<<isempty()<<endl ;
    push(11);
    push(22);
    cout<<isempty()<<endl ;
    push(33);
    push(44);
 
    // Print top element of stack
    cout << "\nTop element is " << peek() << endl;
 
    // Delete top elements of stack
    pop();
    pop();
    // Print top element of stack
    cout << "\nTop element is " << peek() << endl;
    pop();
    pop();
    pop();
    pop();
 
    return 0;
}*/