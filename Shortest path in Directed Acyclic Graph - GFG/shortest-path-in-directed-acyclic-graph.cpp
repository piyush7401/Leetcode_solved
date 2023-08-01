//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void topo(int i,vector<pair<int,int>> adj[],stack<int> & st,vector<int> & visit){
        visit[i] = 1;
        
        for(auto child : adj[i]){
            if(visit[child.first] == 0){
                topo(child.first,adj,st,visit);
            }
        }
        
        st.push(i);
    }
  
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        
        vector<pair<int,int>> adj[n];
        
        for(int i =0;i<m;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            
            int len = edges[i][2];
            
            adj[x].push_back({y,len});
        }
        
        
        // start topo sort
        
        vector<int> visit(n,0);
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(visit[i] == 0){
                topo(i,adj,st,visit);
            }
        }
        
        vector<int> dist(n,1e9);
        
        dist[0] = 0;
        
        while(st.empty() != 1){
            int node = st.top();
            st.pop();
            
            for(auto child : adj[node]){
                int child_node = child.first;
                
                int child_dis = child.second;
                
                if(child_dis + dist[node] < dist[child_node]){
                    
                   dist[child_node] = child_dis + dist[node]; 
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends