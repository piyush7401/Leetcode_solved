//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        map<int,int> m;
        
        int prefix = 0;
        
        int j =0;
        
        m[prefix]++;
        
        int count =0;
        
        while(j < n){
            prefix = prefix + arr[j];
            
            if(m.find(prefix - k) != m.end()){
                count = count + m[prefix - k];
            }
            
            m[prefix]++;
            
            j++;
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends