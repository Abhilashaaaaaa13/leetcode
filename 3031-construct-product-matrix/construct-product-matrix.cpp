class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int MOD = 12345;
       vector<vector<int>>dp(m,vector<int>(n));
       long long suffix = 1;
       for(int i = m-1;i>=0;i--) {
        for(int j = n-1;j>=0;j--){
            dp[i][j] = suffix;
            suffix = (suffix*grid[i][j])%MOD;
        }
       }
       long long prefix =1;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = (prefix*dp[i][j])%MOD;
            prefix = (prefix*grid[i][j])%MOD;
        }
       }
       return dp;
    }
};