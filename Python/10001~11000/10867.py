# import sys
# input = sys.stdin.readline

# class dup_num:
#     def removeduplication(self, alpha:str)->str:
#         for S in sorted(set(alpha)):           
#             temp = alpha[alpha.index(S):]
            
#             if set(alpha) == set(temp):
#                 return int(S + self.removeduplication(temp.replace(S,'')))
        
#         return ''

# N = int(input())
# remove_dup = dup_num()
# str_num = [int(x) for x in input().split()]
# print(f'')

N = int(input())
number_list = list(map(int, input().split()))

for i in sorted(list(set(number_list))):
    print(i, end = ' ')