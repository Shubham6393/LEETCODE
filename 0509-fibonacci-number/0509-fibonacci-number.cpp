class Solution {
public:
    vector<int> dp;
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        
        if(dp.empty()){
            dp.resize(n+1,-1);
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int a1 = fib(n-1);
        int a2 = fib(n-2);

        int ans = a1+a2;

        dp[n] = ans;

        return ans;
        
    }
};