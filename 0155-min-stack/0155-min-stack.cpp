class MinStack {
  // Approach :- Stack Implementation using array/vector
  // Time :- O(1)
  // Space :- O(N)
private:
    vector<int> arr;
    vector<int> minVal;
    
public:
    MinStack() {}
    
    void push(int value) {
        arr.push_back(value);

        if(minVal.empty() || value <= minVal.back()) {
            minVal.push_back(value);
        }
    }
    
    void pop() {
        if(!arr.empty()) {
            if(arr.back() == minVal.back()) {
                minVal.pop_back();
            }
            arr.pop_back();
        }
    }
    
    int top() {
        if(!arr.empty()) {
            return arr.back();
        }
        return INT_MIN;
    }
    
    int getMin() {
        if(!minVal.empty() ) {
            return minVal.back();
        }
        return INT_MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */