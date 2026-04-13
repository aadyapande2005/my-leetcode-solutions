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
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] || v[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while(!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle_size++;
            }

            if(cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        unordered_map<int,vector<int>> levels;

        while(!q.empty())
        {
            int curr_size = q.size();
            for(int i=0;i<curr_size;i++)
            {
                auto [node, lvl] = q.front();
                q.pop();

                levels[lvl].push_back(node->val);
                
                if(node->left) q.push({node->left, lvl+1});
                if(node->right) q.push({node->right, lvl+1});
            }
        }
        int ans = 0;

        for(auto l:levels) ans += minSwaps(l.second);

        return ans;
    }
};