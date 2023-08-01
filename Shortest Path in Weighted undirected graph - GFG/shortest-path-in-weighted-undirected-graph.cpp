//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i =0;i<m;i++){
                int x = edges[i][0];
                int y = edges[i][1];
                
                int len = edges[i][2];
                
                adj[x].push_back({y,len});
                
                adj[y].push_back({x,len});
        }
        
        vector<int> dist(n+1,1e9);
        
        vector<int> parent(n+1,0);
        
        for(int i=1;i<n+1;i++){
            parent[i] = i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        q.push({0,1});
        
        dist[1] = 0;
        
        parent[1] = 1;
        
        while(q.empty() != 1){
            pair<int,int> temp = q.top();
            q.pop();
            
            int dis = temp.first;
            
            int node = temp.second;
            
            for(auto it : adj[node]){
                
                int child = it.first;
                
                int child_dis = it.second;
                
                if(dis + child_dis < dist[child]){
                    dist[child] = dis + child_dis;
                    parent[child] = node; 
                    q.push({dist[child],child});
                }
            }
        }
        
        if(dist[n] == 1e9){
            return {-1};
        }
        
        
        vector<int> ans;
        
        int node = n;
        
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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