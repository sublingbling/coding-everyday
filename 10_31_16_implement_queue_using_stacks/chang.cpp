class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        stack1.push(element);
    }
    
    void adjust() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }
    }
    
    int pop() {
        adjust();
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

    int top() {
        adjust();
        return stack2.top();
    }
};
