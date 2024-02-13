class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        
        // Create a dummy node to handle edge cases when removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until the fast pointer reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        
        // Return the updated head
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
