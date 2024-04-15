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
    int sumNumbers(TreeNode* root , int digit=0) {
    digit=(root)?root->val+10*digit:0;
    return (!root||(!root->left && !root->right))?digit:    
            sumNumbers(root->left, digit)+sumNumbers(root->right, digit);      
    }
};