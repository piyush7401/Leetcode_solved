class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    
    int i =1;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int x = 0;
        
        if(st.empty() == 1){
            x = 1;
        }
        else{
            if(st.top().first > price){
                x = 1;
            }
            else if(st.top().first <= price){
            
                while(st.empty() != 1 && st.top().first <= price){
                    st.pop();
                }
                
                if(st.empty() == 1){
                    x = i;
                }
                
                else if(st.top().first > price){
                    x = i - st.top().second;
                    cout<<x<<"\n";
                }
            } 
        }
        
        st.push({price,i});
        
        cout<<price<<" "<<i<<"\n";
        
        i++;
        
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */