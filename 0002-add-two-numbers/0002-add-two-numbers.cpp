/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify insertion
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + carry;
            carry = sum / 10; // Calculate carry
            curr->next = new ListNode(sum % 10); // Create a new node with the sum % 10
            curr = curr->next; // Move the current pointer forward
            l1 = (l1 != nullptr ? l1->next : nullptr); // Move l1 pointer forward if not null
            l2 = (l2 != nullptr ? l2->next : nullptr); // Move l2 pointer forward if not null
        }
        
        return dummy->next; // Return the next of the dummy node which is the start of the resultant list
    }
};
