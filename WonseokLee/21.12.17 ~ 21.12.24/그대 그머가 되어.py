import heapq

a, b = map(int, input().split())
N, M = map(int, input().split())
INF = int(1e9)

graph = [[] for _ in range(N + 1)]

for i in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)


def dijikstra(start, end):
    q = []
    heapq.heappush(q, (0, start))
    distance = [INF] * (N + 1)

    # 시작지점의 dist 는 0으로 치환
    distance[start] = 0

    while q:
        dist, now_node = heapq.heappop(q)

        for g in graph[now_node]:
            next_node = g
            cost = dist + 1
            if cost < distance[next_node]:
                heapq.heappush(q, (cost, next_node))
                distance[next_node] = cost

    if distance[end] == INF:
        return -1
    else:
        return distance[end]


print(dijikstra(a, b))

