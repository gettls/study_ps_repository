<<<<<<< HEAD
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(a, b):
    global fire
    q = deque([])
    visited = [[0] * w for _ in range(h)]
    visited_f = [[0] * w for _ in range(h)]

    q.append([a, b])
    visited[a][b] = 1

    for f_x, f_y in fire:
        visited_f[f_x][f_y] = 1

    while fire:
        f = fire.popleft()

        for i in range(4):
            na = f[0] + dx[i]
            nb = f[1] + dy[i]

            if 0 <= na < h and 0 <= nb < w:
                if tower[na][nb] != '#' and not visited_f[na][nb]:
                    visited_f[na][nb] = visited_f[f[0]][f[1]] + 1
                    fire.append([na, nb])

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 장애물이 없을 경우
            if 0 <= nx < h and 0 <= ny < w:
                if tower[nx][ny] != '#' and not visited[nx][ny]:
                    if visited[x][y] + 1 < visited_f[nx][ny] or visited_f[nx][ny] == 0:
                        q.append([nx, ny])
                        visited[nx][ny] = visited[x][y] + 1

            # 테두리에 도착한 경우에는 탈출한 경우
            else:
                return visited[x][y]

    return "IMPOSSIBLE"


T = int(input())

for _ in range(T):
    w, h = map(int, input().split())
    tower = [[] for _ in range(h)]
    fire = deque([])

    for i in range(h):
        get = input()
        for g in get:
            tower[i].append(g)

    for i in range(h):
        for j in range(w):
            if tower[i][j] == '@':
                x, y = i, j
            if tower[i][j] == "*":
                fire.append([i, j])

    if x == 0 or y == 0 or x == h - 1 or y == w - 1:
        print(1)
    else:
        print(bfs(x, y))

# for t in tower:
#     for x in t:
#         print(x)


=======
T =

##
>>>>>>> origin/main
