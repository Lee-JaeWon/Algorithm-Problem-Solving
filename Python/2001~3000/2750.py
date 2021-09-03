import sys
input = sys.stdin.readline

def insertion_sort(arr):
    for end in range(1, len(arr)):
        i = end
        while i > 0 and arr[i-1] > arr[i]:
            arr[i-1], arr[i] = arr[i], arr[i-1]
            i -= 1

num = int(input())
sort_num = []

for _ in range(num):
    sort_num.append(int(input()))

insertion_sort(sort_num)

for n in sort_num:
    print(n)
