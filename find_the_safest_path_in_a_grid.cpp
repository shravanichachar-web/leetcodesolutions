#include <vector>
#include <queue>
#include <algorithm>

class Solution {
private:    
    const int DIRECTIONS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;


        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    safeness[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& dir: DIRECTIONS) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && safeness[nr][nc] == -1 ){
                    safeness[nr][nc] = safeness[r][c] + 1;
                    q.push({nr, nc});
                }
                
                
             }
        }

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        maxHeap.push({safeness[0][0], {0, 0}});
        visited[0][0] = true;

        while (!maxHeap.empty()) {
            auto [currentSafeness, cell] = maxHeap.top();
            auto [r, c] = cell;
            maxHeap.pop();

            if (r == n - 1 && c == n - 1) {
                return currentSafeness;
            }

            for (const auto& dir : DIRECTIONS) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nextSafeness = min(currentSafeness, safeness[nr][nc]);
                    maxHeap.push({nextSafeness, {nr, nc}});
                }

            }
        }

        return 0;

    }
};





