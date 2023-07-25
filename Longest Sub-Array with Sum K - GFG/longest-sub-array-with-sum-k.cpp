//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        map<int,int> m;
        
        int prefix = 0;
        
        int j =0;
        
        int count =INT_MIN;
        
        m[prefix] = -1;
        
        while(j < n){
            prefix = prefix + arr[j];
            
            if(m.find(prefix - k) != m.end()){
                count = max(count,j- m[prefix - k]);
            }
            
            if(m.find(prefix) == m.end()){
                m[prefix] = j;
            }
            
            j++;
        }
        
        if(count ==INT_MIN){
            return 0;
        }
        
        return count;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends