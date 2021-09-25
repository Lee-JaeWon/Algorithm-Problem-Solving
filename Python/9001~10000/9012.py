import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    check = list(input())
    sum = 0

    for i in check:
        if i == '(':
            sum += 1
        elif i == ')':
            sum -= 1
        if sum < 0:
            print('NO')
            break
        
    if sum > 0:
        print('NO')
    elif sum == 0:
        print('YES')
