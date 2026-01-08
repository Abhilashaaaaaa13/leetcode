class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long totalsum = 0;
        int negcount = 0;
        int minabs = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = matrix[i][j];
                if (val<0){
                    negcount++;
                }
                totalsum += abs(val);
                minabs = min(minabs,abs(val));
            }
        }
        if(negcount%2==0)
       return totalsum;
       else 
       return totalsum -2*minabs;
        
    }
};