class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

    return max(
        nums[n-1] * nums[n-2] * nums[n-3],  // aakhari ka largest element mil jayega
        nums[0] * nums[1] * nums[n-1]  // agar negative hai toh largest negative mil jayega usko multiply kr denge toh positive mil jayega .. phir usko multiply kr denge last wale se aur dono ka max element nikal lenge ...
    );
        
    }
};