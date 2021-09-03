import sys
input = sys.stdin.readline

room_num = int(input())

people_num = [int(x) for x in input().split()]

first_sup, other_sup = map(int, input().split())
result = room_num

for i in range(room_num):
    if (people_num[i] - first_sup) < 0:
        continue

    result += (people_num[i] - first_sup) // other_sup
    if(people_num[i] - first_sup) % other_sup != 0:
        result += 1
        
print(result)