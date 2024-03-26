`https://programmers.co.kr/tos`
#BFS #coding_test

# 문제
###### 문제 설명

두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

```
1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
```

예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

##### 제한사항

- 각 단어는 알파벳 소문자로만 이루어져 있습니다.
- 각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
- words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
- begin과 target은 같지 않습니다.
- 변환할 수 없는 경우에는 0를 return 합니다.

##### 입출력 예

|begin|target|words|return|
|---|---|---|---|
|"hit"|"cog"|["hot", "dot", "dog", "lot", "log", "cog"]|4|
|"hit"|"cog"|["hot", "dot", "dog", "lot", "log"]|0|

##### 입출력 예 설명

예제 #1  
문제에 나온 예와 같습니다.

예제 #2  
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.

# 문제풀이

1. [[넓이 우선 탐색(Breadth-First Search)|Breadth-First Search (BFS) 알고리즘]]을 사용하여 최단 경로를 찾습니다.
2. 변환 가능한 단어들 사이의 연결을 [[그래프(Graph)|그래프]]로 표현합니다.
3. `begin`에서 시작하여 `target`에 도달할 때까지 단계별로 탐색을 진행합니다.
4. 각 단계에서 한 글자만 다른 단어로 변환할 수 있는지 확인하고, 가능하면 그 단어로 넘어갑니다.
5. `target` 단어에 도달하면 변환 과정의 수를 반환합니다.