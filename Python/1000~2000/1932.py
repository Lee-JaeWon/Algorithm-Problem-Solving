import sys
input = sys.stdin.readline

size = int(input())

triangle = [0] * size

for i in range(size):
    triangle[i] = list(map(int, input().split()))

for i in range(1, size):
    if i == 1:
        triangle[i][0] += triangle[0][0]
        triangle[i][i] += triangle[0][0]
    else:
        triangle[i][0] += triangle[i-1][0]
        triangle[i][i] += triangle[i-1][i-1]
        for j in range(1, i):
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])
print(max(triangle[size-1]))