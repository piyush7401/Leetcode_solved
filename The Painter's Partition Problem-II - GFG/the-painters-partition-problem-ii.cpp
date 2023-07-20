//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    long long fun(long long mid,int arr[],int n){
        
        long long count =0;
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(count + arr[i] < mid){
                count = count + arr[i];
            }
            else if(count + arr[i] == mid){
                count = 0;
                ans++;
            }
            else{
                count = arr[i];
                ans++;
            }
        }
        
        if(count != 0){
            ans++;
        }
        
        return ans;
    }
  
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long start = *max_element(arr,arr+n);
        
        if(n <= k){
            return start;
        }
        
        
        long long end = 0;
        
        for(int i=0;i<n;i++){
            end = end + arr[i];
        }
        
        //cout<<end<<"\n";
        
        long long res = end;
        
        while(start <= end){
            
            long long mid = start + (end-start)/2;
            
            long long x = fun(mid,arr,n);
            
            if(x > k){
                start = mid+1;
            }
            
            else{
                res = mid;
                end = mid -1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends