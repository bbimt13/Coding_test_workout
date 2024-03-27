#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Event {
    int x, y1, y2, type;
    Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
};

bool compareEvent(const Event &a, const Event &b) {
    return a.x < b.x;
}

long long solution(vector<vector<int>> rectangles) {
    vector<Event> events;
    multimap<int, int> activeRects; // 활성화된 직사각형의 y 좌표를 저장

    for (auto &rect : rectangles) {
        events.emplace_back(rect[0], rect[1], rect[3], 1);  // 시작 이벤트
        events.emplace_back(rect[2], rect[1], rect[3], -1); // 종료 이벤트
    }

    sort(events.begin(), events.end(), compareEvent);

    long long area = 0;
    int lastX = 0;
    for (auto &event : events) {
        int width = event.x - lastX;

        if (!activeRects.empty()) {
            int height = 0;
            int lastY = -1;
            for (auto &interval : activeRects) {
                if (lastY != -1) height += interval.first - lastY;
                lastY = interval.first;
            }
            area += (long long)width * height;
        }

        if (event.type == 1) {
            activeRects.insert({event.y1, 1});
            activeRects.insert({event.y2, -1});
        } else {
            auto it = activeRects.lower_bound(event.y1);
            activeRects.erase(it);
            it = activeRects.lower_bound(event.y2);
            activeRects.erase(it);
        }

        lastX = event.x;
    }

    return area;
}

int main() {
    vector<vector<int>> rectangles = {{0, 1, 4, 4}, {3, 1, 5, 3}};
    cout << solution(rectangles) << endl;  // 14

    rectangles = {{1, 1, 6, 5}, {2, 0, 4, 2}, {2, 4, 5, 7}, {4, 3, 8, 6}, {7, 5, 9, 7}};
    cout << solution(rectangles) << endl;  // 38

    return 0;
}
