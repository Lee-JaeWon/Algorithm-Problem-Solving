import sys
input = sys.stdin.readline

step = int(input())

def solve(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return solve(n-1) + solve(n-2) + solve(n-3)

for _ in range(step):
    num = int(input())
    print(solve(num))
