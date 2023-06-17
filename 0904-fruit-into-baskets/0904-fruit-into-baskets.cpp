class Solution {
public:
    int totalFruit(vector<int>& arr) {
        
        int i =0;
        
        int n = arr.size();
        
        map<int,int> m;
        
        int j =0;
        
        int count = 0;
        
        while(j < n){
            m[arr[j]]++;
            
            if(m.size() < 2){
                
                int sum =0;
                
                for(auto it : m){
                    sum = sum + it.second;
                }
                
                count = max(sum,count);
                
                j++;
            }
            
            else if(m.size() == 2){
                int sum =0;
                
                for(auto it : m){
                    sum = sum + it.second;
                }
                
                count = max(sum,count);
                
                j++;
            }
            
            else if(m.size() > 2){
                
                while(m.size() > 2){
                    m[arr[i]]--;
                    
                    if(m[arr[i]] == 0){
                        m.erase(arr[i]);
                    }
                    
                    i++;
                }
                
                if(m.size() == 2){
                    int sum =0;
                    
                    for(auto it : m){
                        sum = sum + it.second;
                    }
                    
                    count = max(count,sum);
                }
                
                j++;
            }
        }
        
        return count;
    }
};