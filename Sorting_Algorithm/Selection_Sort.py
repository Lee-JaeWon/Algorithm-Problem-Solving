import random
from timeit import default_timer as timer

def selection_sort(x):
    for last in range(len(x) - 1, 0, -1):
        largest = 0
        for i in range(1, last + 1):
            if x[i] > x[largest]:
                largest = i
        x[largest], x[last] = x[last], x[largest]
    
def test(x):
    for i in range(1, len(x)):
        if x[i - 1] > x[i]:
            return False
    return True

data = random.sample(range(10000), 100) # 0~9999 중 100개 랜덤 추출
print(f"Data = {data}\n")
start = timer()
selection_sort(data)
print(f"Elapsed Time = {timer() - start}")
print(f"\nResult = {data}")
