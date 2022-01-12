n = int(input())
box = list(map(int, input().split()))
dp = [1] * n

# 최장 증가 부분수열
for i in range(1, n):
    for j in range(i):
        if box[i] > box[j]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))

# 1, 2, 2, 3, 4