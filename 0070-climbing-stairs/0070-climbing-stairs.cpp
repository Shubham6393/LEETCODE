class Solution {
public:
    // initialize the dp and used as a diary to store prev value.
    vector<int> dp;
    int climbStairs(int n) {
        // base case
        if(n==0 || n==1){
            return 1;
        }
        // check kr rhe hai agar dp empty hai toh size ko 1 jada kr ke sbko -1 se initialize kr rhe hai
        if(dp.empty()){
            dp.resize(n+1,-1);
        }
        // check rhe hai ki dp me pehle se toh nhi agar pehle se hai toh ussi dp se nikal ke de denge 
        if(dp[n] != -1){
            return dp[n];
        }
        // ans calculate kr rhe hai 
        int ans  = climbStairs(n-1)+climbStairs(n-2);
        //  agar pehle se nhi hai toh calculated ans ko dp me daal rhe hai 
        dp[n]= ans;
        
        return ans;
    }
};