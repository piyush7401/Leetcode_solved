//{ Driver Code Starts
// Initial Template for C++

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


bool issafe(int x,int y,vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    
    if(x < 0 || y < 0 || x >= n || y >= m){
        return false;
    }
    if(mat[x][y] == 0){
        return false;
    }
    return true;
}

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &mat) {
        
        vector<int> ans;
        disjoint_set ds(n*m);
        vector<vector<int>> grid(n,vector<int> (m,0));
        for(int i=0;i<mat.size();i++){
            int x = mat[i][0];
            int y = mat[i][1];
            
            grid[x][y] = 1;
            
            if(issafe(x+1,y,grid) == true){
                ds.union_by_rank(m*x + y,m*(x+1)+y);
            }
            if(issafe(x-1,y,grid) == true){
                ds.union_by_rank(m*x + y,m*(x-1)+y);
            }
            if(issafe(x,y+1,grid) == true){
                ds.union_by_rank(m*x + y,m*x + y+1);
            }
            if(issafe(x,y-1,grid) == true){
                ds.union_by_rank(m*x + y,m*x + y-1);
            }
            
            int count =0;
            
            for(int i=0;i<n*m;i++){
                int x = i/m;
                int y = i%m;
                if( i == ds.parent[i] && grid[x][y] == 1){
                    // cout<<x<<" "<<y<<"\n";
                    count++;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends