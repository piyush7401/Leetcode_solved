//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    int fun(int mid,int arr[],int m,int n){
        
        int count =0;
        
        int ans = INT_MIN;
    
        for(int i=0;i<n;i++){
            
            if(count + arr[i] < mid){
                count = count + arr[i];
                
                ans = max(ans,count);
            } 
            
            else if(count + arr[i] == mid){
                m--;
                
                ans = max(ans,count + arr[i]);
                
                count = 0;
            }
            
            else{
                
                m--;
                
                ans = max(ans,count);
                
                count = arr[i];
            }
        }
        
        if(count != 0){
            m--;
        }
        
        return m;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        
        if(m > n){
            return -1;
        }
        
        
        int start = *max_element(arr,arr+n);
        
        int end = accumulate(arr,arr+n,0);
        
        int res = end;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            //cout<<mid<<"\n";
            
            if(fun(mid,arr,m,n) > 0){
                res = mid;
                end = mid -1;
            }
            
            else if(fun(mid,arr,m,n) == 0){
                res = mid;
                end = mid -1;
            }
            
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends