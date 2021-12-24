import re

T = int(input())

for _ in range(T):
    sig = input()
    pattern = re.compile('(100+1+|01)+')

    if pattern.fullmatch(sig):
        print("YES")
    else:
        print("NO")

