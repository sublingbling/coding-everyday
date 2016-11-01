class Queue {
private:
    stack<int> po;
    stack<int> pu;
public:
    // Push element x to the back of queue.
    void push(int x) {
        pu.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        if(!po.empty()) po.pop();
    }

    // Get the front element.
    int peek(void) {
        if(po.empty()){
            while(!pu.empty()){
                po.push(pu.top());
                pu.pop();
            }  
        }
        return po.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return po.empty()&&pu.empty();
    }
};
