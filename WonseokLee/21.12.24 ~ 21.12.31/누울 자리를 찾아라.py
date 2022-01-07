N = int(input())
get = []

for _ in range(N):
    get.append((input()))


def get_w(room):
    result_w = 0
    for i in range(N):
        cnt = 0
        for j in range(N):
            if room[i][j] == ".":
                cnt += 1
            else:
                if cnt >= 2:
                    result_w += 1
                cnt = 0

        if cnt >= 2:
            result_w += 1
    return result_w


def get_h(room):
    result_h = 0
    for i in range(N):
        cnt = 0
        for j in range(N):
            if room[j][i] == ".":
                cnt += 1
            else:
                if cnt >= 2:
                    result_h += 1
                cnt = 0

        if cnt >= 2:
            result_h += 1
    return result_h


print(get_w(get), get_h(get))
