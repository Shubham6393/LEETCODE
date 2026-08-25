class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mySet(nums.begin(), nums.end());
    
        int multiple = k;
        while (mySet.count(multiple)) {
            multiple += k;
        }
        
        return multiple;
        
    }
};