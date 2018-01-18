# problem 3
def count():
    text = ""
    f = open("twist.txt", "r")
    lines = f.readlines()  # 读取全部内容
    for line in lines:
        text += line
    text = text.split()
    wordset = set(text)
    result = []
    for i in wordset:
        if text.count(i) == 1:
            result.append(i)
    return len(result)

print(count())
