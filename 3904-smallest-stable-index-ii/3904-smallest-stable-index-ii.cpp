class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suffix(nums.size());
        int mini = nums[nums.size()-1];
        for(int i = nums.size()-1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            suffix[i] = mini;
        }
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            int diff = maxi - suffix[i];
            if(diff <= k){
                return i;
            }
        }
        return -1;
    }
};