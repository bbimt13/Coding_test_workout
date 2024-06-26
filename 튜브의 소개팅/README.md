`https://programmers.co.kr/tos`

#coding_test #2019_KAKAO_BLIND_RECRUITMENT

# 문제
###### 문제 설명

## 튜브의 소개팅

![Tube 1](https://t1.kakaocdn.net/codefestival/tube1.png)  
얼마 전 소개팅에 실패해 낙담한 튜브를 안타깝게 여긴 친구들은 튜브에게 새로운 사람을 소개해주기로 했다. 좀 더 자연스러운 자리를 만들기 위해, 튜브와 소개팅녀를 파티에 초대하기로 했다.

친구들은 튜브에게 파티에 초대된 모든 사람의 위치를 알려주었다. 사각형 모양의 파티장 입구는 왼쪽 맨 위였고, 만나야 하는 상대의 좌석은 파티장의 오른쪽 맨 아래였다. 파티장의 가로 길이가 `n`이라고 하고, 세로 길이를 `m`이라 할 때, 튜브와 소개팅 상대의 위치는 각각, `(0, 0)`, `(m - 1, n - 1)`이 된다.

튜브는 `(0, 0)`에서 `(m - 1, n - 1)`까지 가는 가장 짧은 길을 알고 싶다. 이동은 `좌/우/상/하`로만 가능하다. 또한, 조금이라도 더 빠르게 이동하고 싶은 튜브는 이동하는 중에 가능한 덜 수다스러운 친구들만 만나고 싶다. 다시 말해, 목표 지점까지 길이가 같은 여러 개의 경로가 존재할 경우, 경로상에 위치한 친구들과 나눠야 하는 대화 시간의 합이 적은 것을 더 선호한다.

튜브에게는 스트레스를 심하게 받을 경우 미친 오리로 변하는 비밀이 있다. 경로 상에 위치한 친구들과 나눠야 하는 대화 시간의 합이 `s`를 초과한다면 미친 오리로 변하고 소개팅에 실패하고 말 것이다! 그러므로 아무리 짧은 경로라도 친구들과 나눠야 하는 대화 시간의 합이 `s`를 초과한다면 그 경로를 진행할 수는 없다.  
![Tube 2](https://t1.kakaocdn.net/codefestival/tube2.png)  
튜브가 소개팅 상대에게 무사히 갈 수 있는 경로를 알려주자.

### 입력 형식

입력은 파티장의 크기 `m`과 `n` 그리고 튜브가 참을 수 있는 대화 시간의 총합 `s`, 친구와의 대화에 필요한 시간 `t`가 담긴 2차원 배열 `time_map`으로 주어진다. `t`가 `-1`인 경우는 파티 테이블이 위치한 경우라 지나갈 수 없다. 그리고 시작 지점과 도착 지점에서는 수다에 필요한 시간이 없다, 즉 `t = 0`이다.  
추가 제한조건은 아래와 같다.

- `2 <= n, m <= 50`
- `1 <= s <= 2^31-1`
- `-1 <= t <= 2^31-1`
- 모든 입력에는 문제의 조건을 만족하는 경로가 하나 이상 존재한다.

### 출력 형식

리턴 타입은 원소가 두 개인 정수 배열이다. 튜브가 이동해야 하는 경로의 길이와 해당 경로를 지나갈 때 친구와 나눠야 하는 대화 시간의 총합을 리턴한다.

### 예제 입출력

| m   | n   | s   | time_map                                                                                | answer   |
| --- | --- | --- | --------------------------------------------------------------------------------------- | -------- |
| 3   | 3   | 150 | [[0, 2, 99], [100, 100, 4], [1, 2, 0]]                                                  | [4, 103] |
| 4   | 6   | 25  | [[0, 1, 1, -1, 2, 4], [-1, 7, 2, 1, 5, 7], [-1, 1, -1, 1, 6, 3], [-1, 1, -1, -1, 7, 0]] | [8, 15]  |
| 5   | 5   | 12  | [[0, 1, 1, 1, 1], [9, 9, 9, 1, 9], [1, 1, 1, 1, 9], [1, 1, 5, 9, 9], [1, 1, 1, 1, 0]]   | [12, 11] |
# 문제풀이

BFS (Breadth-First Search): 이 방법을 사용하여 각 단계마다 모든 가능한 위치를 탐색한다. 이 때, 각 위치에서의 경로 길이와 대화 시간의 총합을 기록한다. 

Priority Queue: BFS를 진행하면서 가능한 경로를 우선순위 큐에 저장한다. 여기서 우선순위는 먼저 대화 시간의 합이 작은 것, 그 다음으로 경로의 길이가 짧은 것으로 설정한다.
