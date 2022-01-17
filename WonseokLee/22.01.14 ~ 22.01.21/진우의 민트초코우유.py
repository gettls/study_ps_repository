import sys
input = lambda: sys.stdin.readline()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
result = 0


def dfs(x, y, HP, milk):
    global result
    # print([x, y, HP])

    for nx, ny in milks:
        # 우유를 마시지 않았다면
        if maps[nx][ny] == 2:
            # 현재 좌표와 우유까지의 거리
            dist = abs(nx - x) + abs(ny - y)
            # 도착 가능한가?
            if dist <= HP:
                # 도착한 우유의 위치를 0으로 초기화
                maps[nx][ny] = 0
                dfs(nx, ny, HP + H - dist, milk + 1)
                # 다음 탐색을 위해 다시 우유의 위치를 복구
                maps[nx][ny] = 2

    # 다음 우유까지 소모될 HP가 부족한경우, 현재 위치에서 집까지 복귀가 가능한가?
    if abs(x - i) + abs(y - j) <= HP:
        # 마신 우유의 최대값을 저장한다
        result = max(result, milk)


N, M, H = map(int, input().split())
maps = []
milks = []

for _ in range(N):
    maps.append(list(map(int, input().split())))

for a in range(N):
    for b in range(N):
        # 진우의 집 좌표
        if maps[a][b] == 1:
            i, j = a, b
        # 우유의 위치 저장
        if maps[a][b] == 2:
            milks.append([a, b])

dfs(i, j, M, 0)
print(result)
