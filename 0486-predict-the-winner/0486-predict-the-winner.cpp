class Solution {
public:
    bool help(int i, int j, int turn, int score, vector<int>& nums) {

        if (i > j) {
            return score >= 0;
        }

        if (turn) {

            return help(i + 1, j, 0, score - nums[i], nums) &&
                   help(i, j - 1, 0, score - nums[j], nums);

        } else {

            return help(i + 1, j, 1, score + nums[i], nums) ||
                   help(i, j - 1, 1, score + nums[j], nums);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return help(0, n - 1, 0, 0, nums);
        
    }
};