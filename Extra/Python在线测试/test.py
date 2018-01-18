def func(str):
    vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    if len(str) <= 1:
        return str
    last = 0
    result = str
    resultIndex = 2
    for i in range(1, len(str)):
        if str[i] in vowel and str[last] not in vowel:
            result = result[:resultIndex] + str[last] + str[i] + result[resultIndex:]
            resultIndex += 2
        last += 1
        resultIndex += 1
    return result

# print(func('stout'))
# print(func('Mississippi'))
# print(func('Milwaukee'))

# stotout
# MiMissisissisippipi
# MiMilwawaukekee


# 1

def calnum(num):
    result = 0
    while(num > 0):
        result += int(num) % int(10)
        num /= 10
    return result

def cal(num):
    while(num>=10):
        num = calnum(num)
    return num

# print(cal(45739834294))

# 3

def separ(str):
    vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    for i in range(len(str)):
        if str[i] in vowel:
            return (str[:i],str[i:])
    return (str,"")

# print(separ("crusty"))
# print(separ("apology"))
# print(separ("Marquette"))

# 4

def endwithvowel(str):
    if len(str) == 0:
        return False
    vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    return str[-1] in vowel

# print(endwithvowel("crusty"))
# print(endwithvowel(""))
# print(endwithvowel("Marquette"))

# 5

def matten(str):
    if len(str) == 0:
        return str
    vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    if str[0] in vowel:
        str = 'i' + str[1:]
        if str[-1] in vowel:
            return str + 'hee'
        else:
            return str + 'ee'
    else:
        prefixIndex = 0
        for i in range(len(str[0])):
            if i not in vowel:
                prefixIndex += 1
            else:
                break
        str = str[prefixIndex:] + str[:prefixIndex] + 'ee'
        str = 'i' + str[1:]
        return str


print(matten("marquette"))
print(matten("anger"))
