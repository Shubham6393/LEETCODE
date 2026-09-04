class Solution {
public:
    int solve(int idx, int end, vector<int>& nums, vector<int>& dp) {

        if (idx > end) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Take current house
        int take = nums[idx] + solve(idx + 2, end, nums, dp);

        // Don't take current house
        int notTake = solve(idx + 1, end, nums, dp);

        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Case 1: First house included -> exclude last
        vector<int> dp1(n, -1);
        int case1 = solve(0, n - 2, nums, dp1);

        // Case 2: First house excluded -> last can be included
        vector<int> dp2(n, -1);
        int case2 = solve(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};