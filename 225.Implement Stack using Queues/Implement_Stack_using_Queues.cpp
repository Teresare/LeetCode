//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, 
//peek/pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. 
//You may simulate a queue by using a list or deque (double-ended queue), 
//as long as you use only standard operations of a queue.
//You may assume that all operations are valid 
//(for example, no pop or top operations will be called on an empty stack).

#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		inque.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(!empty()){
			int temp = inque.front();
			inque.pop();
			if(!empty()){
				outque.push(temp);
			}
		}
		inque.swap(outque);
    }

    // Get the top element.
    int top() {
        return inque.back();
    }

    // Return whether the stack is empty.
    bool empty() {
		return inque.empty();
    }
private:
	queue<int> inque;
	queue<int> outque;
};

int main(){
	Stack istack;
	istack.push(1);
	istack.push(2);
	istack.pop();
	int temp = istack.top();
	return 0;
}