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
unordered_map<int,int>mp;
TreeNode*solve(vector<int>& preorder, int prestart , int preend,vector<int>& inorder,int instart,int inend){
    if(prestart>preend||instart>inend){
        return NULL;
    }
    //preorder m s 1 root 
    int rootval = preorder[prestart];
    //us value ko node bnaya
    TreeNode*root = new TreeNode(rootval);
    // root ka index inorder me
    int inroot = mp[rootval];
    int leftsize = inroot-instart;
   root->left =  solve(preorder,prestart+1,prestart+leftsize,inorder,instart,inroot-1);
   root->right = solve(preorder,prestart+leftsize+1,preend,inorder,inroot+1,inend);
   return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i= 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};