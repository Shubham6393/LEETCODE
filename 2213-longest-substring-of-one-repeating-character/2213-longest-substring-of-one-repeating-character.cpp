class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
    };

    vector<Node> tree;


    // --------------------------------------------------
    // MERGE
    // --------------------------------------------------
    Node merge(Node left, Node right, int leftLength, int rightLength) {

        Node parent;

        // Character at the beginning and end
        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;


        // -------------------------
        // Prefix
        // -------------------------

        parent.prefix = left.prefix;

        // If entire left part is same character
        // and boundary characters are same
        if (left.prefix == leftLength &&
            left.rightChar == right.leftChar) {

            parent.prefix = left.prefix + right.prefix;
        }


        // -------------------------
        // Suffix
        // -------------------------

        parent.suffix = right.suffix;

        // If entire right part is same character
        // and boundary characters are same
        if (right.suffix == rightLength &&
            left.rightChar == right.leftChar) {

            parent.suffix = left.suffix + right.suffix;
        }


        // -------------------------
        // Best
        // -------------------------

        // Best completely inside left or right
        parent.best = max(left.best, right.best);


        // Best substring crossing the boundary
        if (left.rightChar == right.leftChar) {

            parent.best = max(
                parent.best,
                left.suffix + right.prefix
            );
        }


        return parent;
    }


    // --------------------------------------------------
    // BUILD
    // --------------------------------------------------
    void build(int node, int low, int high, string &s) {

        // Base case: leaf node
        if (low == high) {

            tree[node].leftChar = s[low];
            tree[node].rightChar = s[low];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }


        int mid = low + (high - low) / 2;


        // Build left child
        build(2 * node, low, mid, s);

        // Build right child
        build(2 * node + 1, mid + 1, high, s);


        // Length of left and right segments
        int leftLength = mid - low + 1;
        int rightLength = high - mid;


        // Merge children
        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1],
            leftLength,
            rightLength
        );
    }


    // --------------------------------------------------
    // UPDATE
    // --------------------------------------------------
    void update(int node, int low, int high,
                int index, char ch) {

        // We reached the required index
        if (low == high) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }


        int mid = low + (high - low) / 2;


        // Find the side containing index
        if (index <= mid) {

            update(
                2 * node,
                low,
                mid,
                index,
                ch
            );

        } else {

            update(
                2 * node + 1,
                mid + 1,
                high,
                index,
                ch
            );
        }


        // Length of left and right segments
        int leftLength = mid - low + 1;
        int rightLength = high - mid;


        // Recalculate current node
        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1],
            leftLength,
            rightLength
        );
    }


    // --------------------------------------------------
    // MAIN FUNCTION
    // --------------------------------------------------
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.length();

        tree.resize(4 * n);


        vector<int> ans;


        // Build segment tree
        build(
            1,
            0,
            n - 1,
            s
        );


        // Process every query
        for (int i = 0;
             i < queryIndices.size();
             i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];


            // Update segment tree
            update(
                1,
                0,
                n - 1,
                index,
                ch
            );


            // Root contains answer for entire string
            ans.push_back(tree[1].best);
        }


        return ans;
    }
};