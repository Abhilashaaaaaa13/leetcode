class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total =nums[0];
        int currmax = nums[0], maxsum = nums[0], currmin = nums[0], minsum = nums[0];
        for(int i=1;i<n;i++){
             total += nums[i];
            currmax = max(nums[i],nums[i]+currmax);
            maxsum = max(maxsum,currmax);
            currmin = min(nums[i], nums[i]+currmin);
            minsum = min(currmin,minsum);
           
        }
      
        if(maxsum<0){
            return maxsum;
        }
        return max(maxsum,total-minsum);
    }
};