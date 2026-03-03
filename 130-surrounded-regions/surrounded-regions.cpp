class Solution {
public:
vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
void bfs(vector<vector<char>>&board,int i,int j){
    int m=board.size();
    int n=board[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    board[i][j]='T';
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(auto dir:directions){
            int newx = x+dir[0];
            int newy = y+dir[1];
            if(newx>=0 &&newx<m && newy>=0 && newy<n &&board[newx][newy]=='O'){
                 board[newx][newy]='T';
                 q.push({newx,newy});
            }
        }
    }

}
    void solve(vector<vector<char>>& board) {
       int m = board.size();
       int n = board[0].size();
       for(int i=0;i<m;i++){
       if(board[i][0]=='O')
       bfs(board,i,0);
       if(board[i][n-1]=='O')bfs(board,i,n-1);
       }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')bfs(board,0,j);
            if(board[m-1][j]=='O')bfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};