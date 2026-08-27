class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string &s, int idx, vector<string> &diary,
               vector<vector<string>> &ans) {

        // Base case
        if(idx == s.length()) {
            ans.push_back(diary);
            return;
        }

        // Try every possible substring
        for(int i = idx; i < s.length(); i++) {

            // Check if s[idx...i] is palindrome
            if(isPalindrome(s, idx, i)) {

                // Pick
                diary.push_back(s.substr(idx, i - idx + 1));

                // Recursion
                solve(s, i + 1, diary, ans);

                // Backtrack
                diary.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> diary;

        solve(s, 0, diary, ans);

        return ans;
    }
};