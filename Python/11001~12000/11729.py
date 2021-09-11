import sys
input = sys.stdin.readline

N = int(input())

def Hanoi(num, one, two, thr):
    if num == 1:
        print(one, thr)
    else:
        Hanoi(num - 1, one, thr, two)
        print(one, thr)
        Hanoi(num - 1, two, one, thr)

print(2**N-1)
Hanoi(N,1,2,3)
    
        


