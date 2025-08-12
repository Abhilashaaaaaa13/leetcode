class Solution {
public:
int solve(vector<int>& prices,int k){
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
   
    int profit =0;
    for(int index = n-1; index>=0 ;index--){
        for(int operation =0 ;operation<2*k;operation++){
    
    if(operation%2 == 0){
        int buykaro = -prices[index]+dp[index+1][operation+1];
        int skipkaro = 0+dp[index+1][operation];
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index]+dp[index+1][operation+1];
        int skipkaro = 0+dp[index+1][operation];
        profit = max(sellkaro,skipkaro);
    }
    dp[index][operation]=profit;
        }}
       return  dp[0][0];
}
    int maxProfit(int k, vector<int>& prices) {
       
      return solve(prices,k);
    }
};