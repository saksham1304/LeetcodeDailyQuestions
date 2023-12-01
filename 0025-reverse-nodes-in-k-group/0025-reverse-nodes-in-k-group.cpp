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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;

        // Count the number of nodes in the current k-group
        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }

        // If there are enough nodes for a k-group, reverse the k-group
        if (count == k) {
            // Reverse the k-group starting from the current head
            ListNode* reversedHead = reverseList(head, k);

            // Recursively reverse the next k-group
            head->next = reverseKGroup(current, k);

            return reversedHead;
        }

        // If there are fewer than k nodes, return the original head
        return head;
    }

    // Helper function to reverse a linked list of given size k
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        // Reverse the first k nodes in the list
        while (k > 0 && current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            k--;
        }

        return prev;
    }
};
