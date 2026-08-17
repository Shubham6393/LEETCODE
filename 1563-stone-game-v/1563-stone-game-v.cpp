class Solution {
public:

    int solve(vector<int>& stoneValue,
              int l,
              int r,
              vector<vector<int>>& dp,
              vector<int>& prefix) {

        // Only one stone
        if (l == r) {
            return 0;
        }

        // Already calculated
        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        int ans = 0;

        // Try every possible split
        for (int k = l; k < r; k++) {

            // O(1) left sum
            int leftSum = prefix[k + 1] - prefix[l];

            // O(1) right sum
            int rightSum = prefix[r + 1] - prefix[k + 1];

            // Left is smaller
            if (leftSum < rightSum) {

                ans = max(
                    ans,
                    leftSum + solve(
                        stoneValue,
                        l,
                        k,
                        dp,
                        prefix
                    )
                );
            }

            // Right is smaller
            else if (leftSum > rightSum) {

                ans = max(
                    ans,
                    rightSum + solve(
                        stoneValue,
                        k + 1,
                        r,
                        dp,
                        prefix
                    )
                );
            }

            // Equal
            else {

                ans = max(
                    ans,
                    leftSum + max(
                        solve(
                            stoneValue,
                            l,
                            k,
                            dp,
                            prefix
                        ),
                        solve(
                            stoneValue,
                            k + 1,
                            r,
                            dp,
                            prefix
                        )
                    )
                );
            }
        }

        return dp[l][r] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        // DP
        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] + stoneValue[i];
        }

        return solve(
            stoneValue,
            0,
            n - 1,
            dp,
            prefix
        );
    }
};