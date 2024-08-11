/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        helper(root, arr);
        return arr;
    }

private:
    void helper(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) return;
        arr.push_back(node->val);
        helper(node->left, arr);
        helper(node->right, arr);
    }
};
