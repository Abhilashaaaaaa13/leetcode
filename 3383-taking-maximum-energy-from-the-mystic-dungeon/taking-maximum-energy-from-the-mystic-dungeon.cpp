class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxsum = INT_MIN;
        vector<int>dp(n);
        for(int i = n-1;i>=0;i--){
            dp[i]=energy[i];
            if(i+k<n)
                dp[i] += dp[i+k];
                maxsum = max(maxsum,dp[i]);
            
        }
        return maxsum;
    }
};