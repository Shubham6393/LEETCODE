class Solution {
public:

    void solve(string &s, int idx, int ones, string &curr,
               int k, string &ans) {

        // We already have more than k ones
        if (ones > k) {
            return;
        }

        // We found exactly k ones
        if (ones == k) {

            if (ans == "" ||
                curr.length() < ans.length() ||
                (curr.length() == ans.length() && curr < ans)) {

                ans = curr;
            }

            return;
        }

        // String khatam ho gayi
        if (idx == s.length()) {
            return;
        }

        // Pick current character
        curr.push_back(s[idx]);

        if (s[idx] == '1') {
            solve(s, idx + 1, ones + 1, curr, k, ans);
        }
        else {
            solve(s, idx + 1, ones, curr, k, ans);
        }

        // Backtrack
        curr.pop_back();
    }

    string shortestBeautifulSubstring(string s, int k) {

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            string curr = "";

            solve(s, i, 0, curr, k, ans);
        }

        return ans;
    }
};