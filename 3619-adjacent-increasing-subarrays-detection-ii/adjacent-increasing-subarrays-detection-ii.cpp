class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int curr =0 ;
        int prev = 0;
        for(int i =0 ;i<n;i++){
            curr++;
            if(i==n-1 || nums[i]>=nums[i+1]){
            ans = max(ans,(curr/2));
            ans = max(ans , min(prev,curr));
            prev= curr;
            curr=0;
            }
            
        }
        return ans;
    }
};