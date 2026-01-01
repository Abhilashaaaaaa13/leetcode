class Solution {
public:
bool check(vector<vector<char>>& board, string word, int m , int n, int i , int j,int index){
    if(index==word.size()){
        return true;
    }
    if(i<0|| j<0|| i>=m||j>=n || board[i][j]!=word[index]){
        return false;
    }
    char temp = board[i][j];
    board[i][j]='#';
    bool found =
    check(board,word,m,n,i+1,j,index+1)||
    check(board,word,m,n,i-1,j,index+1)||
    check(board,word,m,n,i,j+1,index+1)||
    check(board,word,m,n,i,j-1,index+1);

    board[i][j]=temp;
    return found;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
       for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            if(check(board,word,m,n,i,j,0))
            return true;
        }
       }
       return false;
    }
};