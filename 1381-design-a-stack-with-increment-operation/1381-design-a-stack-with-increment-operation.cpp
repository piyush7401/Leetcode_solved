class CustomStack {
public:
    
    stack<int> st;
    
    int maxi = 0;
    
    stack<int> temp;
    
    stack<int> tempy;
    
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxi){
            st.push(x);
        }
        
    }
    
    int pop() {
        if(st.empty() != 1){
            int x = st.top();
            st.pop();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        while(st.size() > k){
            tempy.push(st.top());
            st.pop();
        }
        
        while(st.empty() != 1){
            temp.push(st.top() + val);
            st.pop();
        }
        
        while(temp.empty() != 1){
            st.push(temp.top());
            temp.pop();
        }
        
        while(tempy.empty() != 1){
            st.push(tempy.top());
            tempy.pop();
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */