class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
         const long long MOD = 1e9 + 7;
        unordered_map<int, long long> cnt;

        for(auto &p : points)
            cnt[p[1]]++;

        vector<long long> v;
        for(auto &x : cnt)
            if(x.second >= 2) v.push_back(x.second);

        int m = v.size();
        if(m < 2) return 0;

        long long total = 0, squareSum = 0;

        for(long long x : v) {
            long long ways = x * (x - 1) / 2 % MOD;
            total = (total + ways) % MOD;
            squareSum = (squareSum + (ways * ways) % MOD) % MOD;
        }

        // (total^2 − sum(ways^2)) / 2
        long long ans = ( (total * total % MOD - squareSum + MOD) % MOD ) * ((MOD + 1) / 2) % MOD;
        return ans;
    }
};