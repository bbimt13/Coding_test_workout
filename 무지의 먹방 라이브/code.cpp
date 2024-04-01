#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long total_time = 0;
    for (int time : food_times) {
        total_time += time;
    }

    if (total_time <= k) {
        return -1;
    }

    // 음식 시간과 인덱스를 함께 저장하는 pair 벡터 생성
    vector<pair<int, int>> foods;
    for (int i = 0; i < food_times.size(); i++) {
        foods.push_back({food_times[i], i + 1});
    }

    // 음식을 시간순으로 정렬
    sort(foods.begin(), foods.end());

    total_time = 0;
    long long previous_time = 0;
    long long remaining = foods.size();

    for (int i = 0; i < foods.size(); i++) {
        long long difference = foods[i].first - previous_time;
        if (difference * remaining <= k) {
            k -= difference * remaining;
            total_time += difference;
            previous_time = foods[i].first;
        } else {
            k %= remaining;
            // 인덱스 순으로 다시 정렬하여 k번째 음식 찾기
            sort(foods.begin() + i, foods.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            });
            return foods[i + k].second;
        }
        remaining--;
    }

    return -1;  // 이론적으로 여기에 도달할 수 없음
}

// 예제 사용
int main() {
    vector<int> food_times = {3, 1, 2};
    long long k = 5;
    int result = solution(food_times, k);
    return 0;  // result는 1이 될 것입니다
}