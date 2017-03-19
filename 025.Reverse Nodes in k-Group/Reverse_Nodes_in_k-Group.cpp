//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr){}
};

ListNode *reverseKGroup(ListNode *head, int k) {
	if (head == nullptr || head->next == nullptr || k < 2)
		return head;
	ListNode *next_group = head;
	for (int i = 0; i < k; ++i) {
		if (next_group)
			next_group = next_group->next;
		else
			return head;
	}
	ListNode *new_next_group = reverseKGroup(next_group, k);
	ListNode *prev = nullptr, *cur = head;
	while (cur != next_group) {
		ListNode *next = cur->next;
		cur->next = prev ? prev : new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
	if (head == nullptr || head->next == nullptr || k < 2) return head;
	ListNode dummy(-1);
	dummy.next = head;
	for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
		for (int i = 1; i < k && end; i++)
			end = end->next;
		if (end == nullptr) break;
		prev = reverse(prev, prev->next, end);
	}
	return dummy.next;
}

ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
	ListNode *end_next = end->next;
	for (ListNode *p = begin, *cur = p->next, *next = cur->next;
		cur != end_next;
		p = cur, cur = next, next = next ? next->next : nullptr) {
			cur->next = p;
	}
	begin->next = end_next;
	prev->next = end;
	return begin;
}

//int main(){
//	ListNode first(1), second(2), third(3), forth(4), fifth(5);
//	first.next = &second;
//	second.next = &third;
//	third.next = &forth;
//	forth.next = &fifth;
//	int num = 2;
//	ListNode *head = reverseKGroup(&first, num);
//	return 0;
//}