# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :


def fastGrowing(n):
    """
    Takes a natural number and returns the product of all
    the natural numbers from 1 up to the given number.
    :param n: int, a natural number
    :return: int, result
    """
    if n == 1:
        return 1
    else:
        return n * fastGrowing(n - 1)


def power_of_three(n):
    """
    Takes a natural number n and returns 3**n
    :param n: int, a natural number
    :return: int, result
    """
    if n == 1:
        return 3
    else:
        return 3 * power_of_three(n - 1)


def power(b, n):
    """
    Takes a number b and a natural number n and returns b**n
    :param b: int, a natural number
    :param n: int, a number
    :return: int, result
    """
    if n == 1:
        return b
    else:
        return b * power(b, n - 1)


# main program
print(fastGrowing(5))
print(power_of_three(5))
print(power(3, 4))
