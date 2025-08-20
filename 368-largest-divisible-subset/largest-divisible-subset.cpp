class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);
        vector<int>prev_index(n,-1);
        int last_choosen_index =0;
        int maxL =1;
        for(int i =1 ;i<n;i++){
            for(int j =0 ;j<i;j++){
                if(nums[i]%nums[j]==0){
                  if(  dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev_index[i] = j;
                  }
                  if(dp[i]>maxL){
                    maxL = dp[i];
                    last_choosen_index =i;

                  }
                }
            }
        }
        vector<int>result;
        while(last_choosen_index != -1){
            result.push_back(nums[last_choosen_index]);
            last_choosen_index = prev_index[last_choosen_index];
        }
        return result;
    }
};