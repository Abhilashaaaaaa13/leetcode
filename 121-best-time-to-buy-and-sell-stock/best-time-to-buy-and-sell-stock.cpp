class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxprofit =0;
       int minvalue = prices[0] ;
       for(int i=1;i<prices.size();i++){
        if(prices[i]<minvalue){
            minvalue = prices[i];
        }
        else {
            int profit= prices[i]-minvalue;
            maxprofit = max(maxprofit,profit);
        }
       }
return maxprofit;
    }
};