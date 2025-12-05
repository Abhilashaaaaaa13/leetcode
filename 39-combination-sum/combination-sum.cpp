class Solution {
public:
void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&output,int index){
    if(target==0){
        ans.push_back(output);
        return;
    }
    if(index>=candidates.size()|| target<0){
        return;
    }
    int element = candidates[index];
    output.push_back(element);
    solve(candidates,target-element,ans,output,index);
    output.pop_back();
    solve(candidates,target,ans,output,index+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
       int index =0;
       solve(candidates,target,ans,output,index);
       return ans;
    }
};