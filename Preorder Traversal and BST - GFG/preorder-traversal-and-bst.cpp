//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int pre[], int n) {
        // code here
        stack<int> s;
        
        int root = INT_MIN;
         
        for (int i=0; i<n; i++)
        {
            if (pre[i] < root)
                return false;
                
            while (!s.empty() && s.top()<pre[i])
            {
                root = s.top();
                s.pop();
            }
            
            s.push(pre[i]);
            
        }
        
        return true;
         
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends