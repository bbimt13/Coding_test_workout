`https://programmers.co.kr/tos`

#coding_test
#coding_test
###### 문제 설명

평면 위에 N개의 직사각형이 놓여있습니다. 직사각형의 각 변은 x축, y축에 평행합니다. 각각의 직사각형은 왼쪽 아래 좌표(x1, y1)과 오른쪽 위 좌표 (x2, y2)를 가지며, (x1, y1, x2, y2)로 나타내고, 서로 겹쳐있을 수 있습니다. 이때 이 직사각형들이 차지하는 면적을 구하려고 합니다. 다음은 N = 5인 경우의 예시입니다.

![직사각형1_n91auy.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/3540f1f7-d7d1-4eba-9d88-3421584e2c5e/%E1%84%8C%E1%85%B5%E1%86%A8%E1%84%89%E1%85%A1%E1%84%80%E1%85%A1%E1%86%A8%E1%84%92%E1%85%A7%E1%86%BC1_n91auy.png)  
위 그림에는 5개의 직사각형 (1, 1, 6, 5), (2, 0, 4, 2), (2, 4, 5, 7), (4, 3, 8, 6), (7, 5, 9, 7) 이 놓여있습니다. 이때 전체 직사각형이 덮고 있는 면적은 아래 그림의 검은 테두리 안쪽의 면적과 같습니다.

![직사각형2_sfgsce.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0fb732a3-5360-44b4-8898-c61fd0566cf3/%E1%84%8C%E1%85%B5%E1%86%A8%E1%84%89%E1%85%A1%E1%84%80%E1%85%A1%E1%86%A8%E1%84%92%E1%85%A7%E1%86%BC2_sfgsce.png)  
따라서 위 예시에서 5개의 직사각형이 덮고 있는 면적은 38이 됩니다.

평면 위에 놓여있는 직사각형들의 좌표가 매개변수 rectangles로 주어질 때, 직사각형들이 덮고 있는 면적의 넓이를 return하도록 solution 합수를 완성해 주세요.

##### 제한사항

- 직사각형의 개수 N : 1 ≤ N ≤ 100,000
- 직사각형의 좌표 x1, y1, x2, y2 : 0 ≤ x1 < x2 ≤ 109 , 0 ≤ y1 < y2 ≤ 109
- x1, y1, x2, y2는 정수

---

##### 입출력 예

|rectangles|result|
|---|---|
|[[0, 1, 4, 4], [3, 1, 5, 3]]|14|
|[[1, 1, 6, 5], [2, 0, 4, 2], [2, 4, 5, 7], [4, 3, 8, 6], [7, 5, 9, 7]]|38|

##### 입출력 예 설명

입출력 예 #1  
직사각형 (0, 1, 4, 4)가 차지하는 면적은 12이며, 직사각형 (3, 1, 5, 3)이 차지하는 면적은 4입니다. 두 직사각형의 겹치는 면적은 2 이기 때문에 전체 면적은 12 + 4 - 2 = 14입니다.

입출력 예 #2  
문제의 예시와 같습니다.
# 문제풀이

### 1. 좌표 정렬 및 매핑

직사각형의 각 변은 x축, y축에 평행하므로, 모든 직사각형의 x좌표와 y좌표를 각각 정렬합니다. 이렇게 정렬된 좌표는 고유한 값을 가지며, 이를 기반으로 겹치는 부분을 계산할 수 있습니다.

``` python
x_coords = sorted({x for rect in rectangles for x in [rect[0], rect[2]]}) y_coords = sorted({y for rect in rectangles for y in [rect[1], rect[3]]})
````

그런 다음 각 좌표에 대해 인덱스를 매핑합니다. 이 인덱스는 격자(grid)에서 해당 좌표의 위치를 나타내며, 직사각형이 겹치는 부분을 계산할 때 사용됩니다.

```python
x_index = {x: i for i, x in enumerate(x_coords)} y_index = {y: i for i, y in enumerate(y_coords)}
```

### 2. 겹치는 부분 계산

직사각형들이 평면 위에서 어떻게 겹치는지 계산하기 위해 격자를 사용합니다. 이 격자는 `x_coords`와 `y_coords`로 정의된 각 좌표에 해당하는 2차원 배열입니다. 격자의 각 셀은 직사각형에 의해 커버되는지 여부를 나타냅니다.

```python
grid = [[0 for _ in range(len(y_coords))] for _ in range(len(x_coords))]
```

각 직사각형에 대해 격자의 셀을 순회하며, 해당 직사각형에 의해 커버되는 경우 셀의 값을 1로 설정합니다.

```python
for x1, y1, x2, y2 in rectangles:
	for i in range(x_index[x1], x_index[x2]):
		for j in range(y_index[y1], y_index[y2]):             
			grid[i][j] = 1
```

### 3. 전체 면적 계산

격자의 각 셀을 순회하며, 셀이 1로 표시되어 있으면 해당 영역이 직사각형에 의해 커버되는 것으로 간주합니다. 이때, 실제 면적을 계산하기 위해 격자 셀의 가로 및 세로 길이(인접한 좌표 간의 차이)를 고려해야 합니다.

```python
area = 0 for i in range(len(x_coords) - 1):
	for j in range(len(y_coords) - 1):         
		if grid[i][j]:             
			area += (x_coords[i + 1] - x_coords[i]) 
						* (y_coords[j + 1] - y_coords[j])
```

이렇게 계산된 `area`는 모든 직사각형이 덮고 있는 총 면적을 나타냅니다.

# 코드
```python
def solution(rectangles):
    # x 좌표와 y 좌표를 분리하여 정렬
    x_coords = sorted({x for rect in rectangles for x in [rect[0], rect[2]]})
    y_coords = sorted({y for rect in rectangles for y in [rect[1], rect[3]]})

    # 좌표를 인덱스로 매핑
    x_index = {x: i for i, x in enumerate(x_coords)}
    y_index = {y: i for i, y in enumerate(y_coords)}

    # 겹치는 부분 계산
    grid = [[0 for _ in range(len(y_coords))] for _ in range(len(x_coords))]

    # 각 직사각형에 대해 겹치는 부분을 표시
    for x1, y1, x2, y2 in rectangles:
        for i in range(x_index[x1], x_index[x2]):
            for j in range(y_index[y1], y_index[y2]):
                grid[i][j] = 1

    # 전체 면적 계산
    area = 0
    for i in range(len(x_coords) - 1):
        for j in range(len(y_coords) - 1):
            if grid[i][j]:
                area += (x_coords[i + 1] - x_coords[i]) * (y_coords[j + 1] - y_coords[j])

    return area

# 입출력 예제 실행
print(solution([[0, 1, 4, 4], [3, 1, 5, 3]]))  # 14
print(solution([[1, 1, 6, 5], [2, 0, 4, 2], [2, 4, 5, 7], [4, 3, 8, 6], [7, 5, 9, 7]]))  # 38
```

## C++

```Cpp
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

```

이 코드는 효율성 테스트를 통과하지 못함. 새로운 알고리즘 필요.

## 문제풀이

1. **이벤트 포인트 생성**: 각 직사각형의 시작점과 끝점을 x좌표에 따라 이벤트로 처리합니다. 이때, 직사각형의 시작을 나타내는 이벤트와 종료를 나타내는 이벤트를 구분해야 합니다.
2. **스위핑 진행**: x좌표를 기준으로 정렬된 이벤트를 순서대로 처리하면서, 각 위치에서 활성화된 직사각형의 y좌표를 관리합니다.
3. **면적 계산**: 스위핑하면서 이전 x좌표와 현재 x좌표 사이의 거리와 활성화된 직사각형의 높이의 합을 곱하여 면적을 계산합니다.

## C++ 코드

```cpp
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
```

이것도 안됨. 시간 날 때 다시 풀어보기.