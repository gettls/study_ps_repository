import heapq

T = int(input())

for _ in range(T):
    K = int(input())
    total = 0
    file = list(map(int, input().split()))
    q = []
    for f in file:
        heapq.heappush(q, f)

    while len(q) != 1:
        add = 0
        for _ in range(2):
            add += heapq.heappop(q)
        heapq.heappush(q, add)
        total += add

    print(total)



# def merge(f, t):
#     global total
#     result = deque([])
#     while f:
#         print("!", f)
#         add = 0
#         for _ in range(2):
#             if len(f) == 0:
#                 break
#             add += f.popleft()
#             print("!!",f)
#
#         if flag != 1:
#             total += add
#         result.append(add)
#     print()
#     print(result)
#     print()
#     return result

