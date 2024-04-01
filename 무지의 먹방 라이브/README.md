`https://programmers.co.kr/tos`

#coding_test #2019_KAKAO_BLIND_RECRUITMENT

# 문제
###### 문제 설명

## 무지의 먹방 라이브

`* 효율성 테스트에 부분 점수가 있는 문제입니다.`

평소 식욕이 왕성한 무지는 자신의 재능을 뽐내고 싶어 졌고 고민 끝에 카카오 TV 라이브로 방송을 하기로 마음먹었다.

![muji_live.png](https://grepp-programmers.s3.amazonaws.com/files/production/10f4f72c93/1d932bfc-8082-4b7e-b30d-ab46bf71a9f2.png)

그냥 먹방을 하면 다른 방송과 차별성이 없기 때문에 무지는 아래와 같이 독특한 방식을 생각해냈다.

회전판에 먹어야 할 N 개의 음식이 있다.  
각 음식에는 1부터 N 까지 번호가 붙어있으며, 각 음식을 섭취하는데 일정 시간이 소요된다.  
무지는 다음과 같은 방법으로 음식을 섭취한다.

- 무지는 1번 음식부터 먹기 시작하며, 회전판은 번호가 증가하는 순서대로 음식을 무지 앞으로 가져다 놓는다.
- 마지막 번호의 음식을 섭취한 후에는 회전판에 의해 다시 1번 음식이 무지 앞으로 온다.
- 무지는 음식 하나를 1초 동안 섭취한 후 남은 음식은 그대로 두고, 다음 음식을 섭취한다.
    - 다음 음식이란, 아직 남은 음식 중 다음으로 섭취해야 할 가장 가까운 번호의 음식을 말한다.
- 회전판이 다음 음식을 무지 앞으로 가져오는데 걸리는 시간은 없다고 가정한다.

무지가 먹방을 시작한 지 K 초 후에 네트워크 장애로 인해 방송이 잠시 중단되었다.  
무지는 네트워크 정상화 후 다시 방송을 이어갈 때, 몇 번 음식부터 섭취해야 하는지를 알고자 한다.  
각 음식을 모두 먹는데 필요한 시간이 담겨있는 배열 food_times, 네트워크 장애가 발생한 시간 K 초가 매개변수로 주어질 때 몇 번 음식부터 다시 섭취하면 되는지 return 하도록 solution 함수를 완성하라.

##### 제한사항

- food_times 는 각 음식을 모두 먹는데 필요한 시간이 음식의 번호 순서대로 들어있는 배열이다.
- k 는 방송이 중단된 시간을 나타낸다.
- 만약 더 섭취해야 할 음식이 없다면 `-1`을 반환하면 된다.

##### 정확성 테스트 제한 사항

- food_times 의 길이는 `1` 이상 `2,000` 이하이다.
- food_times 의 원소는 `1` 이상 `1,000` 이하의 자연수이다.
- k는 `1` 이상 `2,000,000` 이하의 자연수이다.

##### 효율성 테스트 제한 사항

- food_times 의 길이는 `1` 이상 `200,000` 이하이다.
- food_times 의 원소는 `1` 이상 `100,000,000` 이하의 자연수이다.
- k는 `1` 이상 `2 x 10^13` 이하의 자연수이다.

##### 입출력 예

|food_times|k|result|
|---|---|---|
|[3, 1, 2]|5|1|

##### 입출력 예 설명

입출력 예 #1

- 0~1초 동안에 1번 음식을 섭취한다. 남은 시간은 [2,1,2] 이다.
- 1~2초 동안 2번 음식을 섭취한다. 남은 시간은 [2,0,2] 이다.
- 2~3초 동안 3번 음식을 섭취한다. 남은 시간은 [2,0,1] 이다.
- 3~4초 동안 1번 음식을 섭취한다. 남은 시간은 [1,0,1] 이다.
- 4~5초 동안 (2번 음식은 다 먹었으므로) 3번 음식을 섭취한다. 남은 시간은 [1,0,0] 이다.
- 5초에서 네트워크 장애가 발생했다. 1번 음식을 섭취해야 할 때 중단되었으므로, 장애 복구 후에 1번 음식부터 다시 먹기 시작하면 된다.
# 문제풀이

1. 모든 음식을 시간 순서대로 정렬합니다.
2. 시간 `K` 동안 먹을 수 있는 음식의 수를 찾습니다.
3. `K` 초 후에 어떤 음식을 먹어야 하는지 결정합니다.

다음은 이를 구현하는 알고리즘입니다:

1. `food_times` 배열의 각 요소에 대해 `food_times[i]`는 `i+1`번 음식을 먹는데 필요한 시간을 나타냅니다.
2. 모든 음식을 시간 별로 정렬하고, 이를 통해 가장 빨리 먹을 수 있는 음식부터 차례대로 먹습니다.
3. `k` 초 동안 먹을 수 있는 음식을 찾아 그 시간 동안 모든 음식을 한 번씩 먹습니다.
4. 남은 `k` 초 내에 먹어야 할 음식의 위치를 정확히 찾습니다.

# 코드
```python
def solution(food_times, k):
    if sum(food_times) <= k:
        return -1  # 모든 음식을 먹는 시간보다 k가 크거나 같으면 더 이상 먹을 음식이 없다.

    # 음식 시간과 원래 인덱스를 함께 저장
    foods = sorted([(time, index) for index, time in enumerate(food_times)])

    total_time = 0  # 총 소요 시간
    previous_time = 0  # 이전 음식까지의 소요 시간
    for i, (time, index) in enumerate(foods):
        # 현재 음식까지 먹는데 필요한 총 시간
        # 여기서 time - previous_time은 남은 음식을 먹는데 필요한 시간
        # len(foods) - i는 남은 음식의 수
        difference = time - previous_time
        if difference * (len(foods) - i) <= k:
            k -= difference * (len(foods) - i)
            total_time += difference
            previous_time = time
        else:
            # 남은 k로 몇 번째 음식을 먹을 수 있는지 찾기
            k %= len(foods) - i
            return sorted(foods[i:], key=lambda x: x[1])[k][1] + 1

# 테스트 케이스
solution([3, 1, 2], 5)
```

## C++

```Cpp
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
```

# 점수

정확성  테스트

|   |   |
|---|---|
|테스트 1 〉|통과 (0.01ms, 4.22MB)|
|테스트 2 〉|통과 (0.01ms, 3.58MB)|
|테스트 3 〉|통과 (0.01ms, 4.23MB)|
|테스트 4 〉|통과 (0.01ms, 4.19MB)|
|테스트 5 〉|통과 (0.01ms, 4.18MB)|
|테스트 6 〉|통과 (0.01ms, 3.65MB)|
|테스트 7 〉|통과 (0.01ms, 4.15MB)|
|테스트 8 〉|통과 (0.01ms, 4.19MB)|
|테스트 9 〉|통과 (0.01ms, 4.21MB)|
|테스트 10 〉|통과 (0.01ms, 3.71MB)|
|테스트 11 〉|통과 (0.01ms, 4.21MB)|
|테스트 12 〉|통과 (0.02ms, 4.22MB)|
|테스트 13 〉|통과 (0.01ms, 4.16MB)|
|테스트 14 〉|통과 (0.01ms, 3.68MB)|
|테스트 15 〉|통과 (0.01ms, 3.67MB)|
|테스트 16 〉|통과 (0.01ms, 4.21MB)|
|테스트 17 〉|통과 (0.01ms, 4.15MB)|
|테스트 18 〉|통과 (0.01ms, 3.67MB)|
|테스트 19 〉|통과 (0.01ms, 4.19MB)|
|테스트 20 〉|통과 (0.01ms, 4.2MB)|
|테스트 21 〉|통과 (0.02ms, 4.17MB)|
|테스트 22 〉|통과 (0.03ms, 4.2MB)|
|테스트 23 〉|통과 (0.02ms, 4.13MB)|
|테스트 24 〉|통과 (0.19ms, 4.22MB)|
|테스트 25 〉|통과 (0.27ms, 3.72MB)|
|테스트 26 〉|통과 (0.25ms, 3.69MB)|
|테스트 27 〉|통과 (0.26ms, 3.73MB)|
|테스트 28 〉|통과 (0.01ms, 3.61MB)|
|테스트 29 〉|통과 (0.01ms, 4.22MB)|
|테스트 30 〉|통과 (0.01ms, 4.12MB)|
|테스트 31 〉|통과 (0.01ms, 4.15MB)|
|테스트 32 〉|통과 (0.01ms, 4.14MB)|

효율성  테스트

|   |   |
|---|---|
|테스트 1 〉|통과 (26.68ms, 12.3MB)|
|테스트 2 〉|통과 (7.13ms, 12.4MB)|
|테스트 3 〉|통과 (22.36ms, 12.3MB)|
|테스트 4 〉|통과 (23.36ms, 12.3MB)|
|테스트 5 〉|통과 (25.75ms, 12.3MB)|
|테스트 6 〉|통과 (26.46ms, 12.2MB)|
|테스트 7 〉|통과 (27.45ms, 12.3MB)|
|테스트 8 〉|통과 (29.21ms, 12.3MB)|

채점 결과

정확성: 42.9

효율성: 57.1

합계: 100.0 / 100.0