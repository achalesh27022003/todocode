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
    int ans=0;
    void dfs(vector<int>&vis,TreeNode* root){
        if(!root)return;
        if(root->left==NULL and root->right==NULL){
            int odd=0;
            for(int i=1;i<10;i++)
                if(vis[i]%2!=0)odd++;
            if(odd>1)return;
            ans++;
        }
        if(root->left){
        vis[root->left->val]++;
        dfs(vis,root->left);
        vis[root->left->val]--;}
        if(root->right){
            vis[root->right->val]++;
        dfs(vis,root->right);
            vis[root->right->val]--;}
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return 0;
        vector<int>vis(10,0);
        vis[root->val]++;
        dfs(vis,root);
        return ans;
    }
};
