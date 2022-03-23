import random
from timeit import default_timer as timer

def insertion_sort(A):
    for i in range(1, len(A)):
        loc = i - 1
        new_item = A[i]
        while loc >= 0 and new_item < A[loc]: # loc가 0이상이고, new item보다 이전 인덱스의 값이 클 때
            A[loc + 1] = A[loc] # A[loc]를 다음 인덱스에 대입
            loc = loc - 1 # loc 감소시킨 후 비교 반복
        A[loc + 1] = new_item

def test(A):
    for i in range(1, len(A)):
        if A[i - 1] > A[i]:
            return False
    return True

x = random.sample(range(10000), 100) # 0~9999 중 100개 랜덤 추출
print(f"Data = {x}\n")
start = timer()
insertion_sort(x)
print(f"Elapsed Time = {timer() - start}")
print(f"\nResult = {x}")
print(f"\nTest = {test(x)}")