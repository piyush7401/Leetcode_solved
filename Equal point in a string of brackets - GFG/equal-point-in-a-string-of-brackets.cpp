//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int findIndex(string s) {
        // Your code goes here
        
        int n = s.size();
        
        vector<int> open(n,0);
        
        if(s[0] == '('){
            open[0] = 1;
        }
        
        vector<int> close(n,0);
        
        for(int i=1;i<n;i++){
        
            if(s[i] == '('){
                open[i] = open[i-1] + 1;
            }
            else{
                open[i] = open[i-1];
            }
        }
        
        if(s[n-1] == ')'){
            close[n-1] = 1;
        }
        for(int i = n-2;i>=0;i--){
        
            if(s[i] == ')'){
                close[i] = close[i+1] + 1;
            }
            else{
                close[i] = close[i+1];
            }
        }
        
        
        /*int start = 0;
        
        int end = n-1;
        
        while(start <= end){
            
            int mid = start + (end -start)/2;
            
            if(open[mid] == close[mid]){
                return mid -1;
            }
            
            else if(open[mid] > close[mid]){
                end = mid -1;
            }
            
            else{
                start = mid + 1;
            }
        }*/
        
        for(int i=0;i<n;i++){
            
            //cout<<open[i]<<" "<<close[i]<<"\n";
            
            
            if(open[n-1] == 0){
                return n;
            }
        
            if(open[i] == close[i+1]){
                
                return i+1;
            }
        }
        
        
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.findIndex(s)<<endl;
	}
}
// } Driver Code Ends