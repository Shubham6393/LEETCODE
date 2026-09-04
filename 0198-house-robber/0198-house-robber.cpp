class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int> &dp){
        if(idx>=nums.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int pick = nums[idx] + solve(nums, idx+2, dp);

        int notPick = solve(nums, idx+1, dp);

        int ans = max(pick,notPick);

        dp[idx] = ans;

        return ans;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
        
    }
};