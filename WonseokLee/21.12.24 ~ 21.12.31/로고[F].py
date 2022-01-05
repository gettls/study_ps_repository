from collections import deque

N = int(input())

maps = [[0] * 2000 for _ in range(2001)]
visited = [[0] * 2000 for _ in range(2001)]
PU = 0

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

start = deque()

# 1000/2 - 500 = 0
start.append([1000, 1000])

for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())

    # maps 확장
    x1 = (x1 + 500) * 2
    y1 = (y1 + 500) * 2
    x2 = (x2 + 500) * 2
    y2 = (y2 + 500) * 2

    # x축 선 긋기
    for i in range(x1, x2 + 1):
        maps[y1][i], maps[y2][i] = 1, 1

    # y축 선 긋기
    for i in range(y1, y2 + 1):
        maps[i][x1], maps[i][x2] = 1, 1
    start.append([y1, x1])


def bfs(s):
    q = deque()
    q.append(s)

    while q:
        y, x = q.popleft()
        if visited[y][x] == 1:
            continue

        visited[y][x] = 1

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx <= 2000 and 0 <= ny <= 2000:
                if maps[ny][nx] == 1 and not visited[ny][nx]:
                    q.append([ny, nx])

    return


for s in start:
    # 좌표가 방문한적이 있다면 이미 선을 그렸기때문에 continue
    if visited[s[0]][s[1]] == 1:
        continue

    PU += 1
    bfs(s)

print(PU)
