class Solution {
public:

    struct Node {
        long long weight;
        vector<int> indices;
    };

    vector<vector<Node>> dp;

    vector<array<long long, 4>> arr;

    Node solve(int i, int k, vector<array<long long, 4>>& intervals) {

        // No more intervals or no more selections
        if (i == intervals.size() || k == 0) {
            return {0, {}};
        }

        // Already calculated
        if (dp[i][k].weight != -1) {
            return dp[i][k];
        }

        // -------------------------
        // 1. Skip current interval
        // -------------------------
        Node skip = solve(i + 1, k, intervals);

        // -------------------------
        // 2. Pick current interval
        // -------------------------

        long long l = intervals[i][0];
        long long r = intervals[i][1];
        long long weight = intervals[i][2];
        int originalIndex = intervals[i][3];

        // Find first interval whose start > r
        int low = i + 1;
        int high = intervals.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (intervals[mid][0] > r) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int next = low;

        Node nextNode = solve(next, k - 1, intervals);

        Node pick;

        pick.weight = weight + nextNode.weight;

        pick.indices = nextNode.indices;
        pick.indices.push_back(originalIndex);

        // Required answer is lexicographically smallest
        sort(pick.indices.begin(), pick.indices.end());

        // -------------------------
        // Compare Pick vs Skip
        // -------------------------

        if (pick.weight > skip.weight) {
            return dp[i][k] = pick;
        }

        if (pick.weight < skip.weight) {
            return dp[i][k] = skip;
        }

        // Same weight
        if (pick.indices < skip.indices) {
            return dp[i][k] = pick;
        }

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<array<long long, 4>> arr;

        // Store:
        // {start, end, weight, originalIndex}

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start
        sort(arr.begin(), arr.end());

        // dp[n][5]
        dp.assign(n, vector<Node>(5, {-1, {}}));

        return solve(0, 4, arr).indices;
    }
};