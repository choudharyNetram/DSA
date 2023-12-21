//  queue using STL 

#include<iostream>
//#include<queue> 
using namespace std ; 
/*
/*
int main(){
    queue<int> q ; /// first in first out  
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    cout<< q.front()<<endl; // first element printing 
    q.pop() ; // first element deleting 
    cout<< q.front()<<endl; 
    if(q.empty()){
        cout<<"q is empty"<<endl ; 
    }
    else {
        cout<<"q is not empty "<<endl ; 
    }
    return 0 ; 
}
*/

/* Queue implementation using classes and objects */
/*
class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/
/*
    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

#include<queue>

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whther queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }
    
    
    


};
/// input restricited queue:- we only insert at rear/ back and output can be done both at rear and front 
/// output restricted queue:- we can insert at front and both but we only take pop from front

// doubly ended queue:- all four operations can be done, push at front and back, pop at front and back :- it is called deque 
// if you want to implement the doubly ended queue using the array than using circular queue method 
// by linked list you can implement by doubly linked list 

*/
// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

/*
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
  
    
    approach 1 vector<long long> ArrayNegInt ;
    long long int i = 0 ; 
    while(i+K <= N){
        for(long long int j = i ; j<K+i ; ){
            if(A[j] <0 ){
                //cout<<A[j]<<endl ; 
                ArrayNegInt.push_back(A[j]) ;
                j = K+i ; 
            }
            else if (j == i+K-1){
                // cout<<0<<endl  ; 
                 ArrayNegInt.push_back(0) ;
            }
            j++; 
        }
        i++; 
    }
    return ArrayNegInt; */
    // In the upper code, it takes a more time when positive number are more, because than time complexity is O(N*K) 
    // we should do something about positive numbers, positive numbers are useless 


    /// approach-2 
    /// here we use a deque for index negative numbers,then we trverse in array then we check that if this index in 
    //  it means that we include in ans vector To  A[i] 
    /*
    vector<long long> VectorNegInt ;
    deque<long long int> dq ; 
    // for first window 
    for(int i = 0 ;i<K ; i++){
        if(A[i]<0){
            dq.push_back(i) ;
        }
    }
    if(dq.size() > 0){
        VectorNegInt.push_back(A[dq.front()]);
    }
    else {
         VectorNegInt.push_back(0); 
    }
    for(int i  = K ; i < N ;i++ ){
        if(!dq.empty() && (i- dq.front() >= K)){  // it means that dq's front (index)printed earlier and the current window doesn't include index front   
            dq.pop_front() ;
        }
        //
        if(A[i] < 0 ){
            dq.push_back(i) ;
        }
        
        if(dq.size() > 0){
            VectorNegInt.push_back(A[dq.front()]);
        }
        else {
            VectorNegInt.push_back(0) ;
        }
    }
    return VectorNegInt ; 
                                                 
}*/