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
TreeNode*check(vector<int>& inorder,int instart, int inend, vector<int>& postorder,int poststart, int postend){
    if(instart>inend|| poststart>postend){
        return NULL;
    }
    int rootval = postorder[postend];
    TreeNode*root = new TreeNode(rootval);
    int inroot = mp[rootval];
    int leftsize = inroot-instart;
    root->left = check(inorder,instart,inroot-1,postorder,poststart,poststart+leftsize-1);
    root->right = check(inorder,inroot+1,inend,postorder,poststart+leftsize,postend-1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return check(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};