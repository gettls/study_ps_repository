from itertools import combinations

N = int(input())
Ai = list(map(int, input().split()))
Ai.sort()
cnt = 0
max_idx = N
# -6, -5, -4, -4, 0, 1, 2, 2, 3, 7

# -5, 2, 3

for i in range(N - 2):
    # index / 1 ~ 4, 5
    l, r = i + 1, N - 1

    # target = -(l + r) 를 찾아야한다
    while l < r:
        # (l+r) 값을 증가 시켜야 하므로 l += 1
        if Ai[l] + Ai[r] + Ai[i] < 0:
            l += 1
        # (l+r) 값을 감소 시켜야 하므로 l += 1
        elif Ai[l] + Ai[r] + Ai[i] > 0:
            r -= 1
        # (l+r) 값이 같다면
        elif Ai[l] + Ai[r] + Ai[i] == 0:

            # l,r의 배열값이 같다면 그 사이에 있는 숫자들도 같은 값이기 때문에
            # l,r 사이의 거리가 경우의 수
            if Ai[l] == Ai[r]:
                cnt += r - l

            # 다른경우
            elif Ai[l] != Ai[r]:

                if max_idx > r:
                    max_idx = r

                    # r과 같은 인덱스까지 max_idx 를 1씩 줄인다.
                    while max_idx >= 0 and Ai[max_idx - 1] == Ai[r]:
                        max_idx -= 1

                # r과 max_idx 까지의 거리
                cnt += r - max_idx + 1
            l += 1

print(cnt)