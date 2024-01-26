#include<iostream>
using namespace std ;

/// Bfs traversal  
#include<unordered_map>
#include<list>
#include<queue>
#include<set> 
void prepareadjlist( unordered_map<int, list<int>> &adjlist , vector<pair<int, int>> &edges){
    for(int i = 0 ; i< edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int>> &adjlist ,unordered_map< int, bool> &visited ,vector<int> &ans ,int  node){
    queue<int>q ;
    q.push(node);
    visited[node]= 1 ;
    while(!q.empty()){
        int frontNode =  q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1 ;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   unordered_map<int, list<int>> adjlist ;
   vector<int> ans; 
   unordered_map< int, bool> visited ;
    prepareadjlist(adjlist, edges);
    for(int i = 0 ; i< vertex; i++){
        if(!visited[i]){
            bfs(adjlist, visited, ans, i )
;        }
        }
    return ans ;
}

// In this question at this platform we need to print ans in sorted order , it means that if we have two adjacecy nodes at one node than we  first print the small node first , after it the bigger node 
//  so in the adjlist,instead of a list we take a set of nodes 
//////******* using set instead of list 
#include<unordered_map>
#include<list>
#include<queue>
#include<set> 

void prepareadjlist( unordered_map<int, set<int>> &adjlist , vector<pair<int, int>> &edges){
    for(int i = 0 ; i< edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adjlist ,unordered_map< int, bool> &visited ,vector<int> &ans ,int  node){
    queue<int>q ;
    q.push(node);
    visited[node]= 1 ;
    while(!q.empty()){
        int frontNode =  q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1 ;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   unordered_map<int, set<int>> adjlist ;
   vector<int> ans; 
   unordered_map< int, bool> visited ;
    prepareadjlist(adjlist, edges);
    for(int i = 0 ; i< vertex; i++){
        if(!visited[i]){
            bfs(adjlist, visited, ans, i )
;        }
        }
    return ans ;
}




// DFS 
// recursive approach 
/// implement dfs without using  recursion, instead of it use stack 
void prepareadjlist( unordered_map<int, list<int>> &adjList , vector<vector<int>> &edges){
    for(int i = 0 ; i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
// recursive approach 
void dfs(unordered_map<int,  list<int>> &adjList, unordered_map<int , bool> &visited ,  vector<int> &component , int vertex){
    component.push_back(vertex);
    visited[vertex] = true ;
    for(auto i: adjList[vertex]){
    if(!visited[i]){
        dfs(adjList, visited , component , i);
    }
    }
    
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges )
{
    unordered_map<int , bool> visited ;
    unordered_map<int,  list<int>> adjList ;
    vector<vector<int>> ans ;
    prepareadjlist( adjList , edges);
    for(int  i = 0 ; i<V ; i++){
        if(!visited[i]){
            vector<int> component ; 
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans ; 
}

// learning  from this  question , use STL function mindfully 
// learn how to use double vector 
// learn  syntax 

