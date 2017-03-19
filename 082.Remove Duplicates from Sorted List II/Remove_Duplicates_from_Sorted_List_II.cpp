//Given a sorted linked list, delete all nodes that have duplicate numbers, 
//leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

#include <climits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	ListNode dummy(-1);
	bool deleteNode = false;
	ListNode *cur = head;
	ListNode *iter = &dummy;
	while(cur && cur->next){
		if(cur->val == cur->next->val)
			deleteNode = true;
		else {
			if(!deleteNode){
				iter->next = cur;
				iter = iter->next;
			}
			deleteNode = false;
		}
		cur = cur->next;
	}
	if(!deleteNode){
		iter->next = cur;
	}else{
		iter->next = nullptr;
	}
	return dummy.next;
}

//标准答案
ListNode *deleteDuplicates(ListNode *head) {
	if (!head || !head->next) return head;
	ListNode *p = head->next;
	if (head->val == p->val) {
		while (p && head->val == p->val) {
			ListNode *tmp = p;
			p = p->next;
			delete tmp;
		}
		delete head;
		return deleteDuplicates(p);
	} else {
		head->next = deleteDuplicates(head->next);
		return head;
	}
}

//标准答案
ListNode *deleteDuplicates(ListNode *head) {
	if (head == nullptr) return head;
	ListNode dummy(INT_MIN); // 头结点
	dummy.next = head;
	ListNode *prev = &dummy, *cur = head;
	while (cur != nullptr) {
		bool duplicated = false;
		while (cur->next != nullptr && cur->val == cur->next->val) {
			duplicated = true;
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
		}
		if (duplicated) { // 删除重复的最后一个元素
			ListNode *temp = cur;
			cur = cur->next;
			delete temp;
			continue;
		}
		prev->next = cur;
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = cur;
	return dummy.next;
}