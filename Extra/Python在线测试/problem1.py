# problem 1

def addub(string):
    vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    result = string
    resultIndex = 0
    for i in range(len(string)):
        if string[i] in vowel:
            result = result[:resultIndex] + 'ub' + string[i:]
            resultIndex += 2
        resultIndex += 1
    return result

print(addub("exercise"))
print(addub("hello"))
