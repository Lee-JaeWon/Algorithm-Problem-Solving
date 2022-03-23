import random
from timeit import default_timer as timer

def heapify(A, k, n):
    largest = k
    left = 2*k + 1
    right = 2*k + 2

    if left < n and A[left] > A[largest]:
        largest = left
    if right < n and A[right] > A[largest]:
        largest = right
    if largest != k:
        A[k], A[largest] = A[largest], A[k]
        heapify(A, largest, n)

def First_Build_Heap(A, n):
    for i in range(n//2 - 1, -1, -1):
        heapify(A, i, n)

def heap_sort(A):
    n = len(A)
    First_Build_Heap(A, n)
    for i in range(n-1, 0, -1):
        A[0], A[i] = A[i], A[0]
        heapify(A, 0, i)

def test(A):
    for i in range(1, len(A)):
        if A[i - 1] > A[i]:
            return False
    return True


data = random.sample(range(10000), 100) # 0~9999 중 100개 랜덤 추출
print(f"Data = {data}\n")
start = timer()
heap_sort(data)
print(f"Elapsed Time = {timer() - start}")
print(f"\nResult = {data}")
print(f"\nTest Result = {test(data)}")