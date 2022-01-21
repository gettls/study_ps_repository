N, C = map(int, input().split())
M = int(input())

village = [[] for _ in range(N)]

box = [list(map(int, input().split())) for i in range(M)]

box.sort(key=lambda x: x[1])

print(box)


# 1번에서 2번에 10개 3번에 20개를 내린다 현재 30개
# 2번에서 10개를 내린다. 현재 20개.
# 2번에서 3번에 10개를 내린다. 현재 30개
# 3번에서 10개를 내린다. 현재 20개.
#

# print(village)
#
# for i in village[1]:
#     if total_box >= C:
#         continue
#     elif total_box + i[1] <= C:
#         total_box += i[1]
#         target[i[0]] += i[1]
#     else:
#         target[i[0]] += (C - total_box)
#         total_box = C
#
# print(total_box, target)
#
# for i in range(2, N):
#     # i번 마을에 도착했을 때, 박스를 내린다
#     total_box -= target[i]
#     print(i, "?",total_box)
#     fin_box += target[i]
#     print("T",target[i])
#     for j in village[i]:
#         if total_box >= C:
#             print("[1]")
#             continue
#         elif total_box + j[1] <= C:
#             print("[2]")
#             total_box += j[1]
#             target[j[0]] += j[1]
#         else:
#             print("[3]")
#             target[j[0]] += (C - total_box)
#             total_box = C
#
#         print(target)
#     print()
#
# fin_box += target[-1]

# print(target)
# print(fin_box)