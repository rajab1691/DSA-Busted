/*
  eg: 1->2->3->4->5
  o/p: 5->4->3->2->1
*/
/*
    1.Iterative approach
    2.Three ptr approach
    3.1st ptr=NULL, 2nd ptr=head 3rd ptr=nowhere
    
   T.C-O(n) & S.C-O(1)  
*/
ListNode* reverseList(ListNode* head) {
	ListNode* prev2 = NULL;
	ListNode* prev1 = head;
	ListNode* curr;

	while (prev1) {
		curr = prev1->next;
		prev1->next = prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	head = prev2;
	return head;
}
/*
    Recursive
    (1->2->3->4)
    1->(2->3->4)
    
*/
ListNode* reverseList(ListNode* head) {
	if (head == NULL or head->next == NULL)
		return head;

	ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}
