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
    ListNode* deleteDuplicates(ListNode* head) {
                if (!head) return nullptr;

        std::unordered_map<int, int> countMap;
        ListNode* temp = head;

        // Count the occurrences of each value in the list
        while (temp) {
            countMap[temp->val]++;
            temp = temp->next;
        }

        ListNode dummy; // Dummy head for the new list
        ListNode* current = &dummy;

        // Iterate through the original list and add non-duplicate values to the new list
        temp = head;
        while (temp) {
            if (countMap[temp->val] < 2) {
                current->next = new ListNode(temp->val);
                current = current->next;
            }
            temp = temp->next;
        }

        return dummy.next;
    }
};
