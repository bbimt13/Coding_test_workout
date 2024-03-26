def solution(money):
    n = len(money)

    # 첫 번째 집을 터는 경우
    dp1 = [0] * n
    dp1[0] = money[0]
    dp1[1] = max(money[0], money[1])
    for i in range(2, n - 1):  # 마지막 집은 털 수 없음
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])

    # 마지막 집을 터는 경우
    dp2 = [0] * n
    dp2[0] = 0  # 첫 번째 집을 털지 않음
    dp2[1] = money[1]
    for i in range(2, n):  # 마지막 집을 털 수 있음
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])

    # 두 경우 중 더 큰 값을 선택
    return max(dp1[n-2], dp2[n-1])

# 테스트 케이스
print(solution([1, 2, 3, 1]))  # 4