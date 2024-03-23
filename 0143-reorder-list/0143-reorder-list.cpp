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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev = nullptr, *curr = slow->next;
        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = nullptr; // Terminate the first half

        // Merge the two halves
        ListNode *p1 = head, *p2 = prev;
        while (p1 && p2) {
            ListNode *next1 = p1->next;
            ListNode *next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
    }
};
