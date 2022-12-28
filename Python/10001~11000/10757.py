import sys
input = sys.stdin.readline

Lbuf, Rbuf = input().split()
Lsize = len(Lbuf); Rsize = len(Rbuf)

Left = []; Right = []

for i in str(Lbuf):
    Left.append(int(i))
for i in str(Rbuf):
    Right.append(int(i))

Left.reverse();Right.reverse()

# print(Left, Right)

if Lsize < Rsize:
    min_n = Lsize
else:
    min_n = Rsize

num_upper = 0
temp = []
for i in range(min_n):
    result = Left[i] + Right[i] + num_upper
    num_upper = result / 10
    temp[i] = result % 10

    if num_upper > 0:
        Left[i+1] += 1
        num_upper = 0

if Lsize < Rsize:
    for i in range(min_n, Rsize):
        temp[i] = Right[i]


print(temp.reverse())
