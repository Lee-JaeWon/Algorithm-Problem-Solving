import sys
input = sys.stdin.readline

input_num = int(input())
fibonacci = [0, 1]

for i in range(2, input_num+1):
        fibonacci.append(fibonacci[i-1]+fibonacci[i-2])
print(fibonacci[input_num])

# #그냥 input함수는 시간이 조금 느려요..
# #그래서 sys모듈을 import해서 사용합니다.

# #보통의 사용방법은
# num = int(sys.stdin.readline())
# #입니다.