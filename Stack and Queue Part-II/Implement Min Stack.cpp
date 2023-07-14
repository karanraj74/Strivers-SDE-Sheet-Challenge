class MinStack {
public:
    vector<int>v;
    int t;
    MinStack() {
        t=-1;
    }
    
    void push(int val) {
       t++;
       v.push_back(val);
    }
    
    void pop() {
        t--;
        v.pop_back();
    }
    
    int top() {
        return v[t];
    }
    
    int getMin() {
        return *min_element(v.begin(),v.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
