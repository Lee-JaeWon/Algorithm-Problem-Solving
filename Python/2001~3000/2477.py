import sys
input = sys.stdin.readline

melon = int(input())

side_num = 6

mylist=[]
for _ in range(side_num):
    mylist.append(list(map(int, input().split())))

max_NS = 1; max_EW = 1
max_NS_index = 0; max_EW_index = 0
for i in range(side_num):
    if mylist[i][0] == 1 or mylist[i][0] == 2:
        if max_EW < mylist[i][1]:
            max_EW = mylist[i][1]
            max_EW_index = i
    if mylist[i][0] == 3 or mylist[i][0] == 4:
        if max_NS < mylist[i][1]:
            max_NS = mylist[i][1]
            max_NS_index = i
            
min_EW = abs(mylist[(max_EW_index-1) % 6][1] - mylist[(max_EW_index+1) % 6][1])
min_NS = abs(mylist[(max_NS_index-1) % 6][1] - mylist[(max_NS_index+1) % 6][1])

area = max_EW*max_NS - min_EW*min_NS

print(area*melon)
        
