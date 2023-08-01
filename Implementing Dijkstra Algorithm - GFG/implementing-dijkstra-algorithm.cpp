//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<pair<int,int>> edge[n];
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<adj[i].size();j++){
                int x = adj[i][j][0];
            
                int len = adj[i][j][1];
            
                edge[i].push_back({x,len});   
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        q.push({0,s});
        
        vector<int> dist(n,INT_MAX);
        
        dist[s] = 0;
        
        while(q.empty() != 1){
            pair<int,int> temp = q.top();
            
            q.pop();
            
            int dis = temp.first;
            
            int node = temp.second;
            
            for(auto child : edge[node]){
                
                int child_node = child.first;
                
                int child_dis = child.second;
                
                if(child_dis + dis < dist[child_node]){
                    dist[child_node] = child_dis + dis;
                    
                    q.push({dist[child_node],child_node});
                }
            }
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends