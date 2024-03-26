from collections import deque

def solution(begin, target, words):
    if target not in words:  # target이 words에 없으면 변환 불가
        return 0

    def one_letter_diff(w1, w2):
        # 두 단어가 한 글자만 다른지 확인하는 함수
        return sum(c1 != c2 for c1, c2 in zip(w1, w2)) == 1

    def bfs():
        # 너비 우선 탐색(BFS)을 이용한 최단 경로 탐색
        queue = deque([(begin, 0)])  # (현재 단어, 단계 수)
        visited = {begin}  # 방문한 단어 집합
        while queue:
            current_word, steps = queue.popleft()
            if current_word == target:
                return steps  # target에 도달하면 단계 수 반환
            for word in words:
                if word not in visited and one_letter_diff(current_word, word):
                    queue.append((word, steps + 1))
                    visited.add(word)
        return 0  # target에 도달할 수 없는 경우

    return bfs()

# 테스트 케이스
begin1, target1, words1 = "hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]
begin2, target2, words2 = "hit", "cog", ["hot", "dot", "dog", "lot", "log"]
solution(begin1, target1, words1), solution(begin2, target2, words2)
