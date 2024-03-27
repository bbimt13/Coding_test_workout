#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long solution(vector<vector<int>> rectangles) {
    set<int> x_set, y_set;

    // x, y 좌표를 집합에 추가
    for (auto& rect : rectangles) {
        x_set.insert(rect[0]);
        x_set.insert(rect[2]);
        y_set.insert(rect[1]);
        y_set.insert(rect[3]);
    }

    // 좌표를 벡터로 변환하고 정렬
    vector<int> x_coords(x_set.begin(), x_set.end()), y_coords(y_set.begin(), y_set.end());

    // 겹치는 부분을 계산하기 위한 2차원 벡터
    vector<vector<bool>> grid(x_coords.size(), vector<bool>(y_coords.size(), false));

    // 직사각형들의 겹치는 부분 표시
    for (auto& rect : rectangles) {
        int x1 = lower_bound(x_coords.begin(), x_coords.end(), rect[0]) - x_coords.begin();
        int x2 = lower_bound(x_coords.begin(), x_coords.end(), rect[2]) - x_coords.begin();
        int y1 = lower_bound(y_coords.begin(), y_coords.end(), rect[1]) - y_coords.begin();
        int y2 = lower_bound(y_coords.begin(), y_coords.end(), rect[3]) - y_coords.begin();
        for (int i = x1; i < x2; ++i) {
            for (int j = y1; j < y2; ++j) {
                grid[i][j] = true;
            }
        }
    }

    // 전체 면적 계산
    long long area = 0;
    for (int i = 0; i < x_coords.size() - 1; ++i) {
        for (int j = 0; j < y_coords.size() - 1; ++j) {
            if (grid[i][j]) {
                area += (long long)(x_coords[i + 1] - x_coords[i]) * (y_coords[j + 1] - y_coords[j]);
            }
        }
    }

    return area;
}

int main() {
    vector<vector<int>> rectangles = {{0, 1, 4, 4}, {3, 1, 5, 3}};
    cout << solution(rectangles) << endl;  // 기대 출력: 14

    rectangles = {{1, 1, 6, 5}, {2, 0, 4, 2}, {2, 4, 5, 7}, {4, 3, 8, 6}, {7, 5, 9, 7}};
    cout << solution(rectangles) << endl;  // 기대 출력: 38

    return 0;
}