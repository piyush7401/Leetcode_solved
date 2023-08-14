//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disjoint_set{
    
    public:
    vector<int> rank,parent;
    
    disjoint_set(int n){
        rank.resize(n,0);
        parent.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int find_par(int u){
        if(u == parent[u]){
            return u;
        }
        else{
            return parent[u] = find_par(parent[u]);
        }
    }
    
    void union_by_rank(int u,int v){
        int ult_u = find_par(u);
        int ult_v = find_par(v);
        
        if(ult_u == ult_v){
            return;
        }
        else if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else{
            rank[ult_u]++;
            parent[ult_v] = ult_u;
        }
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        disjoint_set ds(n);
        int count =0;
        
        for(int i=0;i<edge.size();i++){
            int u = edge[i][0];
            int v = edge[i][1];
            
            if(ds.find_par(u) == ds.find_par(v)){
                count++;
            }
            ds.union_by_rank(u,v);
        }
        
        int req = 0;
        
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                req++;
            }
        }
        
        // cout<<count<<req<<"\n";
        if(count >= req-1){
            return min(count,req-1);
        }
        return -1;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends