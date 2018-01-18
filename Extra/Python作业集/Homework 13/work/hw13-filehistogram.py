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


def dict_from_file(filename):
    """
    Opens the file, reads its contents,
    and returns a dictionary based on the letter frequencies
    :param filename: str, name of file
    :return: dict, letter frequencies of file content
    """
    content = read_file(filename)
    frequencies = dict()
    for chr in content:
        if chr in frequencies:
            frequencies[chr] += 1
        else:
            frequencies[chr] = 1
    return frequencies


# main program
frequencies = dict_from_file('poem.txt')
print(frequencies)
