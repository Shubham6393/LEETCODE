class Solution {
public:

    void solve(int ind, vector<int>& nums,
               vector<int>& ds, vector<vector<int>>& ans) {

        // Current subset is always a valid subset
        ans.push_back(ds);

        // Try every element from current index
        for(int i = ind; i < nums.size(); i++) {

            // Skip duplicate elements
            // if it is not the first choice at this level
            if(i > ind && nums[i] == nums[i - 1]) {
                continue;
            }

            // Pick
            ds.push_back(nums[i]);

            solve(i + 1, nums, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Step 1: Sort so duplicates become adjacent
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        // Step 2: Generate only unique subsets
        solve(0, nums, ds, ans);

        return ans;
    }
};