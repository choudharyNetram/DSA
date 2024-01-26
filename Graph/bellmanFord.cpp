// dijkstra's algorithm doesn't work for negative weight edge graph

// in bellman ford algorithm we have to apply this formula by n-1 times 
// if(d[u]+weight < d[v]){ d[v] = d[u]+weight} 
// then we will apply this condition for one  more time 
// if the distance is reduced than negative cycle present 


#include <bits/stdc++.h> 
using namespace std ; 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1, 1e9) ; // this is a vector that stores the value of distance from the source node 
    dist[src] = 0 ; 

    for(int i = 0 ;i<n-1 ;i++){
        for(int j = 0;j<edges.size() ; j++){
            int u = edges[j][0] ; 
            int v = edges[j][1] ; 
            int w = edges[j][2] ; 
            if(dist[u] != 1e9 && dist[u]+ w < dist[v] ){
                dist[v]   = dist[u]+w ; 
            }
        }
    }
    // checking the negative cycle 
    bool flag = 0 ; 
    for(int j = 0;j<edges.size() ; j++){
        int u = edges[j][0] ; 
        int v = edges[j][1] ; 
        int w = edges[j][2] ; 
        if(dist[u] != 1e9 && dist[u]+ w < dist[v] ){
            dist[v]   = dist[u]+w ; 
            flag = 1 ; 
        }
    } 
    if(flag == 0){
        return dist[dest] ;
    }
    else {
        return -1 ; /// this means there is negative cycle
    }

}