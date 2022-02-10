/*
  1. take help of two ptr and remove duplicates
*/

class Solution {
  public:
    ListNode * deleteDuplicates(ListNode * head) {

      if (head == NULL or head -> next == NULL) {
        return head;
      }
      
      ListNode * prev = head;
      ListNode * curr = head -> next;

      while (curr) {

        if (prev -> val == curr -> val) {
          prev -> next = curr -> next;
          curr = prev -> next;
        } else {
          prev = prev -> next;
          curr = curr -> next;
        }
      }
      return head;
    }
};
