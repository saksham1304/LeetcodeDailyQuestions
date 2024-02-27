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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        calculateDiameter(root, max_diameter);
        return max_diameter;
    }
    
    int calculateDiameter(TreeNode* node, int& max_diameter) {
        if (node == nullptr)
            return 0;
        
        int left_depth = calculateDiameter(node->left, max_diameter);
        int right_depth = calculateDiameter(node->right, max_diameter);
        
        // Update max_diameter if necessary
        max_diameter = max(max_diameter, left_depth + right_depth);
        
        // Return the depth of the current node
        return max(left_depth, right_depth) + 1;
    }
};
