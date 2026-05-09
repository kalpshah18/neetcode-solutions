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
    void dfs(TreeNode* node, int& counter, int& val, int k){
        if(node->left) dfs(node->left, counter, val, k);
        counter++;
        if(counter == k){
            val = node->val;
            return;
        } else if(counter > k) return;
        if(node->right) dfs(node->right, counter, val, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int val = 0;
        dfs(root, counter, val, k);
        return val;
    }
};
