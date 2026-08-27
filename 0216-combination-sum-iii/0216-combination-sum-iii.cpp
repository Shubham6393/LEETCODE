class Solution {
public:
    void solve(int idx, int k, int n, int sum, vector<vector<int>> &ans, vector<int> diary){
        if(k==0){
            if(sum == n){
                ans.push_back(diary);
            }
            return;
        }

        

        for(int i = idx; i <= 9; i++){
            diary.push_back(i);
            solve(i+1,k-1,n,sum+i,ans,diary);

            diary.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> diary;
        solve(1, k, n, 0, ans, diary);
        
        return ans;
    }
};