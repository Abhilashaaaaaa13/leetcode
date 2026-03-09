class Solution {
public:
int M = 1e9+7;
int dp[201][201][2];
int solve(int onesleft, int zerosleft, int limit, bool lastwasone){
    if(onesleft==0 && zerosleft==0){
        return 1;
    }
     if(dp[onesleft][zerosleft][lastwasone] != -1)
        return dp[onesleft][zerosleft][lastwasone];
    int result =0;
    if(lastwasone==true){//explore zeros
    for(int i=1;i<=min(zerosleft,limit);i++){
        result = (result+solve(onesleft,zerosleft-i,limit,false))%M;
    }}
    else{
        //explore ones
        for(int i=1;i<=min(onesleft,limit);i++){
            result = (result+solve(onesleft-i,zerosleft,limit,true))%M;
        }
    

    }
    return dp[onesleft][zerosleft][lastwasone]=result;
}
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int startwithone = solve(one,zero,limit,false);
        int startwithzero = solve(one,zero,limit,true);
        return (startwithone+startwithzero)%M;
    }
};