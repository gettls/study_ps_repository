from collections import deque

N, M, T = map(int, input().split())
find = 0

maps = [list(map(int, input().split())) for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]


def gram(i, j):
    visited = [[0] * M for _ in range(N)]
    visited[i][j] = 1
    q = deque()
    q.append([i, j])

    while q:
        x, y = q.popleft()
        if x == N - 1 and y == M - 1:
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append([nx, ny])

    return visited[x][y]


def dfs(i, j):
    global find

    visited = [[0] * M for _ in range(N)]
    visited[i][j] = 1
    q = deque()
    q.append([i, j])

    while q:
        x, y = q.popleft()
        if x == N - 1 and y == M - 1:
            break

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0:
                    if maps[nx][ny] == 0:
                        visited[nx][ny] = visited[x][y] + 1
                        q.append([nx, ny])
                    elif maps[nx][ny] == 2 and find == 0:
                        find = 1
                        return gram(nx, ny) + visited[x][y] - 1
    if x != N - 1 or y != M - 1:
        return "Fail"
    else:
        return visited[x][y] - 1


# 첫번째 탐색
result = dfs(0, 0)

# 첫번째 탐색에서 그람을 사용했을 경우,
if find == 1:
    # 그람을 사용하지 않고 탐색할 경우를 구한다.
    result2 = dfs(0, 0)

    # 그람을 사용하지 않았을때 탐색이 불가능하고, 기존의 탐색이 T 시간내에 가능할 때
    if result2 == "Fail" and result <= T:
        # print("1")
        print(result)

    # 그람을 사용하지 않았을때 탐색이 불가능하고, 기존의 탐색이 T 시간내에도 불가능할 때
    elif result2 == "Fail" and result > T:
        # print("1-1")
        print("Fail")

    # 탐색에 성공하고 제한시간 T 내에 통과할 경우
    elif min(result, result2) <= T:
        # print("2")
        print(min(result, result2))

    # 탐색에 성공헀지만 제한시간 T 를 초과할 경우
    elif min(result, result2) > T:
        # print("3")
        print("Fail")


# 그람을 사용하지 않고 시간내에 탐색에 실패할경우
elif result == "Fail" or result > T:
    print("Fail")


# 그람을 사용하지 않고 탐색에 성공헀을 경우
else:
    print(result)