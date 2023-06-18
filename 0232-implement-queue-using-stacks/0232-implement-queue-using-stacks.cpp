class MyQueue {
public:

    stack<int> st1;

    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int n = st1.size();

        if(n == 0){
            return -1;
        }

        while( n != 1){
            st2.push(st1.top());

            st1.pop();

            n--;
        }

        int x = st1.top();

        st1.pop();

        int m = st2.size();

        while( m != 0){
            st1.push(st2.top());

            st2.pop();

            m--;
        }

        return x;
    }
    
    int peek() {
        int n = st1.size();

        if(n == 0){
            return -1;
        }

        while( n != 1){
            st2.push(st1.top());

            st1.pop();

            n--;
        }

        int x = st1.top();

        st2.push(st1.top());

        st1.pop();

        int m = st2.size();

        while( m != 0){
            st1.push(st2.top());

            st2.pop();

            m--;
        }

        return x;

    }
    
    bool empty() {
        if(st1.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */