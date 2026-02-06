class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int curr = 1;
        int maxlen = 1;
        for(int i =1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                curr++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
          else{
            curr = 1;
          }
          maxlen = max(maxlen,curr);
        }
        return maxlen;
    }
};