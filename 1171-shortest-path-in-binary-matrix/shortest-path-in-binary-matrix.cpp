class Solution {
public:
vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            auto[x,y]= q.front();
            q.pop();
            int dist = grid[x][y];
            if(x==n-1 && y==n-1)return dist;
            for(vector<int>dir:directions){
                int newx = x+ dir[0];
                int newy = y + dir[1];
                if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==0){
                   grid[newx][newy]=dist+1;
                   q.push({newx,newy});
                
                }
            }
        }
        return -1;
    }
};