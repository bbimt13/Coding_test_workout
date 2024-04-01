from math import comb  # 조합 함수를 사용하기 위해 comb를 임포트합니다.

def catalan_number(n):
    # n번째 Catalan 수를 계산하는 함수입니다.
    return comb(2 * n, n) // (n + 1)

def solution(n):
    # n개의 괄호 쌍으로 만들 수 있는 모든 가능한 괄호 문자열의 개수를 반환합니다.
    return catalan_number(n)

# 테스트 케이스
print(solution(2))  # 2개의 괄호쌍으로 만들 수 있는 경우의 수: 2
print(solution(3))  # 3개의 괄호쌍으로 만들 수 있는 경우의 수: 5