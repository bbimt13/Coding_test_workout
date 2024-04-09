#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

vector<int> find_path(int m, int n, int s, vector<vector<int>>& time_map) {
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> queue;
    queue.push(make_tuple(0, 0, 0, 0));

    vector<vector<pair<int, int>>> visited(m, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    visited[0][0] = {0, 0};

    while (!queue.empty()) {
        tuple<int, int, int, int> current = queue.top();
        queue.pop();

        int conversation = get<0>(current);
        int length = get<1>(current);
        int x = get<2>(current);
        int y = get<3>(current);

        if (x == m - 1 && y == n - 1) {
            return {length, conversation};
        }

        for (auto &d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && time_map[nx][ny] != -1) {
                int next_conversation = conversation + time_map[nx][ny];
                if (next_conversation <= s && visited[nx][ny].second > length + 1) {
                    visited[nx][ny] = {next_conversation, length + 1};
                    queue.push(make_tuple(next_conversation, length + 1, nx, ny));
                }
            }
        }
    }

    return {0, 0}; // 경로가 없는 경우
}

int main() {
    vector<vector<int>> time_map1 = {{0, 2, 99}, {100, 100, 4}, {1, 2, 0}};
    vector<vector<int>> time_map2 = {{0, 1, 1, -1, 2, 4}, {-1, 7, 2, 1, 5, 7}, {-1, 1, -1, 1, 6, 3}, {-1, 1, -1, -1, 7, 0}};
    vector<vector<int>> time_map3 = {{0, 1, 1, 1, 1}, {9, 9, 9, 1, 9}, {1, 1, 1, 1, 9}, {1, 1, 5, 9, 9}, {1, 1, 1, 1, 0}};

    vector<int> answer1 = find_path(3, 3, 150, time_map1);
    vector<int> answer2 = find_path(4, 6, 25, time_map2);
    vector<int> answer3 = find_path(5, 5, 12, time_map3);

    cout << "Answer 1: [" << answer1[0] << ", " << answer1[1] << "]" << endl;
    cout << "Answer 2: [" << answer2[0] << ", " << answer2[1] << "]" << endl;
    cout << "Answer 3: [" << answer3[0] << ", " << answer3[1] << "]" << endl;

    return 0;
}
