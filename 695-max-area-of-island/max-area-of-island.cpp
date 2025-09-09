class Solution {
public:
int dfs(vector<vector<int>>& grid, int i , int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i<0 || j< 0 || i>=m || j>=n || grid[i][j]==0)return 0;
    grid[i][j]=0;
    int maxarea = 1;
    maxarea += dfs(grid,i+1,j);
    maxarea += dfs(grid,i-1,j);
    maxarea += dfs(grid,i,j+1);
    maxarea += dfs(grid,i,j-1);
    return maxarea;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area =0;
        for(int i =0 ;i<m ;i++){
            for(int j =0 ;j<n;j++){
                if(grid[i][j]==1){
                    
                   int maxarea =  dfs(grid,i,j);
                   area = max(maxarea,area);
                }
            }
        }
        return area;
    }
};