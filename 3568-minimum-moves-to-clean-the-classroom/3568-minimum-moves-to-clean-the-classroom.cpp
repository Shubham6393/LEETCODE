class Solution {
public:

    struct Ele {
        int row;
        int col;
        int energy;
        int mask;
        int steps;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int startRow = -1;
        int startCol = -1;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    startRow = i;
                    startCol = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int allLitterMask = (1 << litterCount) - 1;

        queue<Ele> q;

        q.push({
            startRow,
            startCol,
            energy,
            0,
            0 
        });

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[startRow][startCol][energy][0] = true;

        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};

        while (!q.empty()) {

            Ele cur = q.front();
            q.pop();

            if (cur.mask == allLitterMask) {
                return cur.steps;
            }

            for (int dir = 0; dir < 4; dir++) {

                int x = cur.row + dx[dir];
                int y = cur.col + dy[dir];

                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (classroom[x][y] == 'X') {
                    continue;
                }

                if (cur.energy == 0) {
                    continue;
                }

                int newEnergy = cur.energy - 1;

                int newMask = cur.mask;

                if (classroom[x][y] == 'R') {
                    newEnergy = energy;
                }

                if (classroom[x][y] == 'L') {

                    int id = litterId[x][y];

                    newMask = newMask | (1 << id);
                }

                if (!visited[x][y][newEnergy][newMask]) {

                    visited[x][y][newEnergy][newMask] = true;

                    q.push({
                        x,
                        y,
                        newEnergy,
                        newMask,
                        cur.steps + 1
                    });
                }
            }
        }

        return -1;
    }
};