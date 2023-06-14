//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool check(vector<int> & color,int i, vector<int> adj[], int n){
	    
	    color[i] = 0;
	    
	    queue<int> q;
	    
	    q.push(i);
	    
	    while(q.empty() != 1){
	        int temp = q.front();
	        q.pop();
	        for(auto child : adj[temp]){
	           if(color[child] == -1){
                  color[child] = !color[temp];
                     q.push(child);
                }
                else if(color[child] != -1 && color[child] == color[temp]){
	                 return false;
	            }
	        }
	    }
	    
	    /*for(int i=0;i<n;i++){
	        cout<<color[i]<<"\n";
	    }*/
	    
	    return true;
    }


	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    
	    vector<int> color(n,-1);
	    
	    for(int i=0;i<n;i++){
	        if(color[i] == -1){
	            if(check(color,i,adj,n) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends