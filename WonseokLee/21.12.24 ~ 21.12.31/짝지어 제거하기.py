s = "baabaa"


def solution(s):
    get = []
    word = s

    for w in word:
        # 최초의 경우에는 스택에 추가
        if len(get) == 0:
            get.append(w)

        # 가장 마지막에 추가된 스택의 문자와, 다음 문자가 같다면
        elif get[-1] == w:
            get.pop()
        else:
            get.append(w)

    if len(get) == 0:
        return 1
    else:
        return 0

print(solution(s))