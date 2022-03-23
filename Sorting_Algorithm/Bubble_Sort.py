import random
from timeit import default_timer as timer

def bubble_sort(A):
    for last in range(len(A) - 1, 0, -1):
        for i in range(last):
            if A[i] > A[i+1]:
                A[i], A[i + 1] = A[i + 1], A[i]

def test(A):
    for i in range(1, len(A)):
        if A[i-1] > A[i]:
            return False
    return True

data = random.sample(range(10000), 100) # 0~9999 중 100개 랜덤 추출
print(f"Data = {data}\n")
start = timer()
bubble_sort(data)
print(f"Elapsed Time = {timer() - start}")
print(f"\nResult = {data}")
print(f"\nTest Result = {test(data)}")