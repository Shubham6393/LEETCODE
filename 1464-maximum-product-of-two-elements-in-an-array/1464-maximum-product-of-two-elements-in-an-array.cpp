class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int res;
        int maxi =0;
        int first,second;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                res = nums[i]*nums[j];
                if(res>maxi){
                    maxi = res;
                    first = nums[i];
                    second = nums[j];
                }
                
            }
            
            
        }
        return (first-1)*(second-1);
        
    }
};