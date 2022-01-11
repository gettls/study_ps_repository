import sys
input = sys.stdin.readline

N, M = map(int, input().split())

# N^2
word = [0] * N
for i in range(N):
    get = input().strip()
    for g in get:
        word[i] |= 1 << ord(g) - 97


# 알파벳을 모두 알때
validate = (1 << 26) - 1
for _ in range(M):
    cnt = 0
    o, x = input().split()
    x = ord(x) - 97

    # AND 연산을 통해 x 의 값을 반전하여 0을 기록한다.
    if o == '1':
        validate = validate & ~(1 << x)

    # OR 연산을 통해 x 의 값을 1로 기록한다.
    else:
        validate = validate | (1 << x)

    for i in range(N):
        # word 와 validate 의 AND 연산이 그대로라면..
        # validate 와 word 의 bin 값이 겹치치 않으므로 제외해야하는 문자가 word 에 없다는 결과

        # word 와 validate 의 AND 연산이 다르다면..
        # validate 의 0의 값이 word 의 bin 값을 0으로 만들기 때문에 기존의 word 와 bin 값이 틀리게 된다.
        if word[i] & validate == word[i]:
            cnt += 1

    print(cnt)
