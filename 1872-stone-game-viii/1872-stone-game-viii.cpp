class Solution {
    vector<long long> pref;
    int n;

    long long solve(int i, vector<long long> &dp) {
       
        if (i == n - 1) {
            return pref[n - 1];
        }
        if(dp[i] != -1e18){
            return dp[i];
        }

        // Option 1: PICK index i
        long long pick = pref[i] - solve(i + 1,dp);

        // Option 2: NOT PICK index i (move to i + 1)
        long long notPick = solve(i + 1,dp);

        return dp[i] = max(pick, notPick);
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<long long> dp(n+1 , -1e18);
        pref.resize(n);
        
        // Step 1: Compute Prefix Sums
        pref[0] = stones[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Start from index 1 because x >= 2 (1-based count)
        return solve(1,dp);
    }
};