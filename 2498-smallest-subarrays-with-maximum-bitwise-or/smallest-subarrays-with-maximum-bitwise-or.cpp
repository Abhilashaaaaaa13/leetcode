class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        vector<int>setbitindex(32,-1);
        
        for(int i=n-1;i>=0;i--){
            int endindex=i;
            for(int j=0 ;j<32;j++){
                if(!(nums[i]& (1<<j))){//j bit is not set
                if(setbitindex[j]!=-1){
                     endindex = max(endindex,setbitindex[j]);
                }
                
                }
                else{
                    setbitindex[j]=i;
                }
            }
            result[i] = endindex-i+1;

        }
        return result;
    }
};