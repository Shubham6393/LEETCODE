class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for (int val : nums) {
            int windowCount = 0; 

            for (int i = 0; i <= n - k; i++) {
                bool found = false;

                for (int j = i; j < i + k; j++) {
                    if (nums[j] == val) {
                        found = true;
                        break;
                    }
                }
                if (found) windowCount++;
            }

            if (windowCount == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};