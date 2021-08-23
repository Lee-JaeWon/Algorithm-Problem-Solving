import sys
import heapq

cal_num = int(sys.stdin.readline())
heap = []

for _ in range(cal_num):
    num = int(sys.stdin.readline())
    if num != 0:
        heapq.heappush(heap, num)
    else:
        if len(heap) != 0:
            print(heapq.heappop(heap))
        else:
            print(0)