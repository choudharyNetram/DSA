// heap is Complete binary tree 
// left se fill krte h 
// Max heap ->  parent is greater than the childrens 
// Min heap ->  parent is smaller than the childrens 

// we put a heap in array whose 0th index is nothing  
// we put first elements in first index and 
// suppose i is the index (0 based indexing) // but we are putting element from index 1 
// left child of the ith index = 2*i 
// right child of the ith index = 2*i +1 ;
// parent  of the ith index is  =  i/2 


// insertion of a node 
//  step 1 : put new node at the end of the array 
//  step 2 : (if we are inserting in max heap) compare node with it parent if it parent is
//  smaller than the new node than we swap new node and it's parent 
/// if parent is greater than the child than insertion completed 

// insertion code 
#include<iostream>
#include<queue> 
using namespace std ;
/// this below code is for the max heap 
class heap {
    public : 

    int  size ; 
    int arr[100];
    // construction heap 
    heap(){
        arr[0]= -1 ; 
        size = 0 ; 
    }
    void insert( int value){
        size = size + 1; 
        int index = size ;
        arr[index]= value ;  
        while(index > 1){
            int parent = arr[index/2] ; 
            if(parent < arr[index]){
                arr[index/2] = arr[index];
                arr[index]= parent ; 
            }
            else {
                return ; 
            }
            index = index /2 ; 

        }
    } 
    // delection of node -->  means that delete first/ root node 
    // steps for deletion ,  put last node's value at place of first node 
    // delete the last node , and put the first node its correct possition 

    void  deletion(){
        if(size == 0){
            return ; 
        }
        int index = 1 ;
        int leftChild = 2*index ; // here leftChild is the index of left child , 
        // leftChild+1 is the index of the right child 
        arr[1] = arr[size] ; 
        size = size-1; 
        while((index < size ) && (arr[leftChild] > arr[index]  || arr[leftChild+ 1]> arr[index])){
            if(arr[leftChild] >= arr[leftChild+1]){
                swap(arr[leftChild], arr[index]);
                index = leftChild; 
                leftChild = index*2 ; 
            }
            else {
                
                swap(arr[leftChild+1], arr[index]);  
                index = leftChild + 1 ; 
                leftChild = 2*index ; 
            }
            
        }

    }
    // what is the leaf node-> which node don't have any child 
    // index values for the leaf node --> ((n/2)+1)
    // what is the heapify algorithms ==> it is a algo. that convert random numbers(array) into heap data structure

    
    void print(){
        for(int  i= 1 ; i<= size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl ;
    }

};

void heapify(int n , int arr[], int i){
        if(i>= n){
            return ; 
        }
        int leftChild = 2*i ;
        int rightChild = 2*i + 1 ; 
        int largest = i; 
        
        if(leftChild <=n && arr[largest] < arr[leftChild]  ){
           largest = leftChild ; 
        }
        if (rightChild <= n && arr[largest]  < arr[rightChild]){
            largest = rightChild ; 
        }  
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(n, arr, largest);
    }

}

/// heap sort --> this method is working is like--> for max heap (we are sorting in increasing order)
// first we swap first number with last number 
// than we decrease the size by 1 and than apply heapify algo. in it because we want largest element at the top
void heapSort(int size , int arr[]){
    if(size<= 0){
        return ; 
    }
    swap(arr[1], arr[size]);
    size-- ; 
    heapify(size , arr, 1 );
    heapSort(size, arr); 
}

int main(){
   /*heap h ; 
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();
    h.deletion();
    h.print();
    h.deletion();
    h.print();
 */
    int arr[6] = {-1, 54, 53,55, 52,50 };
    int n = 5; 
   for(int i = n/2 ; i>0 ;i--){ // after (n/2), no child node came so we itreating loop from (n/2) to 1 ;
        heapify(n, arr ,i );// this heapify function in one call make the node i and below i, all node in heap format  
    }
    for(int i = 1 ;i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    heapSort(n , arr);
    
    for(int i = 1 ;i<=n; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl ;

cout<<endl ; 
/*
    // using STL function for building heap 
    // max heap 
    priority_queue<int> pq ; 
    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(11);
    cout<<"top element "<<pq.top()<<endl; 
    pq.pop();
    cout<<"top element "<<pq.top()<<endl;
    cout<<"size "<<pq.size()<<endl;  

    // min heap 
    priority_queue<int, vector<int> ,greater<int> >minheap ;
    minheap.push(5);
    minheap.push(8);
    minheap.push(1);
    minheap.push(11);
    cout<<"top element "<<minheap.top()<<endl; 
    minheap.pop();
    cout<<"top element "<<minheap.top()<<endl;
    cout<<"size "<<minheap.size()<<endl;  */
    return 0 ;    
}
/*
/// min-heap 
// codingninjas
#include <bits/stdc++.h> 
void heapify(int n , vector<int> &arr, int i){
        if(i>= n){
            return ; 
        }
       int smallest = i ; 
        int leftChild = 2*i+1 ;
        int rightChild = 2*i + 2; // here is the 0 based indexing ,so formula change for left and right child 
        
   
        if(leftChild <n && arr[smallest] > arr[leftChild]  ){
           smallest = leftChild ; 
        }
        if (rightChild < n && arr[smallest] > arr[rightChild]){
            smallest = rightChild ; 
        }  
   
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(n, arr, smallest);
            
        }
}
vector<int> buildMinHeap(vector<int> &arr)
{    int n = arr.size(); 
    for(int i = n/2-1 ; i>=0 ;i--){
        heapify(n, arr ,i );
    }
     return arr ; 
}
*/



