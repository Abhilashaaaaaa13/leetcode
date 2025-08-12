class Solution {
public:
int solve(vector<int>& prices,int k){
    int n = prices.size();
    vector<int>curr(2*k+1,0);
    vector<int>next(2*k+1,0);
   
    int profit =0;
    for(int index = n-1; index>=0 ;index--){
        for(int operation =0 ;operation<2*k;operation++){
    
    if(operation%2 == 0){
        int buykaro = -prices[index]+next[operation+1];
        int skipkaro = 0+next[operation];
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index]+next[operation+1];
        int skipkaro = 0+next[operation];
        profit = max(sellkaro,skipkaro);
    }
    curr[operation]=profit;
        }
        next=curr;}
       return  curr[0];
}
    int maxProfit(int k, vector<int>& prices) {
       
      return solve(prices,k);
    }
};