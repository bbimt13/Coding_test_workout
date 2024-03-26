def solution(word):
    # 알파벳 순서에 따른 가중치 설정
    weight = {'A': 0, 'E': 1, 'I': 2, 'O': 3, 'U': 4}
    # 각 자리수마다 증가하는 값 (5진법을 생각하되, 각 자리수마다 가중치 적용)
    increments = [781, 156, 31, 6, 1]
    total = 0

    for i, char in enumerate(word):
        # 해당 자리수의 알파벳 가중치와 증가값을 곱하여 총합에 더함
        total += weight[char] * increments[i] + 1  # 각 단어는 1부터 시작하므로 1을 더함

    return total

# 테스트 케이스
print(solution("AAAAE"))  # 6
print(solution("AAAE"))   # 10
print(solution("I"))      # 1563
print(solution("EIO"))    # 1189