def solution(rectangles):
    # x 좌표와 y 좌표를 분리하여 정렬
    x_coords = sorted({x for rect in rectangles for x in [rect[0], rect[2]]})
    y_coords = sorted({y for rect in rectangles for y in [rect[1], rect[3]]})

    # 좌표를 인덱스로 매핑
    x_index = {x: i for i, x in enumerate(x_coords)}
    y_index = {y: i for i, y in enumerate(y_coords)}

    # 겹치는 부분 계산
    grid = [[0 for _ in range(len(y_coords))] for _ in range(len(x_coords))]

    # 각 직사각형에 대해 겹치는 부분을 표시
    for x1, y1, x2, y2 in rectangles:
        for i in range(x_index[x1], x_index[x2]):
            for j in range(y_index[y1], y_index[y2]):
                grid[i][j] = 1

    # 전체 면적 계산
    area = 0
    for i in range(len(x_coords) - 1):
        for j in range(len(y_coords) - 1):
            if grid[i][j]:
                area += (x_coords[i + 1] - x_coords[i]) * (y_coords[j + 1] - y_coords[j])

    return area

# 입출력 예제 실행
print(solution([[0, 1, 4, 4], [3, 1, 5, 3]]))  # 14
print(solution([[1, 1, 6, 5], [2, 0, 4, 2], [2, 4, 5, 7], [4, 3, 8, 6], [7, 5, 9, 7]]))  # 38
