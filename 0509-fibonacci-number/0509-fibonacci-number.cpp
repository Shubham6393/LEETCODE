class Solution {
public:
    // dp initialize using hashmap hum vector bhi initialize kr skte hai
    unordered_map<int, int> dp;  // ye ek diary ki tarah rahega esme hum value store karenge
    int fib(int n) {
        // base case
        if(n == 0 || n == 1){
            return n;
        }

        // aab dp me check karenge ki pehle se toh nhi n hai ?
        if(dp.find(n) != dp.end()){
            return dp[n];
        }

        int a1 = fib(n-1);
        int a2 = fib(n-2);
        int ans = a1+a2;

        dp[n] = ans; // ans ko dp me daal denge for future use ...

        return ans;
        
    }
};