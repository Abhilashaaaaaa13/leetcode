class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int result =0;
        
        for(int x:nums){
            vector<int>ans;
        for(int i =1;i*i<=x;i++){
            if(x%i==0){
             ans.push_back(i);
            
            if(i != x/i)
                ans.push_back(x/i);
            
        }}
        
        
        if(ans.size()==4){
        for(int d:ans){
            result += d;
        }}
        }
        return result;
    }
};