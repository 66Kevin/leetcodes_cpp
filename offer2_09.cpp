class CQueue {
public:
    vector<int> stack1; //全局变量，可以被任何函数访问
    vector<int> stack2;
    CQueue() {}
    
    void appendTail(int value) {
        stack1.emplace_back(value);
    }
    
    int deleteHead() {
        if(stack2.empty()){
            if(stack1.empty()){
                return -1;
            }
            while(!stack1.empty()){
                int stack1_top = stack1.back();
                stack2.emplace_back(stack1_top);
                stack1.pop_back();
            }
        }
        int stack2_top = stack2.back();
        stack2.pop_back();
        return stack2_top;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
