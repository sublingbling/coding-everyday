class Queue {
    stack<int> _in, _out;
public:
    // Push element x to the back of queue.
    void push(int x) {
        _in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        _out.pop();
    }

    // Get the front element.
    int peek(void) {
        assert(!empty());
        if (_out.empty()) {
            while (!_in.empty()) {
                _out.push(_in.top());
                _in.pop();
            }
        }
        return _out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return _in.empty() && _out.empty();
    }
};
