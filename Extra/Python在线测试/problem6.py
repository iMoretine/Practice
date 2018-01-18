# problem 6
def sumofodd(dic):
    result = 0
    for i in dic:
        if i % 2 == 1:
            result += i
    return result

# test
print(sumofodd({1,2,3,4,5,6,7,8,9,10}))
