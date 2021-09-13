# import sys
# from itertools import combinations
# input = sys.stdin.readline

# while True:
#     s = list(map(int, input().split()))
#     if s[0] == 0:
#         break
#     del s[0]
#     s = list(combinations(s, 6))
#     for i in s:
#         for j in i:
#             print(j, end=' ')
#         print()
#     print()

import sys
input = sys.stdin.readline

def dfs(start, depth):
    if depth == 6:
        for i in range(6):
            print(combi[i], end=' ')
        print()
        return
    for i in range(start, len(s)):
        combi[depth] = s[i]
        dfs(i + 1, depth + 1)

combi = [0] * 13

while True:
    s = list(map(int, input().split()))
    if s[0] == 0:
        break
    del s[0]
    dfs(0, 0)
    print()


    
