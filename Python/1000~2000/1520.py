# import sys
# input = sys.stdin.readline
# from timeit import default_timer as timer

# M, N = map(int, input().split()) # 세로 : M, 가로 : N

# Mat = [list(map(int, input().split())) for _ in range(M)]

# start = timer()

# i, j = 1, 1
# result = 0

# while(i is not M and j is not N):
#     if(Mat[i-1][j] < Mat[i-1][j-1] and Mat[i][j-1] < Mat[i-1][j-1]): # 둘 다 작은 경우
#         result += 1
#         if j <= N:
#             j += 1 # 무조건 오른쪽으로 고
#     elif(Mat[i-1][j] < Mat[i-1][j-1] and not Mat[i][j-1] < Mat[i-1][j-1]):
#         j += 1
#     elif(Mat[i][j-1] < Mat[i-1][j-1] and not Mat[i-1][j] < Mat[i-1][j-1]):
#         i += 1

# i, j = 1, 1
# while(i is not M and j is not N):
#     if(Mat[i-1][j] < Mat[i-1][j-1] and Mat[i][j-1] < Mat[i-1][j-1]): # 둘 다 작은 경우
#         result += 1
#         if i <= M:
#             i += 1 # 무조건 아래로 고
#     elif(Mat[i-1][j] < Mat[i-1][j-1] and not Mat[i][j-1] < Mat[i-1][j-1]):
#         j += 1
#     elif(Mat[i][j-1] < Mat[i-1][j-1] and not Mat[i-1][j] < Mat[i-1][j-1]):
#         i += 1

# print(result)
# print(f"{(timer()-start)*1000} sec")

# ## Reference
# # https://minjoos.tistory.com/2


import sys
input = sys.stdin.readline
from timeit import default_timer as timer

