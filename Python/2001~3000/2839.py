import sys
input = sys.stdin.readline

num = int(input())

count = 0
while num >= 0:
    if num % 5 == 0:
        count += (num / 5)
        print(int(count))
        break
    num -= 3
    count += 1
else:
    print(-1)
        
