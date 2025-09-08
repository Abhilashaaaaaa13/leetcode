class Solution {
public:
vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};

void bfs(vector<vector<char>>& grid, int i , int j){
int m = grid.size();
int n = grid[0].size();
queue<pair<int,int>>q;
q.push({i,j});
grid[i][j]='0';
while(!q.empty()){
    auto [x,y] = q.front();
    q.pop();
    for(vector<int>dir : directions){
        int newx = x + dir[0];
        int newy = y+ dir[1];
        if(newx >= 0 &&  newy >= 0 && newx < m && newy < n && grid[newx][newy]=='1'){
            grid[newx][newy]='0';
            q.push({newx, newy});
        }
    }
}
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count =0;
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};