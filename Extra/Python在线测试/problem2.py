# problem 2
def mostappear(lis):
    appearset = set(lis)
    countlist = list()
    for i in appearset:
        countlist.append((i, lis.count(i)))
    resultlist = []
    for i in range(5):
        if len(countlist) == 0:
            break
        maxIndex = 0
        for j in range(len(countlist)):
            if countlist[j][1] > countlist[maxIndex][1]:
                maxIndex = j
        resultlist.append(countlist[maxIndex][0])
        del countlist[maxIndex]
    return resultlist

# test.
print(mostappear([1,3,4,5,2,3,6,3,6,2,3,4,65,3,2,3,4,5,4,7,8,4]))
