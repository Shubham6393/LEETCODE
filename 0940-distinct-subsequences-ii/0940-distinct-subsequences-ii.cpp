class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        vector<long long> dp(26, 0);
        
        long long total = 0;

        for(char ch : s) {
            
            int i = ch - 'a';

            
            long long add = (total + 1) % MOD;

            
            total = (total + add - dp[i] + MOD) % MOD;

            dp[i] = add;
        }

        return total;
    }
};