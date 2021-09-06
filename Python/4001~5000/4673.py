def selfnumber():
    list = []
    for i in range(10000):
        temp = 0
        for j in str(i):
            temp += int(j)
        list.append(i+temp)

    result = []
    for item in range(10000):
        if not item in list:
            result.append(item) 
    
    for i in range(len(result)):
        print(result[i])

selfnumber()