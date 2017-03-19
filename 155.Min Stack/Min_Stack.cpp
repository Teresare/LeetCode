//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.

#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x) {
		int minEle;
		if(!min.empty()) {
			minEle = getMin();
			if(minEle > x) min.push(x);
			else min.push(minEle);
		}
		else min.push(x);
		s.push(x);
    }

    void pop() {
        s.pop();
		min.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
private:
	stack<int> s;
	stack<int> min;
};