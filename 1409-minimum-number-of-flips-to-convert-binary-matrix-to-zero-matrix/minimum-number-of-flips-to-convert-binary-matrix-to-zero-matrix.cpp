
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int start = 0;

        // Convert the matrix into a bitmask.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int pos = i * n + j;
                    start |= (1 << pos);
                }
            }
        }

        // Already all zeros.
        if (start == 0) {
            return 0;
        }

        vector<vector<int>> directions = {
            {0, 0},    // Current cell
            {-1, 0},   // Up
            {1, 0},    // Down
            {0, -1},   // Left
            {0, 1}     // Right
        };

        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int flips = 0;

        while (!q.empty()) {
            int sz = q.size();

            // Process one BFS level.
            while (sz--) {
                int state = q.front();
                q.pop();

                if (state == 0) {
                    return flips;
                }

                // Try flipping every cell.
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        int nextState = state;

                        // Flip the cell and its valid neighbors.
                        for (auto& d : directions) {
                            int r = i + d[0];
                            int c = j + d[1];

                            if (r >= 0 && r < m &&
                                c >= 0 && c < n) {
                                int pos = r * n + c;
                                nextState ^= (1 << pos);
                            }
                        }

                        if (!visited.count(nextState)) {
                            visited.insert(nextState);
                            q.push(nextState);
                        }
                    }
                }
            }

            flips++;
        }

        return -1;
    }
};
