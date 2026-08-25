class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] % k == 0){
                s.insert(nums[i]);
            }
        }
        int mini = k;
        for(int i =0;i<s.size();i++){
            if(s.count(mini)){
                mini += k;
            }

        }
        return mini;
        
    }
};