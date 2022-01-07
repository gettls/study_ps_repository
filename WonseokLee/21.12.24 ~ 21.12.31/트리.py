N = int(input())
node = list(map(int, input().split()))
delete = int(input())

child = [[] for _ in range(N)]
leaf_cnt = [0] * N
leaf_cnt[0] = 100
test = [0] * N
leaf = 0


def find_leaf(n, c):  # 2 - 4
    result = 0
    # 리프 노드일 때,
    if len(child[n]) == 0:
        c += 1
        test[n] += 1
        return c

    else:
        for i in child[n]:  # 3, 4 - 5, 6
            result += find_leaf(i, c)
    return result


for i in range(len(node)):
    if node[i] == -1:
        p_node = i
    else:
        child[node[i]].append(i)

for i in range(len(child)):
    for j in range(len(child[i])):
        leaf_cnt[child[i][j]] = find_leaf(child[i][j], 0)

for t in test:
    if t != 0:
        leaf += 1

a = node[delete]
if a == -1:
    print(0)
# 2번을 지울때 1번이 부모
elif len(child[a]) == 1:
    print(leaf)
else:
    print(leaf - leaf_cnt[delete])


# [-1, 0, 0, 1, 1]
# parent = 0
# 0 - 1, 2
# 1 - 3, 4

# 6
# -1 0 1 2 2 3
# 2

# [-1, 0, 0, 1, 1]
# [100, 2, 1, 1, 1]
