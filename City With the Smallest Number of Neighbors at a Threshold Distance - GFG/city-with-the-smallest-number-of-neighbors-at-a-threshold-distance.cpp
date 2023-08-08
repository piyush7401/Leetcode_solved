//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int dist) {
        
        vector<vector<int>> adj(n,vector<int> (n,-1));
        
        for(int i=0;i<m;i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int len = edges[i][2];
            
            adj[x][y] = len;
            adj[y][x] = len;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    adj[i][j] = 0;
                }
                else if(adj[i][j] == -1){
                    adj[i][j] = 1e9;
                }
            }
        }
        
        
        for(int temp =0;temp < n;temp++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][temp] + adj[temp][j]);        
                }
            }
        }
        
        int ans = INT_MAX;
        int index = 0;
        for(int i=0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(adj[i][j] <= dist){
                    count++;
                }     
            }
            if(count <= ans){
                ans = count;
                index = i;
            }
        }
        
        return index;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends