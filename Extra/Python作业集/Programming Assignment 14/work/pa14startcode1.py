def f1(x):
    return f1(x)

# This causes an infinite loop, which crashes when it gets 1000 levels deep
# When we call f1(5), it just keeps calling f1(5) again to try and calculate
# the result, until the stack gets too big.


def f2(x):
    return f2(x-1)

# Again, we get an infinite loop, which crashes at 1000 recursions
# This time, the first time through, it tries to calculate f(4), and then f(3),
# and then f(2), etc., but it never ends (until it crashes)


def f3(x):
    if x == 0:
        return 55
    else:
        return f3(x-1)

# In this case, as long as we give a non-negative integer as input, it will
# eventually return 55, and then pass that number back up the stack and return
# 55 for the whole function.
# In PYTHON, if we passed a number bigger than about 1000, it will crash not
# because it's inherently wrong, but because Python can't handle real recursion.
# If you pass a negative number, the values will never stop and it will crash


def f4(x):
    if x==0:
        return 0
    else:
        return f4(x-1)+5

# If you chase down all the recursions here, basically it adds 5 for each
# recursive step, and since it always calls with one smaller, that means
# if the argument is x, then it adds 5 x times. In other words, this function
# is a recursive implementation of times-five.


# Let's actually do something a little more practical:
# QUIZ: Without using recursion, define a function called gauss(), which takes
# a non-negative integer n and returns 1+2+3+4+...+n.
def gauss1(n):
    total = 0
    while n != 0:
        total = total + n
        n = n - 1
    return total


def gauss2(n):
    numbers = range(1, n+1)
    total = 0
    for number in numbers:
        total = total + number
    return total

# There are other methods.


# Now let's do this with recursion.

# Remember from high school algebra that a natural number (nat) is a
# non-negative integer. (i.e., 0, 1, 2, 3, ...)
def gauss(n):
    """returns the sum of all integers from 1 up to n
    natural-number -> natural-number"""
    if n == 0:
        return 0  # base case. should not be recursive.
    else:
        return gauss(n-1) + n  # recursive case. we call the function again
        #  with a value that is closer to the base value

# Every recursive function needs two cases:
# A base case, where no recursion is used.
# And a recursive case, where the function is called again with a value closer
# to the base value, and usually some other calculation is done with that value

# Think about the recursive case like this:
    # If I have the answer for n-1, then how do I get the answer for n
    # gauss(n-1) represents the answer for n-1. We add n to that to get the
    # answer we want for the number n. Think of gauss(n-1) not as an instruction
    # but as the result of the calculation.

# Binary Number Trees are a kind of data, and here's how we'll represent them
# in python:

# A Binary Number Tree (BNT) is either:
# - a number, or:
# - a tuple (BNT, BNT) (a tuple of two Binary Number Trees)

# So for example, a BNT with four numbers may look like this:

tree1 = ((2, (3, 2)), 5)

# This is a recursive data definition, which uses Binary Number Trees as part
# of the definition of a Binary Number Tree.


def count_leaves(bnt):
    """returns the number of leaves in bnt
    BNT -> int"""
    if isinstance(bnt, tuple):
        # this is the recursive case
        # In this case, I have two smaller trees, the left branch and the
        # right branch
        # the left branch is: bnt[0] and the right branch is bnt[1]
        # These values are closer to the base case, because they are smaller
        # trees. So we use them as part of recursive calls:
        # count_leaves(bnt[0]) (the number of leaves in the left branch)
        # and count_leaves(bnt[1]) (the number of leaves in the right branch)
        return count_leaves(bnt[0]) + count_leaves(bnt[1])
    else:
        # Then it must be a number, so this is the base case:
        return 1
