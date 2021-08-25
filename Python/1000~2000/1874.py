import sys
input = sys.stdin.readline

num = int(input())
stack = []
oper = []
cnt = 1

state = True

for _ in range(num):
    num_in = int(input())
    while cnt <= num_in:
        stack.append(cnt)
        oper.append("+")
        cnt += 1
    
    if stack[-1] == num_in:
        stack.pop()
        oper.append("-")
    else:
        state = False
    
if state == False:
    print("NO")
else:
    print("\n".join(oper))