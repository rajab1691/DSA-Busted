/*
  Recursive
*/
ListNode* succ = NULL;
//Reverse from given pos to pos+n
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

	ListNode* newHead = revN(head, right - left + 1);
}
