def recOne(x):
    return recOne(x)


def recTwo(x):
    return recTwo(x-1)


def recThree(x):
    if x == 0:
        return recThree(x - 1)
    else:
        return recThree(x - 1)


def recFour(x):
    if x == 0:
        return 0
    else:
        return recFour(x - 1)


def recFive(x):
    if x == 0:
        return 0
    else:
        return recFive(x - 2)


def recSix(x):
    print('t')
    if x == 0:
        return 0
    else:
        return 2 + recSix(x - 1)


def recSeven(x):
    print('t')
    if x == 0:
        return 0
    else:
        return x + recSeven(x - 1)

# recOne(4)
# recTwo(4)
# recThree(4)
# print(recFour(4))
# print(recFive(4))
# print(recSix(4))
print(recSeven(4))