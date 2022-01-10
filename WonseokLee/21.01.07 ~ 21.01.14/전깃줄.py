line = int(input())
maps = []
dp = [1] * line

for i in range(line):
    maps.append(list(map(int, input().split())))

maps.sort()

# print(maps)

for i in range(1, line):
    for j in range(i):
        # 최장 증가 부분수열
        if maps[i][1] > maps[j][1]:
            dp[i] = max(dp[i], dp[j] + 1)
print(line - max(dp))


# [[1, 8], [2, 2], [3, 9], [4, 1], [6, 4], [7, 6], [9, 7], [10, 10]]
