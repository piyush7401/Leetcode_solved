//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        
        // First Indegree vector
        
        vector<int> indgree(n,0);
        
        for(int i =0;i<n;i++){
            for(auto it:adj[i]){
                indgree[it]++;
            }
        }
        
        /*cout<<"ok"<<"\n";
        for(int i=0;i<n;i++){
            cout<<indgree[i]<<"\n";
        }*/
        
        queue<int> q;
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(indgree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.empty() != 1){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto child : adj[temp]){
                indgree[child]--;
                
                if(indgree[child] == 0){
                    q.push(child);
                }
            }
        }
        
        
        if(ans.size() == n){
            return 0;
        }
        return 1;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends