from itertools import combinations

n, m = map(int, input().split())
res = (1 << n)
switch_list = []
switch_bin = []
comb = []
door = input()
dp = [-1] * (2 * n + 1)


def trans(swt):
    year = 0
    for s in swt:
        if s == '0':
            year -= 1
        else:
            year += 1
    return year


for i in range(m):
    get = 0
    switch = input()
    for j in range(len(switch)):
        if switch[j] == '1':
            get = get | (1 << len(switch) - j - 1)
        else:
            get = get | (0 << 0)

    switch_list.append([get, i + 1])

for i in range(len(door)):
    if door[i] == '1':
        res = res | (1 << len(door) - i - 1)
    else:
        res = res | (0 << 0)

dp[trans(bin(res)[3:]) + n] = 0

for i in range(1, m + 1):
    for c in combinations(switch_list, i):
        switch_bin.append(list(c))

for sb in switch_bin:
    total = 0
    index = []
    for i in sb:
        total |= res ^ i[0]
        index.append(i[1])
    comb.append([bin(total)[3:], index])

for c in comb:
    dp[trans(c[0]) + n] = c[1]


for d in dp:
    if type(d) == list:
        print(len(d), end=' ')
        for i in d:
            print(i, end=' ')
        print()
    else:
        print(d)

# for i in range(1, m + 1):
#     for comb in combinations(switch_list, i):
#         total = 0
#         index = []
#         for c in comb:
#             total |= res ^ c[0]
#             index.append(c[1])
#         com.append([bin(total)[3:], index])

# for i in com:
#     dp[trans(i[0]) + n] = i[1]
#
#


# 000 -3
# 100 -1
# 010
# 001

# 110 +1
# 101
# 011

# 111 +3


# -3 -2 -1 0 1 2 3
#
# 1번쨰 줄 -3년
# 2번째 줄 -2년
# 3번째 줄 -1년
# 4번째 줄  0년
# 5번째 줄  1년
# 6번쨰 줄 +2년
