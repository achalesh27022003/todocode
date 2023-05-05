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
    int dfs(TreeNode* root,int &ans){
        if(!root)return 0;
        int left=max(dfs(root->left,ans),0);
        int right=max(dfs(root->right,ans),0);
        ans=max(ans,root->val+left+right);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)return 0;
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};
