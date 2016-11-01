class Queue {
public:
    stack<int> FIFO;
    stack<int> FILO;
    
    // Push element x to the back of queue.
    void push(int x) {
        FIFO.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
        if (!FILO.empty()) FILO.pop();
    }

    // Get the front element.
    int peek(void) {
        if (FILO.empty())
        {
            while (!FIFO.empty())
            {
                FILO.push(FIFO.top());
                FIFO.pop();
            }
        }
        return FILO.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return FIFO.empty() && FILO.empty();
    }
};
