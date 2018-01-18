# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :


class Exceptional:
    """
    """
    def getAnInteger(self):
        """

        :return:
        """
        while True:
            try:
                num = int(input("Enter an integer:"))
            except ValueError as e:
                print("Here's what just happened: ", e)
            else:
                print("Thanks! You entered the integer value %d" % num)
                break
        pass

    def readThisFile(self):
        """

        :return:
        """
        while True:
            try:
                filename = input("Type a file name:")
                file = open(filename)
                count = 0
                num = 0.0
                for line in open(filename):
                    num += float(line)
                    count += 1
                print('The number in your file "%s"add up to: %.1f' % (filename, num))
                print('The average value of all numbers in your file is: %.1f' % (num/count))
                file.close()
            except FileNotFoundError:
                print("A file with that name can't be found. ")
            else:
                break
        pass

exc = Exceptional()
exc.getAnInteger()
# exc.readThisFile()