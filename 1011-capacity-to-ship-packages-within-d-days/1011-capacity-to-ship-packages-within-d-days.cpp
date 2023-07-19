class Solution {
public:
    
    int fun(int mid,vector<int> & weight){
        
        int n = weight.size();
        
        int ans =1;
        
        int count =0;
        
        for(int i =0;i<n;i++){
            if(count+weight[i] > mid){
                ans++;
                count = weight[i];
            }
            else{
                count = count + weight[i];
            }
        }
        
        //cout<<ans<<" "<<mid<<"\n";
        
        return ans;
    }
    
    
    int shipWithinDays(vector<int>& weight, int day) {
        
        int start = *max_element(weight.begin(),weight.end());
        
        int end = accumulate(weight.begin(),weight.end(),0);
        
        int res = end;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            int ans = fun(mid,weight); 
            
            if(ans > day){
                start = mid +1;
            }
            
            else{
                res = mid;
                end = mid -1;
            }
        }
        
        return res;
    }
};