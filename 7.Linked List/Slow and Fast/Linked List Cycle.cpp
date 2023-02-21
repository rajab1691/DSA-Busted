/*
  1. We can use hashmap - push all elements into hashset/map if we found element again then return true - SPACE- O(N)
  2. We slow and fast ptr approach - if there is cycle then slow and fast ptr will surely meet - CONST SPACE and Linear TIME
*/

bool hasCycle(ListNode *head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;
            }
        }
        return false;
}
