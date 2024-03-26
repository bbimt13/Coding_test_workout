from collections import deque

def solution(maps):
    n, m = len(maps), len(maps[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # 동, 남, 서, 북
    queue = deque([(0, 0, 1)])  # (x, y, 거리)
    visited = [[False] * m for _ in range(n)]
    visited[0][0] = True

    while queue:
        x, y, dist = queue.popleft()
        if x == n - 1 and y == m - 1:  # 목적지에 도달했으면 거리 반환
            return dist

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny, dist + 1))

    return -1  # 목적지에 도달할 수 없으면 -1 반환

# 테스트 케이스
maps1 = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]
maps2 = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]
solution(maps1), solution(maps2)