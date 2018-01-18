# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :


def read_file(filename):
    """
    Opens the file, returns the content of file as a str
    :param filename: str, name of file
    :return: str, content of file
    """
    with open(filename, mode='r', encoding='utf-8') as file:
        content = file.read()
    return content

# main program
content = read_file('poem.txt')
print(content)
