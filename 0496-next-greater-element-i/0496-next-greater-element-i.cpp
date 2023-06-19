class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        
        int n = nums2.size();
        
        vector<int> ans;
        
        for(int i = n-1;i>=0;i--){
            if(st.empty() == 1){
                ans.push_back(-1);
            }
            else{
                if(st.top() < nums2[i]){
                    while(st.empty() != 1 && st.top() < nums2[i]){
                        st.pop();
                    }
                    
                    if(st.empty() == 1){
                        ans.push_back(-1);
                    }
                    
                    else if(st.top() > nums2[i]){
                        ans.push_back(st.top());
                    }
                }
                
                else if(st.top() > nums2[i]){
                    ans.push_back(st.top());                        
                }
            }
            
            st.push(nums2[i]);
        }
        
        reverse(ans.begin(),ans.end());
        
        vector<int> actual_ans;
        
        int m = nums1.size();
        
        //cout<<m<<" "<<n<<"\n";
        
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                //cout<<i<<" "<<j<<"\n";
                if(nums1[i] == nums2[j]){
                    actual_ans.push_back(ans[j]);
                    break;
                }
            }
        }
        
        return actual_ans;
    }
};