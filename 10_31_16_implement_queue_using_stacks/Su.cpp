class Queue {
public:
    stack<int> s1;
    int idx=0;
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        idx++;
    }

    // Get the front element.
    int peek(void) {
        stack<int> tmp;
        while(s1.size()-idx){
            tmp.push(s1.top());
            s1.pop();
        }
        int result=tmp.top();
        while(s1.size()) {
            s1.pop();
            idx=0;
        }
        while(tmp.size()){
            s1.push(tmp.top());
            tmp.pop();
        }
        return result;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.size()==idx;
    }
};
