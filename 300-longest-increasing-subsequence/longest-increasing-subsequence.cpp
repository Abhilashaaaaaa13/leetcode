class Solution {
public:
int solve(vector<int>& nums,int index,int n , int p,vector<vector<int>>&dp){
    if(index>=n){
        return 0;
    }
  int take =0;
  if(p != -1 && dp[index][p] != -1){
    return dp[index][p];
  }
    if(p==-1 || nums[index]>nums[p]){
     take = 1+solve(nums,index+1,n,index,dp);
    }
    int skip = solve(nums,index+1,n,p,dp);
    if(p!= -1)
  dp[index][p] = max(take,skip);
  return max(take,skip) ;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,0,n,-1,dp);
    }
};