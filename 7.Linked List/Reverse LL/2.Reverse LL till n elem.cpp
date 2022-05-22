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
