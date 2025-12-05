class Solution {
public:
void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&output,vector<bool>&used){
    if(output.size()==nums.size()){
        ans.push_back(output);
        return ;
    }
    for(int i =0 ;i<nums.size();i++){
        if(!used[i]){
        used[i]=true;
        output.push_back(nums[i]);
    
        solve(nums,ans,output,used);
        output.pop_back();
        used[i]=false;
    }}
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        vector<bool>used(nums.size(),false);
        
        solve(nums,ans,output,used);
        return ans;
    }
};