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
    int i = 0;
    bool sol(TreeNode* root, vector<int>& voyage, vector<int> &ans)
    {
        if(!root) return true;
        
        if(root->val != voyage[i++]) return false;

        if(i < voyage.size() && root->left && root->left->val != voyage[i]) 
        {
            ans.push_back(root->val);
            return sol(root->right, voyage, ans) && sol(root->left, voyage, ans);
        }
        else 
        {
            return sol(root->left, voyage, ans) && sol(root->right, voyage, ans);
        }

        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        if(sol(root, voyage, ans)) return ans;
        else return {-1};
    }
};