from itertools import combinations_with_replacement
def solution(k, n, reqs):
    # 필요한 초기 변수 설정
    min_wait_time = float('inf')
    
    # 모든 가능한 멘토 배정을 생성 (각 상담 유형별로 최소 한 명의 멘토가 있어야 함)
    for mentors in combinations_with_replacement(range(k), n - k):
        # 각 유형에 대한 초기 배정 (최소 한 명씩 할당)
        mentor_count = [1] * k
        for mentor in mentors:
            mentor_count[mentor] += 1

        # 각 유형별로 멘토 할당 및 시간 계산을 위한 구조 생성
        mentor_available_time = [[0] * count for count in mentor_count]
        total_wait_time = 0
        for req in reqs:
            request_time, duration, type_id = req
            type_id -= 1  # 유형을 0부터 시작하는 인덱스로 조정

            # 해당 유형에 대한 가장 빠르게 사용 가능한 멘토 찾기
            earliest_end_time = min(mentor_available_time[type_id])
            mentor_index = mentor_available_time[type_id].index(earliest_end_time)
            wait_time = max(0, earliest_end_time - request_time)
            total_wait_time += wait_time

            # 멘토의 사용 가능 시간 업데이트
            mentor_available_time[type_id][mentor_index] = max(earliest_end_time, request_time) + duration

        # 최소 대기 시간 찾기
        if total_wait_time < min_wait_time:
            min_wait_time = total_wait_time

    return min_wait_time

# 테스트 케이스 실행
print(solution(3, 5, [[10, 60, 1], [15, 100, 3], [20, 30, 1], [30, 50, 3], [50, 40, 1], [60, 30, 2], [65, 30, 1], [70, 100, 2]]))
print(solution(2, 3, [[5, 55, 2], [10, 90, 2], [20, 40, 2], [50, 45, 2], [100, 50, 2]]))
