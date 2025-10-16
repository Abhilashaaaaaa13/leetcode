class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;

    // Count remainders (adjust for negative numbers too)
    for (int x : nums) {
        int rem = ((x % value) + value) % value; // ensure positive remainder
        freq[rem]++;
    }

    int mex = 0;

    while (true) {
        int rem = mex % value;

        if (freq[rem] > 0) {
            freq[rem]--; // use one occurrence
            mex++;       // try to make next number
        } else {
            break;       // can't form this number
        }
    }

    return mex;
    }
};