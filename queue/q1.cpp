// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            return;
        }
        int top = s.top();
        s.pop();

        push(x);

        s.push(top);
    }
    
    int pop() {
        int top = s.top();
        s.pop();

        return top;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};
