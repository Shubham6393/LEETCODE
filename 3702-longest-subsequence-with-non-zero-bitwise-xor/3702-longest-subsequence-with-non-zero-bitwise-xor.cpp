class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool ans = false;
        for(int i = 0; i<n; i++){
            xr = xr ^ nums[i];
            if(nums[i] != 0){
                ans = true;
            }
        }
        if(xr != 0){
            return n;
        }
        if(ans){
            return n-1;
        }
        

        return 0;
        
        
    }
};