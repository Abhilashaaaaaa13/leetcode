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
long long maxproduct =0;
int MOD = 1e9+7;
long long totalsum = 0;
long long dfssum(TreeNode*root){
    if(!root)return 0;
    return root->val+dfssum(root->left)+dfssum(root->right);
}
long long dfs(TreeNode*root ){
    if(!root)return 0;
    long long left = dfs(root->left);
    long long right = dfs(root->right);
    long long subsum = root->val+left+right;
    long long product = subsum *(totalsum-subsum);
    maxproduct = max(product,maxproduct);
    return subsum;
}

    int maxProduct(TreeNode* root) {
        
         totalsum = dfssum(root);
        dfs(root);
        return maxproduct%MOD;
    }
};