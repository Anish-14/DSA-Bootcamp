// https://www.geeksforgeeks.org/dsa/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

// we have to implement a stack which tracks the minimum element also along with the normal properties of stack
// good question
class SpecialStack {
  private:
    stack<int> s;
    int minEle;
    
  public:
    SpecialStack() {
        minEle = -1;
    }
    
    // Add an element to the top of Stack
    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
        }

        // If new number is less than minEle
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }

        else {
            s.push(x);
        }
    }
    
    // Remove the top element from the Stack
    void pop() {
        if (s.empty()) {
            return ;
        }
        
        int top = s.top();
        s.pop();
        
        // Minimum will change, if the minimum element
        // of the stack is being removed.
        if (top < minEle) {
            minEle = 2 * minEle - top;
        }
    }
    
    // Returns top element of the Stack
    int peek() {
        if (s.empty()) {
            return -1;
        }

        int top = s.top();

        // If minEle > top means minEle stores value of top.
        return (minEle > top) ? minEle : top;
    }
    
    // Finds minimum element of Stack
    int getMin() {
        if (s.empty())
            return -1;

        // variable minEle stores the minimum element
        // in the stack.
        return minEle;
    }
};
