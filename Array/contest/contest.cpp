#include<iostream>
using namespace std ;

/// Bfs traversal  
#include<unordered_map>
#include<list>
#include<queue>
#include<set> 
// In this question at this platform we need to print ans in sorted order , it means that if we have two adjacecy nodes at one node than we  first print the small node first , after it the bigger node 
//  so in the adjlist,instead of a list we take a set of nodes 
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


int main(){
    
}