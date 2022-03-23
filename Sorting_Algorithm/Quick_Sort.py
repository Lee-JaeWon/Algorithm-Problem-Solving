import random
from timeit import default_timer as timer

def partition(A, p, r):
    x = A[r] # 마지막 인덱스
    i = p
    for j in range(p, r):
        if A[j] <= x:
            A[i], A[j] = A[j], A[i]
            i += 1
    A[i], A[r] = A[r], A[i]
    return i

def q_sort(A, p ,r):
    if p < r:
        q = partition(A, p, r)
        q_sort(A, p, q - 1)
        q_sort(A, q +1, r)

def quick_sort(A):
    q_sort(A, 0, len(A) - 1)

def test(A):
    for i in range(1, len(A)):
        if A[i - 1] > A[i]:
            return False
    return True


data = random.sample(range(10000), 100) # 0~9999 중 100개 랜덤 추출
print(f"Data = {data}\n")
start = timer()
quick_sort(data)
print(f"Elapsed Time = {timer() - start}")
print(f"\nResult = {data}")
print(f"\nTest Result = {test(data)}")