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
    TreeNode* sol(TreeNode* root, int &sum) {

        if(root == nullptr) return nullptr;

        TreeNode* right = sol(root->right, sum);
        sum += root->val;
        // cout<<sum<<" "<<root->val<<endl;
        root->val = sum;
        TreeNode* left = sol(root->left, sum);

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        return sol(root, sum);
    }
};