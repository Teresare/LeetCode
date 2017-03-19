//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if(nullptr == head) return head;
	ListNode *cur = head, *tmp = head;
	while(tmp && tmp->next){
		tmp = tmp->next;
		if(cur->val != tmp->val){
			cur->next = tmp;
			cur = tmp;
		}
	}
	cur->next = nullptr;
	return head;
}

//标准答案
static void recur(ListNode *prev, ListNode *cur) {
	if (cur == nullptr) return;
	if (prev->val == cur->val) { // 删除 head
		prev->next = cur->next;
		delete cur;
		recur(prev, prev->next);
	} else {
		recur(prev->next, cur->next);
	}
}
ListNode *deleteDuplicates(ListNode *head) {
	if (!head) return head;
	ListNode dummy(head->val + 1); // 值只要跟 head 不同即可
	dummy.next = head;
	recur(&dummy, head);
	return dummy.next;
}

//标准答案
ListNode *deleteDuplicates(ListNode *head) {
	if (head == nullptr) return nullptr;
	for (ListNode *prev = head, *cur = head->next; cur; cur = cur->next) {
		if (prev->val == cur->val) {
			prev->next = cur->next;
			delete cur;
		} else {
			prev = cur;
		}
	}
	return head;
}