class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MIN));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int product = nums1[i-1] * nums2[j-1];

            int best = product;
            if (dp[i-1][j-1] != INT_MIN) {
                best = max(best, product + dp[i-1][j-1]);
            }

            best = max(best, dp[i-1][j]);
            best = max(best, dp[i][j-1]);

            dp[i][j] = best;
        }
    }
    return dp[m][n];
    }
};