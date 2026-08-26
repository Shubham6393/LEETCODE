class Solution {
public:
    // Recursive helper to generate all subsets
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& result) {
        // Base case: if we've considered all elements, add the current subset to the result set
        if (ind == nums.size()) {
            result.insert(ds);
            return;
        }

        // Choice 1: Include the element at the current index
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, result);
        // Backtrack to explore the other choice
        ds.pop_back();

        // Choice 2: Do not include the element at the current index
        findSubsets(ind + 1, nums, ds, result);
    }

    // Main function to find all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        // Sort the array to handle duplicates consistently
        sort(nums.begin(), nums.end());
        
        findSubsets(0, nums, ds, result);

        // Convert the set of unique subsets to a vector for the final answer
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};