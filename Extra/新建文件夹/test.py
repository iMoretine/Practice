def isEeven(num):
    """
    returns True if the integer is even, False otherwise.
    :param num: int
    :return: bool
    """
    return num % 2 == 0

# print(isEeven(3))


import random


def guessNumber():
    num = random.randrange(1, 100)
    print("I'm thinking of a number between 1 and 100."
          "Try to guess it in as few attempts as possible.")

    count = 0
    while True:
        count += 1
        print("Take a guess: ")
        guess = int(input())
        if guess > num:
            print("higher...")
        if guess < num:
            print("Lower...")
        if guess == num:
            print("You guessed it! The number was %d" % num)
            print("And it only took you 7 tries!")
            break
    pass

# guessNumber()