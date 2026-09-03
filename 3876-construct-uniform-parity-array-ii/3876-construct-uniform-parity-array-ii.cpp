class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n  = nums1.size();

        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        for(int num : nums1){
            if(num % 2 == 0){
                minEven = min(minEven,num);
            }else{
                minOdd = min(minOdd,num);
            }
        }

        bool allEven = true;

        for(int num : nums1){
            if(num % 2 == 0){
                continue;
            }

            if(minOdd == INT_MAX || minOdd >= num){
                allEven = false;
                break;
            }
            
        }
        if(allEven){
            return true;
        }

        bool allOdd = true;

        for(int num : nums1){
            if(num % 2 != 0){
                continue;
            }

            if(minOdd == INT_MAX || minOdd >= num){
                allOdd = false;
                break;
            }
        }
        if(allOdd){
            return true;
        }
        
        return false;
    }
};