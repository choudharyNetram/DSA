//

// the below is the correct solution 
/// 1st code: 
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool chk(vector<int> &color,int node,int c,vector<int> adj[])
    {
        for(auto it:adj[node])
        {
            if(c==color[it])
            return false;
        }
        return true;
    }
    bool f(int node,int n,vector<int> adj[],int m,vector<int> &color)
    {
        if(node==n)
        return true;
        for(int i=1;i<=m;i++)
        {
            if(chk(color,node,i,adj))
            {
                color[node]=i;
                if(f(node+1,n,adj,m,color))
                return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> adj[101];
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                if(graph[i][j]){
                    adj[i].push_back(j);

                }
            }
        }
        vector<int> color(n,0);
        return f(0,n,adj,m,color);
    }
};

/////////// second code ;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
      for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
          return false;
        }
      }
      return true;
    }
    bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
      if (node == N) {
        return true;
      }
    
      for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
          color[node] = i;
          if (solve(node + 1, color, m, N, graph)) return true;
          color[node] = 0;
        }
    
      }
      return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
       int color[n] = {
            0
          };
          if (solve(0, color, m, n, graph)) return true;
          return false;
    }


/*the below method is not  working totally, first mistake is that after backtrack visited become 0, 0. but we don't want  that 
and second thing is that how to count the number of nodes that is visited or not. 
because count become 1 after backtrack 


*/
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with the same colour.
    void printVisited(vector<pair<bool, int>>& visited) {
        int i = 0 ; 
        for (auto node : visited) {
            cout << "Visited: "<< i<<" " <<(node.first ? "true" : "false") << ", Color: " << node.second << endl;
            i++; 
        }
    }

    bool isSafe(int vertex, int color, vector<pair<bool, int>>& visited, unordered_map<int, list<int>>& adj) {
        for (auto nbr : adj[vertex]) {
            if (visited[nbr].first && visited[nbr].second == color) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<pair<bool, int>>& visited, unordered_map<int, list<int>>& adj, int vertex, int m,int n,  int count) {
        //printVisited(visited) ; 
        for (int i = 0; i < m; i++) {
            if (isSafe(vertex, i, visited, adj)) { 
                visited[vertex].first = true;
                visited[vertex].second = i;
               // printVisited(visited) ; 
                count++; 
                cout<<"count "<<count<<endl; 
                if(count == n){
                     return true  ; 
                 }
                for (auto nbr : adj[vertex]) {
                    if (!visited[nbr].first) {
                        return solve(visited, adj, nbr, m, n, count) ; 
                    }
                }
                visited[vertex].first = false;
                visited[vertex].second = -1;
                count-- ; 
            }
        }
        return false ; 
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<pair<bool, int>> visited(n + 1, { false, -1 });
        unordered_map<int, list<int>> adj;
        //vector<bool>visi(n+1, false ) ; 
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (graph[i][j]) {
                    adj[i + 1].push_back(j + 1);
                    //adj[j + 1].push_back(i + 1);
                }
            }
        }
        int count =  0 ; 
        for (int i =1 ; i <= n; i++) {
            if (!visited[i].first) {
                if (!solve(visited, adj, i, m,n,   count)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example graph
    bool graph[101][101] = {{false}};
    int n = 14; // Number of nodes
    int m = 9; // Number of colors

    // Example edges
    int edges[][2] = {{1, 8}, {12, 11}, {3, 0}, {11, 4}, {11, 3}};
    int numEdges = 5;
    // if in edge matrix if there is written a edge between [0,1] it means ther is edge between [1,2]
    // Create the graph
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = graph[v][u] = true;
    }

    // Call the graph coloring function
    bool result = solution.graphColoring(graph, m, n);

    // Print the result
    cout << "The graph can be colored with at most " << m << " colors: " << result << endl;

    return 0;
}




