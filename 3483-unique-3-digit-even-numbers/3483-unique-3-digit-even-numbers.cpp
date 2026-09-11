class Solution {
public:
    void solve(int &cnt, int pos, vector<int>& freq) {
        if(pos == 3) {
            cnt++;
            return;
        }
        for(int i = 0; i <= 9; i++) {
            if(freq[i] == 0) {
                continue;
            }
            if(pos == 0 && i == 0) {
                continue;
            }
            if(pos == 2 && (i % 2 != 0)) {
                continue;
            }
            freq[i]--;
            solve(cnt, pos + 1, freq);
            freq[i]++;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }
        int cnt = 0;
        solve(cnt, 0, freq);
        return cnt;
    }
};