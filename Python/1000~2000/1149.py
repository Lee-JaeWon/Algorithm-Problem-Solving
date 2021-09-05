import sys
input = sys.stdin.readline
num = int(input())

H = []
for i in range(num):
    H.append(list(map(int, input().split())))

for i in range(1,num):
    H[i][0] = min(H[i-1][1], H[i-1][2]) + H[i][0]
    H[i][1] = min(H[i-1][0], H[i-1][2]) + H[i][1]
    H[i][2] = min(H[i-1][0], H[i-1][1]) + H[i][2]
print(min(H[num-1]))


    

    




