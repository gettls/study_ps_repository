N = int(input())
ct = []
bt = []

# 과목의 공강시간을 bit masking
for _ in range(N):
    class_t = 0
    cla = list(map(int, input().split()))
    for c in cla[1:]:
        class_t |= 1 << (c-1)
    ct.append(class_t)


# 학생들의 공강시간을 bit masking
M = int(input())
for _ in range(M):
    btc_t = 0
    btc = list(map(int, input().split()))
    for b in btc[1:]:
        btc_t |= 1 << (b-1)
    bt.append(btc_t)

for i in bt:
    cnt = 0
    for j in ct:
        # 공강시간과 수업시간의 AND 값이 공강시간의 bin 과 똑같다면,
        # 수업시간이 공강시간을 포함한다는 의미
        if i & j == j:
            cnt += 1
    print(cnt)

