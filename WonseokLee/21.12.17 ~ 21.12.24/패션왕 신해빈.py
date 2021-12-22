from itertools import combinations

T = int(input())


for _ in range(T):
    result = 1
    n = int(input())
    cat = []
    for _ in range(n):
        clothe, category = map(str, input().split())
        cat.append(category)
        cat_set = list(set(cat))

    # 옷 종류에 대한 조합의 수를 구한다
    for i in range(len(cat_set)):
        # 종류 + 헐거벗은 경우
        result *= (cat.count(cat_set[i]) + 1)

    # 아무것도 입지않은 경우를 제외한다
    result -= 1
    print(result)


# hat - x, sunglasses
# sunglasses - x, turban,
# turban - x

# mask, sunglasses, makeup
