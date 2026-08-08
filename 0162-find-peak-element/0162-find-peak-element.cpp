class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int maxi = nums[0];
        for(int i =1; i<n; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                idx = i;
            }

        }
        return idx;
        
    }
};