class Solution {
public:
bool isValid(vector<string>&board,int row,int col,int n){
  for(int i=row-1;i>=0;i--){
    if(board[i][col]=='Q'){
        return false;
    }
  }
  //check uper left diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
    if(board[i][j]=='Q'){
        return false;
    }
   
  }
  //check right diagonal
  for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++ ){
    if(board[i][j]=='Q'){
        return false;
    }
  }
   return true;
}
void solve(int n,vector<string>&board,int &count,int row){
    if(row>=n){
        count++;
        return;
    }
    for(int col=0;col<n;col++){
        if(isValid(board,row,col,n)){
            board[row][col]='Q';
            solve(n,board,count,row+1);
            board[row][col]='.';
        }
    }
}
    int totalNQueens(int n) {
        int count =0;
        vector<string>board(n,string(n,'.'));
        solve(n,board,count,0);
        return count;
    }
};