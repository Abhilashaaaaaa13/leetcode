class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector< long long >>maxdp(m,vector<long long>(n));
        vector<vector< long long >>mindp(m,vector<long long>(n));
        const long long MOD = 1e9+7;
        //base case
        maxdp[0][0]=mindp[0][0]=grid[0][0];
        //row
        for(int j=1;j<n;j++){
            maxdp[0][j] = mindp[0][j]= maxdp[0][j-1]*grid[0][j];
        }
        for(int i=1;i<m;i++){
            maxdp[i][0] = mindp[i][0] = maxdp[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long val = grid[i][j];
                long long a = maxdp[i-1][j]*val;
                long long b = mindp[i-1][j]*val;
                long long c = maxdp[i][j-1]*val;
                long long d = mindp[i][j-1]*val;
                maxdp[i][j] = max({a,b,c,d});
                mindp[i][j] = min({a,b,c,d});
            }
        }
        long long ans = maxdp[m-1][n-1];
        if(ans<0)return -1;
        return ans%MOD;
    }
};