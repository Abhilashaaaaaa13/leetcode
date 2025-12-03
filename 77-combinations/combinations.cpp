class Solution {
public:
void solve(int n , int k , vector<vector<int>>&ans,int index,vector<int>&output){
    if(output.size()==k){
        ans.push_back(output);
        return ;
    }
    for(int i = index;i<=n;i++){
        output.push_back(i);
        solve(n,k,ans,i+1,output);
        output.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>output;
        int index =0;
        solve(n,k,ans,1,output);
        return ans;
    }
};