class Solution {
public:
    int missingInteger(vector<int>& nums) {

        vector<int> ans;

        ans.push_back(nums[0]);

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]-nums[i-1] == 1){
                ans.push_back(nums[i]);
            }else{
                break;
            }
        }

        int sum = 0;
        for(int i = 0;i<ans.size();i++){
            sum += ans[i];
        }

        for(int i = 0; i<nums.size(); i++){
            if(sum == nums[i]){
                sum++;
                i = -1;
            }
        }
        return sum;
        
    }
};