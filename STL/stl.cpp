#include<iostream>
using namespace std ; 
#include<vector>
#include<array>

// the STL array is static so that we don't use in CP
// its size is must be known at compile time 
int main(){
    array<int,4>a= {1,2,3,4};
    
    cout<<a.at(2)<<endl  ; // this  is printing the number at index 2 
    cout<<a.empty()<<endl ; // this is telling that a array  is empty or not 
    cout<<a.front()<<endl ;
    cout<<a.back()<<endl ;
    return 0 ;
}

#include<vector>
int main(){
    vector<int>v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

// size tells that how many input in the vector 
// and capacity tell that how many input can come or how much memory is assigned
// the vector automatically increase its capacity when we  add elements 
    cout<<"capacity="<<v.capacity()<<endl  ;// printing the capacity of the vector 
    cout<<"size="<<v.size()<<endl ;
    cout<<"element at 2nd index "<<v.at(2)<<endl;
    cout<<v.front()<<endl ;
    cout<<v.back()<<endl ;
    
    // pop_back function --> its delete the last element;
    // the vector v before pop 
    for(int i:v){
        cout<<i<<" " ;
    }
    cout<<endl ;
    v.pop_back();
    for(int i:v){
        cout<<i<<" " ;
    }
    // clearing the vector ;
    v.clear();
    cout<<v.size();
    
    return 0 ; 

}
// important properties of for loop 
// for(int i:arr)
/*int main(){
    int arr[4] = {2,4,6,8};
    for(int i:arr){
        cout<<i<<" ";
    }  
    return 0 ;
}*/
/*
int main(){
    // give the size to the vector and intializing
    // intializer mean = what value to give each elements  in vector  
    vector<int>ab(5,1);/// here 5 is the size of the vector and 1 is intiliazier
    // if we don't give intializer than the default intializer is 0
    vector<int>a(5); 
    // printing the vector 
    
    for(int i:ab){
        cout<<i<<" ";
    }
    cout<<endl  ;
    for(int i:a){
        cout<<i<<" ";
    }
    // how to copy a vector in a new empty vector 
    vector<int>last(a);
    for(int i:last){
        cout<<i<<" ";
    }
    cout<<endl  ;
    

    return 0 ;

}
*/

/*************
/// Deque 

#include<deque>

int main(){
    deque<int>d ;
    d.push_back(1);
    d.push_front(3);
    for(int  i: d){
        cout<<i<<" ";
    }
    //d.pop_front();
    //d.pop_back();
    cout<<d.at(1);
    cout<<d.front(); /// printing first elements 
    cout<<d.back(); /// printing last elements 

    cout<<d.empty()<<endl ; // checking  d is empty or not 
    cout<<d.size()<<endl ;//--->  for size 
    //  erase function , how to delete many elements 
    d.erase(d.begin(),d.begin()+1); // deleting first elements 
    cout<<d.size()<<endl;
    for(int  i: d){
        cout<<i<<" ";
    }
    return 0 ;
}
*/

/*
//// list  
#include<list>
int main(){
    list<int> l ;
    l.push_back(1);
    l.push_front(2);
    for(int i :l){
        cout<<i<<endl  ;
    }
    l.erase(l.begin()); 
    for(int i :l){
        cout<<i<<endl  ;
    }
    // we can also use pop_back and pop_front and size of list 
    // intilazing a list 
    list<string>nl(6,"jat"); // here 6 is the size of the list and jat is the element in list at each place
    for(string i:nl){
        cout<<i<<" ";
    }
    cout<<endl ;
    list<int>ml(4,8);
    for(int i:ml){
        cout<<i<<" ";
    } 
    
    return 0 ;
    
}

 */

 // stack 
 /*
#include<stack>
int main(){
    stack<string>s ;
    s.push("jat");
    s.push("jatt");
    s.push("sarkar");
    cout<<s.top()<<endl ; // the top or which element filled last was printed
    s.pop();  // the top element is deleted  
    cout<<s.top()<<endl ;
    cout<<"size of stack "<<s.size()<<endl ;
    cout<<"empty or not "<<s.empty()<<endl ;

    cout<<s.top()<<endl ;
    cout<<endl  ;
    return 0 ;

}
*/
/*
// **queue*** 
// queue is like a line or who goes first come first 
#include<queue>
int main(){
    queue<string> q ;
    q.push("jat");
    q.push("jatt");
    q.push("sarkar");
    cout<<q.front()<<endl ;
    cout<<q.size()<<endl  ;
    q.pop();  // the first element is deleted 
    cout<<q.size()<<endl  ; 
    cout<<q.front()<<endl ;
    return 0 ;

}*/


/// priority queue 
// the first elements is always greatest 
// if we make max heap only  we can get is maximum elements and in the maxi the top element is always maximum number 
// and we pop in maxi the top element is deleted or maximum number is deleted
// and we make min heap than only we can get is minimum elements 
/*
#include<queue>
int main(){
    // max heap 
    priority_queue<int> maxi;

    // min heap 
    priority_queue<int, vector<int>, greater<int> >mini ;
    maxi.push(1);
    maxi.push(4);
    maxi.push(2);
    maxi.push(8);
    int n = maxi.size();
    for(int i = 0 ; i<n; i++){
        cout<<maxi.top()<<endl ;
        maxi.pop();
    }   
    mini.push(1);
    mini.push(4);
    mini.push(2);
    mini.push(8);
    n = mini.size();
    for(int i = 0 ; i<n; i++){
        cout<<mini.top()<<endl ;
        mini.pop();
    }   
    cout<<maxi.empty();
}
*/

// set --> it's all elements are unique 
// no modification or we can't change one element to another 
// we only delete or add elments 
//the elements are come in sorted order
// set is slow and unordered set is fast 
/*
#include<set>
int main(){
    set<int>s ;
    s.insert(1);
    s.insert(1);
    s.insert(8);
    s.insert(3);
    s.insert(20);
    for( auto i :s){    // we can take auto or we specifi the type of element
        cout<<i<<" ";
    }
    cout<<endl; 
    // taking iterater from outside 

    s.erase(s.begin());
    
    for( auto i :s){   
        cout<<i<<" ";
    }
    cout<<endl ;
    set<int> ::iterator iter = s.begin();
    iter++ ;
    s.erase(iter);
    for( auto i :s){   
        cout<<i<<" ";
    }
    // finding a number is present   or not (count function )
    cout<<"8 is present or not "<<s.count(8)<<endl ; 
    //finding the index where the number is present
    set<int> ::iterator it = s.begin();
    set<int>::iterator itr = s.find(8);

    for(auto it=itr; it!=s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl ;
}
*/

/// map ===> in map the data stored in the form of key and value 
// all keys are unique and one key point to only one value 
// same key never point to two or more value  
// 
/*
#include<map>

int main(){
    map<int,string> m ; // this is the string key is the integer and value is the string
    // the keys in map is sorted 
    //  but in the unorder_map the sequence in random 
    m[1]= "jat";
    m[5]= "siddu" ;
    m[8]= "sarkar";
    // we can add the key and value by this way also
    m.insert({7, "mosewala"});
    cout<<"before erase"<<endl ;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl ;
    }
    // the way to see the key is present or not 
    cout<<"finding 13-->"<<m.count(8)<<endl;
    m.erase(8);
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl ;
    }
    // map me search ki complexity O(logn)
    // unordered_map me search ki complexity O(1)

    // iterator 
    auto it = m.find(5);
    for(auto i = it ; i != m.end(); i++){
        cout<<(*i).first<<" "<<(*i).second<<endl ;
    }
}

*/




// STL  algorithms 
/*
#include<algorithm>
#include<vector>
int main(){
    vector<int>v ;
    v.push_back(1);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);
    // checking a element is present or not 
    cout<<"finding number"<<" "<<binary_search(v.begin(),v.end(),7)<<endl;
    cout<<"lower bound"<<" "<<lower_bound(v.begin(), v.end(),7)-v.begin()<<endl;
    cout<<"upper bound"<<" "<<upper_bound(v.begin(), v.end(),7)-v.begin()<<endl ;
    
    int a = 5 , b = 7 ;
    cout<<" max "<<max(a,b)<<endl;
    cout<<v<<endl ;
    cout<<"min"<<min(a,b )<<endl;
    swap(a,b);
    cout<<a<<endl ;
    string s = "abcd";
    reverse(s.begin(), s.end());
    cout<<s<<endl ;
    rotate(v.begin(), v.begin()+1 , v.end()); 
    for(int i:v){
        cout<<i<<" " ;
    }
    return 0 ;
}
*/
