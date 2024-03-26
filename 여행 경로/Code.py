def solution(tickets):
    # 항공권 정보를 기반으로 그래프 생성, 각 노드(공항)에서 출발하는 항공권을 정렬
    graph = {}
    for ticket in tickets:
        if ticket[0] in graph:
            graph[ticket[0]].append(ticket[1])
        else:
            graph[ticket[0]] = [ticket[1]]
    for key in graph.keys():
        graph[key].sort(reverse=True)

    route = []  # 경로 저장
    stack = ["ICN"]  # 시작점

    while stack:
        top = stack[-1]
        # 현재 공항에서 출발하는 항공권이 있으면 사용
        if top in graph and graph[top]:
            stack.append(graph[top].pop())
        else:
            route.append(stack.pop())  # 더 이상 갈 곳이 없으면 경로에 추가

    return route[::-1]  # 완성된 경로를 뒤집어서 반환

# 테스트 케이스
tickets1 = [["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]
tickets2 = [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
solution(tickets1), solution(tickets2)