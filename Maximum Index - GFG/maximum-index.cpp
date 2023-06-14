//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        
        vector<pair<int,int>> index;
        
        for(int i=0;i<n;i++){
            index.push_back({a[i],i});
            
        }
        
        sort(index.begin(),index.end());
        
        
        /*for(int i=0;i<n;i++){
            cout<<index[i].first<<" "<<index[i].second<<"\n";
        }*/
        
        
        int i =0;
        
        int j = 1;
        
        int diff = 0;
        
        while(i < n && j < n){
            if(index[i].second > index[j].second){
                i = j;
                j++;
            }
            else{
                //cout<<j-i<<"\n";
                //cout<<index[j].second - index[i].second<<"\n";
                diff = max(diff,index[j].second - index[i].second);
                j++;
            }
            
        }
        
        return diff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends