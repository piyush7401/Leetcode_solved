class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        
        for(int i =0;i<s.size();i++){
            if(s[i] == ')'){
                if(st.empty() == 1){
                    return false;
                }
                else if(st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
            
            else if(s[i] == '('){
                st.push(s[i]);
            }
            
            else if(s[i] == '['){
                st.push(s[i]);
            }
            
            else if(s[i] == '{'){
                st.push(s[i]);
            }
            
            if(s[i] == ']'){
                if(st.empty() == 1){
                    return false;
                }
                else if(st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(']');
                }
            }
            
            if(s[i] == '}'){
                if(st.empty() == 1){
                    return false;
                }
                else if(st.top() == '{'){
                    st.pop();
                }
                else{
                    st.push('}');
                }
            }
        }
        
        if(st.empty() == 1){
            return true;
        }
        return false;
    }
};