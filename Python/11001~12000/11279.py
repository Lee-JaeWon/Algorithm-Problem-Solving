import sys
import heapq as hp

cal_num = int(sys.stdin.readline())
heap = []

for _ in range(cal_num):
    num = int(sys.stdin.readline())
    if num != 0:
        hp.heappush(heap, (-num, num))
    else:
        if len(heap) != 0:
            print(hp.heappop(heap)[1])
        else:
            print(0)