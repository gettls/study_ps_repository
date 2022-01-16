from itertools import permutations

N = int(input())
A = list(map(int, input().split()))
answer = 0

cases = list(permutations(A, N))
for case in cases:
    result = 0
    for i in range(len(case)-1):
        result += abs(case[i] - case[i + 1])
    answer = max(result, answer)

print(answer)
# 0, 0, 0, 0, 0, 0, 0

# 0, 19, 0, 0, 0, 0, 0

# 0, 19,
