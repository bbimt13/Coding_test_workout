def solution(n, wires):
    from collections import defaultdict

    def dfs(start, graph, visited):
        # DFS를 사용하여 연결된 노드의 개수를 계산하는 함수
        visited[start] = True
        count = 1
        for next_node in graph[start]:
            if not visited[next_node]:
                count += dfs(next_node, graph, visited)
        return count

    # 그래프 구성
    graph = defaultdict(list)
    for v1, v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)

    # 모든 전선에 대해 하나씩 끊어보며 최소 차이를 구함
    min_diff = n
    for v1, v2 in wires:
        # 전선을 끊고 두 구역의 송전탑 개수를 계산
        graph[v1].remove(v2)
        graph[v2].remove(v1)

        visited = [False] * (n + 1)
        count1 = dfs(v1, graph, visited)

        # 두 구역의 차이 계산
        diff = abs(count1 - (n - count1))
        min_diff = min(min_diff, diff)

        # 전선 복구
        graph[v1].append(v2)
        graph[v2].append(v1)

    return min_diff

# 테스트 케이스
n1, wires1 = 9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]
n2, wires2 = 4, [[1,2],[2,3],[3,4]]
n3, wires3 = 7, [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]
solution(n1, wires1), solution(n2, wires2), solution(n3, wires3)