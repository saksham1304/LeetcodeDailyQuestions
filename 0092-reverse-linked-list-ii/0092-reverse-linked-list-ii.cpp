class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) // No need to reverse if there's only one node or no node
            return head;

        ListNode dummy(0); // Dummy node to handle the case when left = 1
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Move prev to the node just before the left-th node
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        
        ListNode* curr = prev->next; // The left-th node
        ListNode* next = nullptr;
        ListNode* prevLeft = prev; // Node before the left-th node
        
        // Reverse nodes from left to right
        for (int i = left; i <= right; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        prevLeft->next->next = curr; // Connect the left-th node to the right-th node
        prevLeft->next = prev; // Connect the node before the left-th node to the right end of the reversed part
        
        return dummy.next;
    }
};
