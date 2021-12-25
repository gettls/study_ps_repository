# 간소화
n = int(input())
stack = []
answer = ''
cnt = 0
flag = 0

for _ in range(n):
    v = int(input())

    while cnt < v:
        cnt += 1
        stack.append(cnt)
        answer += "+"

    if stack[-1] == v:
        stack.pop()
        answer += "-"
    else:
        flag = -1
        print("NO")
        break

if flag != -1:
    for a in answer:
        print(a)

# 최초정답
# n = int(input())
# arr = []
# result = [0]
# answer = ''
# flag = 1
#
# for _ in range(n):
#     arr.append(int(input()))
# arr.reverse()
# target = arr.pop()
#
# for _ in range(n):
#     for i in range(flag, n + 1):
#         # push 값과 target 값이 같다면
#         if result[-1] == target:
#             pop = result.pop()
#             answer += "-"
#             target = arr.pop()
#             break
#         else:
#             result.append(i)
#             answer += "+"
#             flag = result[-1] + 1
#
#     # n까지 추가 완료했을 경우에는
#     if flag == n + 1:
#         if result[-1] == target:
#             pop = result.pop()
#             answer += "-"
#             if len(arr) != 0:
#                 target = arr.pop()
#         else:
#             print("NO")
#             answer = -1
#             break
#
# if answer != -1:
#     for a in answer:
#         print(a)
