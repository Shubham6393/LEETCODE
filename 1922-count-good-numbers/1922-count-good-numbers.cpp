class Solution {
public:
    const int MOD = 1e9 + 7;
    long long solve(long long x, long long n){
        // base case 
        if(n==0){
            return 1;
        }
        
        long long half = solve(x, n/2);
        half = (half * half) % MOD;
        // check for even index..
        if(n % 2 == 0){
            return half;
        }else{
            // check for odd index..
            return (half * x) % MOD;
        }

    }
    int countGoodNumbers(long long n) {
        // Even index count (0,2,4,...)
        long long evenCount = (n + 1) / 2;

        // Odd index count (1,3,5,...)
        long long oddCount = n / 2;

        // Total ways = 5^evenCount * 4^oddCount
        long long evenWays = solve(5, evenCount);
        long long oddWays = solve(4, oddCount);

        long long ans = (evenWays * oddWays) % MOD;

        return (int)ans;
        
    }
};