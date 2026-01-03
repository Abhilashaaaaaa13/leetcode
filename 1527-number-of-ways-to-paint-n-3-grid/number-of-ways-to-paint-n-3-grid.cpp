class Solution {
public:
int M = 1e9+7;
vector<vector<int>> t;
    string states[12]= {"YGY","GYG","RGR","GRG","YRY","RYR",
                        "RYG","GYR","RGY","YRG","GRY","YGR"};
    

int solve(int n, int prev){
   if(n==0) return 1; // base case
        
        if(t[n][prev] != -1) return t[n][prev];
        
        int result = 0;
        string last = states[prev];
        
        for(int curr = 0; curr < 12; curr++){
            string currpath = states[curr];
            bool conflict = false;
            for(int col=0; col<3; col++){
                if(currpath[col] == last[col]){
                    conflict = true;
                    break;
                }
            }
            if(!conflict){
                result = (result + solve(n-1, curr)) % M;
            }
        }
        
        return t[n][prev] = result;
}
    int numOfWays(int n) {
        int result = 0;
        t.resize(n+1, vector<int>(12, -1)); // fix size
        
        for(int i=0; i<12; i++){
            result = (result + solve(n-1, i)) % M;
        }
        return result;}
};