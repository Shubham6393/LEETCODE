class Solution {
public:
    

    int solve(int i, int j, int m,int n, string &s, string &t, vector<vector<int>> &dp){

       

        if(j == n){
            return 1;
        }

        if(i == m){
            return 0;
        }

        

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int notTake = solve(i+1,j,m,n,s,t,dp);

        int take = 0;
        if(s[i] == t[j]){
            take = solve(i+1,j+1,m,n,s,t,dp);
        }

        int ans = take + notTake;

        dp[i][j] = ans;

        return ans;


    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,s,t,dp);
        
    }
};