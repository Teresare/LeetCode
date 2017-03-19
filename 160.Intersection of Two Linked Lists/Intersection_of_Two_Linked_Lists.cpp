//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists:
//
//A:          a1 ¡ú a2
//                   ¨K
//                     c1 ¡ú c2 ¡ú c3
//                   ¨J            
//B:     b1 ¡ú b2 ¡ú b3
//begin to intersect at node c1.
//
//
//Notes:
//
//If the two linked lists have no intersection at all, return null.
//The linked lists must retain their original structure after the function returns.
//You may assume there are no cycles anywhere in the entire linked structure.
//Your code should preferably run in O(n) time and use only O(1) memory.

#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	stack<ListNode *> stackA, stackB;
	while(headA){
		stackA.push(headA);
		headA = headA->next;
	}
	while(headB){
		stackB.push(headB);
		headB = headB->next;
	}
	ListNode *result = nullptr;
	while(!stackA.empty() && !stackB.empty() && stackA.top() == stackB.top()){
		result = stackA.top();
		stackA.pop();
		stackB.pop();
	}
	return result;
}