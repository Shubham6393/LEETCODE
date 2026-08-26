class Solution {
public:

    void solve(vector<int>& arr, int n, int idx,
               vector<vector<int>>& ans,
               vector<int>& diary,
               int sum, int target) {

        // Base case
        if (sum == target) {
            ans.push_back(diary);
            return;
        }

        if (idx == n || sum > target) {
            return;
        }

        // NOT PICK
        // Agar same value ka duplicate hai,
        // toh same level par duplicate branch skip karo
        int nextIdx = idx + 1;

        while (nextIdx < n && arr[nextIdx] == arr[idx]) {
            nextIdx++;
        }

        solve(arr, n, nextIdx, ans, diary, sum, target);


        // PICK
        diary.push_back(arr[idx]);

        solve(arr, n, idx + 1, ans, diary,
              sum + arr[idx], target);

        diary.pop_back();
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        int n = candidates.size();

        // Sorting is necessary for duplicate handling
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> diary;

        solve(candidates, n, 0, ans, diary, 0, target);

        return ans;
    }
};