import heapq

N = int(input())

q = []
end_time = []

for _ in range(N):
    n, s, e = map(int, input().split())
    heapq.heappush(q, (s, e))


s, e = heapq.heappop(q)  # 2, 14
heapq.heappush(end_time, e)  # 14

while q:
    s, e = heapq.heappop(q)

    # (최소)강의 종료시간과 끝나는 시간이 같거나 클때,
    if end_time[0] <= s:
        heapq.heappop(end_time)
    heapq.heappush(end_time, e)

print(len(end_time))

# (2, 14)
# (3, 8)
# (6, 20)
# (6, 27)
# (7, 13)
# (12, 18)
# (15, 21)
# (20, 25)
