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