class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n>0){
            ans.push_back(n%10);
            n= n/10;
        }
        int res ;
        int maxi = 0;
        for(int i =0;i<ans.size();i++){
            for(int j = i+1; j<ans.size();j++){
                res = ans[i]*ans[j];
                maxi = max(res,maxi);
            }
           
        }
        return maxi;


        
    }
};