# 불가능한 결과 case

# 1. 승 != 패
# 2. 무승부의 수가 홀수인경우
# 2-1. 무승부의 수를 번갈아 +, -로 더해주었을 때 결과가 0이 아닌경우

from itertools import combinations


def dfs(cnt):
    global result
    # 매칭의 경우의 수 순회가 끝났다면
    if cnt == len(case):
        result = 1

        for b in board:
            if b.count(0) != 3:
                result = 0
                break
        return

    i, j = case[cnt]

    # 승패, 무무, 패승
    for x, y in [(2, 0), (1, 1), (0, 2)]:
        if board[i][x] > 0 and board[j][y] > 0:
            board[i][x] -= 1
            board[j][y] -= 1
            dfs(cnt + 1)
            # 다음 탐색을 위해 원복
            board[i][x] += 1
            board[j][y] += 1


answer = []
case = list(combinations(range(6), 2))

for _ in range(4):
    game = list(map(int, input().split()))
    board = [[] for _ in range(6)]

    for i in range(0, 6):
        for j in range(i * 3, i * 3 + 3):
            board[i].append(game[j])

    result = 0
    dfs(0)
    answer.append(result)

for a in answer:
    print(a, end=" ")

# for _ in range(1):
#     game = list(map(int, input().split()))
#     board = [[] for _ in range(3)]
#     flag, cnt = 0, 0
#     draw = [0] * 6
#
#     if 6 in game:
#         result.append(0)
#         continue
#
#     for i in range(0, 6):
#         sum_abc = 0
#         for j in range(i * 3, i * 3 + 3):
#             board[j % 3].append(game[j])
#
#     if flag == -1:
#         result.append(0)
#         continue
#
#     # 1. 승 != 패
#     if sum(board[0]) != sum(board[2]):
#         print(sum(board[0]), sum(board[2]))
#         result.append(0)
#         continue
#
#     # 2. 무승부의 수가 홀수인경우
#     if (6 - board[1].count(0)) % 2 != 0:
#         result.append(0)
#         continue
#
#     # 2-1. 무승부의 수를 번갈아 +, -로 더해주었을 때 결과가 0이 아닌경우
#     if (6 - board[1].count(0)) % 2 == 0:
#         for b in board[1]:
#             if b != 0 and draw[b] == 0:
#                 draw[b] += 1
#             elif b != 0 and draw[b] != 0:
#                 draw[b] -= 1
#
#         if sum(draw) != 0:
#             result.append(0)
#             continue
#
#     result.append(1)
#
# for r in result:
#     print(r, end=' ')
