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
void dfs( vector<tuple<int , int , int>>&nodes, int row, int col,TreeNode* root ){
    if(root==NULL)return;
    nodes.push_back({col,row,root->val});
    dfs(nodes,row+1,col-1,root->left);
    dfs(nodes, row+1,col+1, root->right);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int , int , int>>nodes;
        vector<vector<int>>result;

        dfs(nodes,0,0,root);
        sort(nodes.begin(), nodes.end());
        int prevcol = INT_MIN;
        for(auto[col, row, values]:nodes){
            if(col != prevcol){
            result.push_back({});
            prevcol = col;
            }
            result.back().push_back(values);
        }
        return result;
    }
};