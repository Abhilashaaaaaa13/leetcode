class Solution {
public:
int solve(int n, vector<int>&prices,int index , int buy, int limit,vector<vector<vector<int>>>&dp){
    if(n==index){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    if(dp[index][buy][limit]!= -1){
        return dp[index][buy][limit];
    }
    int profit =0;
    if(buy){
        int buykaro = -prices[index]+solve(n,prices,index+1,0,limit,dp);
        int skipkaro = 0+ solve(n,prices,index+1,1,limit,dp);
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index]+solve(n,prices,index+1,1,limit-1,dp);
        int skipkaro = 0+ solve(n,prices,index+1,0,limit,dp);
        profit = max(sellkaro,skipkaro);
    }
    return dp[index][buy][limit] = profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,prices,0,1,2,dp);
    }
};