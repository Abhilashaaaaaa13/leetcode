class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        vector<vector<int>>currx(m,vector<int>(n,0));
        vector<vector<int>>curry(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                currx[i][j] =(grid[i][j]=='X');
                curry[i][j] = (grid[i][j]=='Y');
                if(i>0){
                    currx[i][j] += currx[i-1][j];
                    curry[i][j] += curry[i-1][j];
                }
                if(j>0){
                    currx[i][j] += currx[i][j-1];
                    curry[i][j] += curry[i][j-1];
                }
                if(i>0 && j>0){
                    currx[i][j] -= currx[i-1][j-1];
                    curry[i][j] -= curry[i-1][j-1];
                }
                int countx = currx[i][j];
                int county = curry[i][j];
                if(countx==county &&countx>=1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};