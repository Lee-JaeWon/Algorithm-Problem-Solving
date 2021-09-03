import sys
input = sys.stdin.readline

def insertion_sort(arr):
    for end in range(1, len(arr)):
        i = end
        while i > 0 and arr[i] > arr[i-1]:
            arr[i], arr[i-1] = arr[i-1], arr[i]
            i -= 1

s = int(input())
num = list(map(int, str(s)))

insertion_sort(num)
Str_num = int("".join(map(str, num)))

print(Str_num)