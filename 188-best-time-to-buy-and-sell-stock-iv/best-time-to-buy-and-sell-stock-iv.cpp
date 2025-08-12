class Solution {
public:
int solve(int index , int k, int operation,vector<int>& prices,vector<vector<int>>&dp){
    if(prices.size()==index){
        return 0;
    }
    if(k*2==operation){
        return 0;
    }
    if(dp[index][operation]!= -1){
        return dp[index][operation];
    }
    int profit =0;
    if(operation%2 == 0){
        int buykaro = -prices[index]+solve(index+1,k,operation+1,prices,dp);
        int skipkaro = 0+solve(index+1,k,operation,prices,dp);
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index]+solve(index+1,k,operation+1,prices,dp);
        int skipkaro = 0+solve(index+1,k,operation,prices,dp);
        profit = max(sellkaro,skipkaro);
    }
    return dp[index][operation]= profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
       return solve(0,k,0,prices,dp); 
    }
};