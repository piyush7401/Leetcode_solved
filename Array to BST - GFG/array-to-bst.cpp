//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void fun(vector<int> & nums,vector<int> & pre,int start,int end){
        if(start > end){
            return;
        }
        else{
            int mid = (start+end)/2;
            
            pre.push_back(nums[mid]);
            
            fun(nums,pre,start,mid-1);
            
            fun(nums,pre,mid+1,end);
        }
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        
        vector<int> pre;
        
        int start =0;
        
        int end = nums.size() - 1;
        
        fun(nums,pre,start,end);
        
        return pre;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends