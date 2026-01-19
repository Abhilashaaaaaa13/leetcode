class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
      int m = mat.size();
        int n = mat[0].size();

        // prefix sum matrix
        vector<vector<int>> pre(m+1, vector<int>(n+1, 0));

        // build prefix sum
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }

        // function to check if square of size k is possible
        auto possible = [&](int k) {
            for(int i = k; i <= m; i++) {
                for(int j = k; j <= n; j++) {
                    int sum = pre[i][j]
                            - pre[i-k][j]
                            - pre[i][j-k]
                            + pre[i-k][j-k];

                    if(sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        // binary search
        int low = 0, high = min(m, n), ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(possible(mid)) {
                ans = mid;
                low = mid + 1;  // try bigger square
            } else {
                high = mid - 1; // try smaller
            }
        }

        return ans;  
    }
};