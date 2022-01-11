import heapq

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
case = []
INF = int(1e9)
max_time = 0


def delay_dijikstra(n):
    q = []
    heapq.heappush(q, [1, 0])
    distance = [INF] * (N + 1)
    distance[1] = 0

    while q:
        now_node, dist = heapq.heappop(q)

        for g in graph[now_node]:
            next_node, time = g[0], g[1]

            if now_node == case[n][0] and next_node == case[n][1]:
                cost = -1
            elif now_node == case[n][1] and now_node == case[n][0]:
                cost = -1
            else:
                cost = dist + time

            if cost == -1:
                continue

            elif cost != -1 and distance[next_node] > cost:
                distance[next_node] = cost
                heapq.heappush(q, [next_node, cost])

    return distance


def dijikstra():
    q = []
    heapq.heappush(q, [1, 0])
    distance = [INF] * (N + 1)
    distance[1] = 0

    while q:
        now_node, dist = heapq.heappop(q)
        # print(now_node, dist)
        # print()
        for g in graph[now_node]:
            next_node, time = g[0], g[1]
            cost = dist + time

            # print(now_node, "-", next_node, cost, dist, time)

            if distance[next_node] > cost:
                distance[next_node] = cost
                heapq.heappush(q, [next_node, cost])
                # print(q)
        # print()

    return distance


for _ in range(M):
    a, b, t = map(int, input().split())
    graph[a].append([b, t])
    graph[b].append([a, t])
    case.append([a, b])


min_val = dijikstra()[-1]

for i in range(0, M):
    max_time = max(max_time, delay_dijikstra(i)[-1])

if max_time == INF:
    print(-1)

else:
    print(max_time - min_val)

# 1-2, 1-4, 2-3, 3-4, 3-6, 4-5, 5-6
