/*
  Recursive
*/
ListNode* succ = NULL;

ListNode* revN(ListNode* head, int n) {

	if (n == 1) {
		succ = head->next;
		return head;
	}

	ListNode* newHead = revN(head->next, n - 1);
	head->next->next = head;
	head->next = succ;
	return newHead;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {

	if (left == 1) {
		return revN(head, right);
	}
	ListNode* curr = head;
	ListNode* dummy = new ListNode(0);
	ListNode* ptr = dummy;
	//copy till left-1 elem
	for (int i = 1; i < left; i++) {
		ListNode* node = new ListNode(curr->val);
		ptr->next = node;
		ptr = ptr->next;
		curr = curr->next;
	}
	//reverse from left to next (n) elem where n=r-l+1
	ptr->next = revN(curr, right - left + 1);

	return dummy->next;
}
