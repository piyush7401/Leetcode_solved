//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool isvalid(int x,int y,vector<vector<int>>& heights){
        
        int n = heights.size();
        
        int m = heights[0].size();
        
        if( x < 0 || y < 0 | x >= n || y >= m){
            return false;
        }
        return true;
    }
  
    int MinimumEffort(vector<vector<int>>& heights) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        
        q.push({0,{0,0}});
        
        int n = heights.size();
        
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        dist[0][0] = 0;
        
        while(q.empty() != 1){
            int len = q.top().first;
            
            int x = q.top().second.first;
            
            int y = q.top().second.second;
            
            if(x == n-1 && y == m-1){
                return len;
            }
            
            q.pop();
            
            if(isvalid(x+1,y,heights) == true){
                int diff = abs(heights[x+1][y] - heights[x][y]);
                
                diff = max(len,diff);
                
                if(diff < dist[x+1][y]){
                    dist[x+1][y] = diff;
                    
                    q.push({diff,{x+1,y}});
                }
            }
            
            if(isvalid(x-1,y,heights) == true){
                int diff = abs(heights[x-1][y] - heights[x][y]);
                
                diff = max(len,diff);
                
                if(diff < dist[x-1][y]){
                    dist[x-1][y] = diff;
                    
                    q.push({diff,{x-1,y}});
                }
            }
            
            if(isvalid(x,y+1,heights) == true){
                int diff = abs(heights[x][y+1] - heights[x][y]);
                
                diff = max(len,diff);
                
                if(diff < dist[x][y+1]){
                    dist[x][y+1] = diff;
                    
                    q.push({diff,{x,y+1}});
                }
            }
            
            if(isvalid(x,y-1,heights) == true){
                int diff = abs(heights[x][y-1] - heights[x][y]);
                
                diff = max(len,diff);
                
                if(diff < dist[x][y-1]){
                    dist[x][y-1] = diff;
                    
                    q.push({diff,{x,y-1}});
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return dist[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends