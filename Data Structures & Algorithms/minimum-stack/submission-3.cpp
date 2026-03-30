class MinStack {
public:
    vector<int> vec;
    int len = 0;
    vector<int> minvec;
    MinStack() {
        
    }
    
    void push(int val) {
        vec.push_back(val);
        if (len==0) {
            minvec.push_back(val);
        }else {
            if ( val >= minvec[len-1]) minvec.push_back(minvec[len-1]);
            else minvec.push_back(val);
        }
        len++;
    }

    void pop() {
        vec.pop_back();
        minvec.pop_back();
        len--;
    }
    
    int top() {
        return vec[len-1];
    }
    
    int getMin() {
        return minvec[len-1];
    }
};