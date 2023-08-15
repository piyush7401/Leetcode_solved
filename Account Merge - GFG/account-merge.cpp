//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class disjoint_set{
    public:
    vector<int> parent,rank;
    
    disjoint_set(int n){
        parent.resize(n);
        rank.resize(n,0);
        
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
            parent[ult_u]= ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v]= ult_u;
        }
        else{
            rank[ult_u]++;
            parent[ult_v] = ult_u;
        }
    }
};





class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &mat) {
        
        int n = mat.size();
        
        map<string,int> m;
        
        disjoint_set ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<mat[i].size();j++){
                if(m.find(mat[i][j]) == m.end()){
                    m[mat[i][j]] = i;
                }
                else{
                    ds.union_by_rank(i,m[mat[i][j]]);
                }
            }
        }
        
        vector<string> temp[n];
        
        for(auto it: m){
            string s= it.first;
            int node = it.second;
            
            int ult_node = ds.find_par(node);
            
            temp[ult_node].push_back(s);
        }
        
        for(int i=0;i<n;i++){
            
            sort(temp[i].begin(),temp[i].end());
        }
        
        vector<vector<string>> ans;
        
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<temp[i].size();j++){
        //         cout<<temp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        for(int i=0;i<n;i++){
            if(temp[i].size() == 0){
                continue;
            }
            vector<string> temper;
            temper.push_back(mat[i][0]);
            
            for(int j=0;j<temp[i].size();j++){
                temper.push_back(temp[i][j]);
            }
            
            ans.push_back(temper);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends