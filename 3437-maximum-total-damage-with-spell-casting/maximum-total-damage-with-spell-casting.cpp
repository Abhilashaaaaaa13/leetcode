class Solution {
public:
long long solve(int i , vector<int>& power, vector<int>&value, unordered_map<int,long long>&freq,vector<long long >&dp){
    if (i<0)return 0;
    //skip
    if(dp[i]!= -1)return dp[i];
    long long skip = solve(i-1,power,value,freq,dp);
    //take
    long long take = (long long)value[i]*freq[value[i]];
    int j = i-1;
    while(j>=0 && value[j]>=value[i]-2)j--;
   if(j>=0)
    take += solve(j,power,value,freq,dp);
    dp[i]= max(skip,take);
    return dp[i];
}
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long>freq;
        for(int p : power)freq[p]++;
        vector<int>value;
        for(auto&it: freq)
        value.push_back(it.first);
        sort(value.begin(),value.end());
        int n = value.size();
        vector<long long>dp(n,-1);
        return solve(n-1,power, value,freq,dp);
    }
};