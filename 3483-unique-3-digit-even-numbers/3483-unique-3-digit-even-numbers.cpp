class Solution {
public:
    void solve(vector<int>& digits, int num, int count,
        set<int>& st, vector<int>& dp){
            if(count == 3){
                if(num % 2 == 0){
                    st.insert(num);
                }
                return;
            }

            for(int i = 0; i<digits.size(); i++){
                if(dp[i]){
                    continue;
                }

                if(count == 0 && digits[i] == 0){
                    continue;
                }

                dp[i] = 1;

                solve(digits,num*10+digits[i],count+1,st,dp);

                dp[i] = 0;
            }
        }
               
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        vector<int> dp(digits.size(), 0);

        solve(digits, 0, 0, st, dp);

        return st.size();
        
        
        
    }
};