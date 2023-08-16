//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool issafe(vector<vector<int>> m, int n,int x,int y,vector<vector<int>>& visit){
        if(x < 0 || y < 0 || x >= n || y >= n){
            return false;
        }
        else if(m[x][y] == 0 || visit[x][y] == 1){
            return false;
        }
        else{
            return true;
        }
    }
    
    void fun(vector<vector<int>> m, int n,int x,int y,vector<vector<int>>& visit,string temp,vector<string>& ans){
        
        if(x == n-1 && y == n-1){
            ans.push_back(temp);
            return;
        }
        if(issafe(m,n,x,y,visit) == false){
            return;
        }
        visit[x][y] = 1;

        
        if(issafe(m,n,x+1,y,visit) == true){
            temp.push_back('D');
            fun(m,n,x+1,y,visit,temp,ans);
            temp.pop_back();
        }
        if(issafe(m,n,x-1,y,visit) == true){
            temp.push_back('U');
            fun(m,n,x-1,y,visit,temp,ans);
            temp.pop_back();
        }
        if(issafe(m,n,x,y+1,visit) == true){
            temp.push_back('R');
            fun(m,n,x,y+1,visit,temp,ans);
            temp.pop_back();
        }
        if(issafe(m,n,x,y-1,visit) == true){
            temp.push_back('L');
            fun(m,n,x,y-1,visit,temp,ans);
            temp.pop_back();
        }
        visit[x][y] = 0;
        
        // return ans;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visit(n,vector<int> (n,0));
        string temp;
        vector<string> ans;
        fun(m,n,0,0,visit,temp,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends