# problem 4
def reverse(number):
    return int(str(number)[::-1])

def findnumber():
    resullist = []
    for i in range(10000,100000):
        if i == reverse(i) and i%199 == 0:
            resullist.append(i)
    return resullist

# test.
print(findnumber())
