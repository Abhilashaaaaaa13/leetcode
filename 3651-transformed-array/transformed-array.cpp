class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        for(int i =0;i<n;i++){
            int count;
            count = i+nums[i];
            count = ((i+nums[i])%n + n)%n;
            ans[i]=nums[count];
        }
        return ans;
    }
};