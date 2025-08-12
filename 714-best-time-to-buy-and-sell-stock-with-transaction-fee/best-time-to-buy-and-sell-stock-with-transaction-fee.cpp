class Solution {
public:
int solve( vector<int>& prices, int fee){
    int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
    
    int profit =0;
    for(int index = n-1; index>=0 ;index--){
        for(int buy=0;buy<=1;buy++){ 
    
    if(buy){
        int buykaro = -prices[index]+next[0];
        int skipkaro = 0+ next[1];
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index]-fee+next[1];
        int skipkaro = 0+ next[0];
        profit = max(sellkaro,skipkaro);
    }
    curr[buy]=profit;
    }
    next=curr;}
    return curr[1]; 
}
    int maxProfit(vector<int>& prices, int fee) {
        
        return solve(prices,fee);
    }
};