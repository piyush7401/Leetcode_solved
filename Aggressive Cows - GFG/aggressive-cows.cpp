//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:


    bool fun(int mid,vector<int> & stalls,int k){
        
        int n = stalls.size();
        
        int pre = stalls[0];
        
        k--;
        
        int ans = INT_MAX;
        
        for(int i=1;i<n;i++){
            if(stalls[i] - pre >= mid){
                
                int diff = stalls[i] - pre;
                
                ans = min(ans,diff);
                
                pre = stalls[i];
                
                k--;
                
                if(k == 0){
                    return true;    
                }
            }
        }
        
        if(k != 0){
            return false;
        }
        return true;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        
        int start = 1;
        
        int end = stalls[n-1] - stalls[0];
        
        int res = end;
        
        while(start <= end){
            
            int mid = start + (end -start)/2;
            
            //cout<<mid<<"\n";
            
            if(fun(mid,stalls,k) == true){
                res = mid;
                start = mid+1;
            }
            else{
                end = mid -1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends