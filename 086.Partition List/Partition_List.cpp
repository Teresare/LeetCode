//Partition List
//
//Given a linked list and a value x, partition it such that all nodes less than x come 
//before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode newHead(-1);
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *pre = &newHead;
	ListNode *cur = &dummy;
	while(cur->next){
		int value = cur->next->val;
		if(value < x){
			pre->next = cur->next;
			pre = cur->next;
			cur->next = cur->next->next;
		}
		else{
			cur = cur->next;
		}
	}
	pre->next = dummy.next;
	return newHead.next;
}

ListNode* partition(ListNode* head, int x) {
	ListNode leftDummy(-1);
	ListNode rightDummy(-1);
	ListNode *leftCur = &leftDummy;
	ListNode *rightCur = &rightDummy;
	for(ListNode *cur = head; cur; cur = cur->next){
		if(cur->val < x){
			leftCur->next = cur;
			leftCur = cur;
		}
		else{
			rightCur->next = cur;
			rightCur = cur;
		}
	}
	leftCur->next = rightDummy.next;
	rightCur->next = nullptr;
}