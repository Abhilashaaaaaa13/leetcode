class Solution {
public:
void solve(vector<string>&result,string curr, int open , int close, int n){
    if(curr.length()==2*n){
        result.push_back(curr);
        return;
    }
    if(open<n){
        curr.push_back('(');
        solve(result,curr,open+1,close,n);
        curr.pop_back();
    }
    if(close<open){
        curr.push_back(')');
        solve(result,curr,open,close+1,n);
        curr.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string curr = "";
        int open =0;
        int close =0;
        solve(result,curr,open,close,n);
        return result;
    }
};