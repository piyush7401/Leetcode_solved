//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[n];
	    
	    for(auto it : pre){
	        int x = it.first;
	        int y = it.second;
	        
	        adj[x].push_back(y);
	    }
	    
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
        
        //cout<<ans.size()<<"\n";
        
        if(ans.size() == n){
            return 1;
        }
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends