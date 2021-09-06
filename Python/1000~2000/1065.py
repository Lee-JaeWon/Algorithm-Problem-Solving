import sys
input = sys.stdin.readline

N = int(input())

def Hansu(a):
    #----------------
    cnt = 0;tmp1 = 0;tmp2 = 0
    #----------------
    # a까지의 수 반복
    for i in range(1, a+1):
        #리스트 초기화
        list = []
        # 각 자리수 리스트에 추가
        for j in str(i):
            list.append(int(j))
        # 각 자리수의 차이 비교
        if len(list) == 1 or len(list) == 2:
            cnt += 1
        else:
            tmp1 = list[1] - list[0]
            tmp2 = list[2] - list[1]
            if tmp1 == tmp2:
                cnt += 1
    print(cnt)
                
Hansu(N)