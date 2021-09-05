## 시간 초과 (Merge Sort)
## 정답은 아래

# import sys
# input = sys.stdin.readline

# def merge_sort(unsorted_list):
#     if len(unsorted_list) <= 1:
#         return unsorted_list

#     mid = len(unsorted_list) // 2
#     leftList = unsorted_list[:mid]
#     rightList = unsorted_list[mid:]
#     leftList = merge_sort(leftList)
#     rightList = merge_sort(rightList)
#     return merge(leftList, rightList)

# def merge(left, right):
#     i = 0;j = 0
#     sorted_list = []

#     while (i < len(left)) & (j < len(right)):
#         if left[i] < right[j]:
#             sorted_list.append(left[i])
#             i += 1
#         else:
#             sorted_list.append(right[j])
#             j += 1
#     while (i < len(left)):
#         sorted_list.append(left[i])
#         i += 1
#     while (j < len(right)):
#         sorted_list.append(right[j])
#         j += 1
    
#     return sorted_list


# num = int(input())

# sort_num = []
# for _ in range(num):
#     sort_num.append(int(input()))

# for i in range(len(sort_num)):
#     print(merge_sort(sort_num)[i])


N = int(input())
nums = []
for i in range(N):
    nums.append(int(input()))

nums = sorted(nums)
    
for i in range(N):
    print(nums[i])