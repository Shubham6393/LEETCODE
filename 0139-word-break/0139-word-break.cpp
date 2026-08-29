class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &st,
               vector<int> &dp) {

        // Base case
        if(idx == s.length())
            return true;

        // Already calculated
        if(dp[idx] != -1)
            return dp[idx];

        for(int i = idx; i < s.length(); i++) {

            string word = s.substr(idx, i - idx + 1);

            if(st.find(word) != st.end()) {

                if(solve(i + 1, s, st, dp))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;

        for(auto word : wordDict)
            st.insert(word);

        vector<int> dp(s.length(), -1);

        return solve(0, s, st, dp);
    }
};