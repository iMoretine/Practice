import itertools

# Morse code mapping table.
morseMap = {'.-':'A',
            '-...':'B',
            '-.-.':'C',
            '-..':'D',
            '.':'E',
            '..-.':'F',
            '--.':'G',
            '....':'H',
            '..':'I',
            '.---':'J',
            '-.-':'K',
            '.-..':'L',
            '--':'M',
            '-.':'N',
            '---':'O',
            '.--.':'P',
            '--.-':'Q',
            '.-.':'R',
            '...':'S',
            '-':'T',
            '..-':'U',
            '...-':'V',
            '.--':'W',
            '-..-':'X',
            '-.--':'Y',
            '--..':'Z',
            '.----':'1',
            '..---':'2',
            '...--':'3',
            '....-':'4',
            '.....':'5',
            '-....':'6',
            '--...':'7',
            '---..':'8',
            '----.':'9',
            '-----':'0'}


def morseDecode(inputStringList):
    """
    This method should take a list of strings as input. Each string is equivalent to one letter
    (i.e. one morse code string).
    The entire list of strings represents a word.
    This method should convert the strings from morse code into english, and return the word as a string
    """
    # Translate every letter in inputStringList.
    word = ""
    for letter in inputStringList:
        word += morseMap[letter]
    return word


def morsePartialDecode(inputStringList):
    """
    This method should take a list of strings as input. Each string is equivalent to one letter
    (i.e. one morse code string).
    The entire list of strings represents a word.
    However, the first character of every morse code string is unknown (represented by an 'x' (lowercase))
    For example, if the word was originally TEST, then the morse code list string would normally be:
    ['-','.','...','-']
    However, with the first characters missing, I would recieve:
    ['x','x','x..','x']

    With the x unknown, this word could be TEST, but it could also be EESE or ETSE or ETST or EEDT or other permutations.
    To narrow it down, this function should find and return a list of strings of all possible VALID words.
    We define a valid words as one that exists within the dictionary file provided on the website, dictionary.txt
    When using this file, please always use the location './dictionary.txt' and place it in the same directory as
    the python script.
    """

    # Open the file and extract its contents as a list of valid words
    dictionaryFileLoc = './dictionary.txt'
    file = open(dictionaryFileLoc, 'r')
    validWordsList = [word.upper() for word in file.read().split()]
    file.close()

    # Convert the list of valid words into a set for increasing search rate
    validWordsSet = set(validWordsList)

    # Enumerate each combination of letters in inputStringList
    wordsList = ['']
    for letter in inputStringList:
        letter1 = '.' + letter[1:]
        letter2 = '-' + letter[1:]
        if letter1 in morseMap and letter2 not in morseMap:
            wordsList = [ word+morseMap[letter1] for word in wordsList ]
        if letter1 not in morseMap and letter2 in morseMap:
            wordsList = [ word+morseMap[letter2] for word in wordsList ]
        if letter1 in morseMap and letter2 in morseMap:
            wordsList = [ word+morseMap[letter1] for word in wordsList ] + [ word+morseMap[letter2] for word in wordsList ]

    # Find the valid words
    resultWordslist = []
    for word in wordsList:
        if word in validWordsSet:
            resultWordslist.append(word)
    return resultWordslist


class Maze:
    def __init__(self):
        """
        Constructor - You may modify this, but please do not add any extra parameters
        """
        # The maze
        self.maze = [['*']]
        # The width of maze
        self.width = 1
        # The height of maze
        self.height = 1

        # Route from a position to another position, it's used in function "route"
        self.__path = []
        # Record the positions that have been tried, it's used in function "route"
        self.__triedSet = set()
        pass

    def addCoordinate(self, x, y, blockType):
        """
        Add information about a coordinate on the maze grid
        x is the x coordinate
        y is the y coordinate
        blockType should be 0 (for an open space) of 1 (for a wall)
        """
        # if the x-coordinate is greater than the width of maze, extend the maze.
        if x >= self.width:
            for i, row in enumerate(self.maze):
                self.maze[i] = row + ['*' for t in range(x-self.width+1)]
            self.width = x+1

        # if the y-coordinate is greater than the height of maze, extend the maze.
        if y >= self.height:
            newline = ['*' for i in range(self.width)]
            self.maze = self.maze + [newline for t in range(y-self.height+1)]
            self.height = y+1

        # Set the content of the position
        if blockType == 0:
            self.maze[y][x] = ' '
        else:
            self.maze[y][x] = '*'

    def printMaze(self):
        """
        Print out an ascii representation of the maze.
        A * indicates a wall and a empty space indicates an open space in the maze
        """
        # Print the maze
        for row in self.maze:
            for i in row:
                print i,
            print

    def route(self, currentPos, targetPos):
        # Reach the target
        if currentPos == targetPos:
            return True

        # record the last position
        lastPos = None
        if len(self.__path) >= 2:
            lastPos = self.__path[-2]

        # Add current position to the triedSet
        self.__triedSet.add(currentPos)
        upPos = (currentPos[0], currentPos[1] - 1)
        downPos = (currentPos[0], currentPos[1] + 1)
        leftPos = (currentPos[0] - 1, currentPos[1])
        rightPos = (currentPos[0] + 1, currentPos[1])

        # Find every possible route
        if upPos not in self.__triedSet and 0 <= upPos[1] < self.height and self.maze[upPos[1]][upPos[0]] == ' ':
            currentPos = upPos
            self.__path.append(currentPos)
            if self.route(currentPos, targetPos):
                return True
            self.__path.pop()

        if downPos not in self.__triedSet and 0 <= downPos[1] < self.height and self.maze[downPos[1]][downPos[0]] == ' ':
            currentPos = downPos
            self.__path.append(currentPos)
            if self.route(currentPos, targetPos):
                return True
            self.__path.pop()

        if leftPos not in self.__triedSet and 0 <= leftPos[0] < self.width and self.maze[leftPos[1]][leftPos[0]] == ' ':
            currentPos = leftPos
            self.__path.append(currentPos)
            if self.route(currentPos, targetPos):
                return True
            self.__path.pop()

        if rightPos not in self.__triedSet and 0 <= rightPos[0] < self.width and self.maze[rightPos[1]][rightPos[0]] == ' ':
            currentPos = rightPos
            self.__path.append(currentPos)
            if self.route(currentPos, targetPos):
                return True
            self.__path.pop()

        # Remove last path in tried set, take a step back
        if lastPos in self.__triedSet:
            self.__triedSet.remove(lastPos)
        return False

    def findRoute(self,x1,y1,x2,y2):
        """
        This method should find a route, traversing open spaces, from the coordinates (x1,y1) to (x2,y2)
        It should return the list of traversed coordinates followed along this route as a list of tuples (x,y),
        in the order in which the coordinates must be followed
        If no route is found, return an empty list
        """
        # Current position and target positon
        currentPos = (x1,y1)
        targetPos = (x2,y2)

        # Route
        self.__path.append(currentPos)

        # Empty the triedSet.
        self.__triedSet = set()

        # Ecursive calls to the Route function
        if self.route(currentPos, targetPos):
            return self.__path
        else:
            return []


def morseCodeTest():
    """
    This test program passes the morse code as a list of strings for the word
    HELLO to the decode method. It should receive a string "HELLO" in return
    """

    hello = ['....','.','.-..','.-..','---']
    print morseDecode(hello)


def partialMorseCodeTest():

    """
    This test program passes the partial morse code as a list of strings
    to the morsePartialDecode method
    """

    # This is a partial representation of the word TEST, amongst other possible combinations
    test = ['x','x','x..','x']
    print morsePartialDecode(test)

    # This is a partial representation of the word DANCE, amongst other possible combinations
    dance = ['x..','x-','x.','x.-.','x']
    print morsePartialDecode(dance)


def mazeTest():
    """
    This sets the open space coordinates for the example
    maze in the assignment.
    The remainder of coordinates within the max bounds of these specified coordinates
    are assumed to be walls
    """
    myMaze = Maze()
    myMaze.addCoordinate(1,0,0)
    myMaze.addCoordinate(1,1,0)
    myMaze.addCoordinate(7,1,0)
    myMaze.addCoordinate(1,2,0)
    myMaze.addCoordinate(2,2,0)
    myMaze.addCoordinate(3,2,0)
    myMaze.addCoordinate(4,2,0)
    myMaze.addCoordinate(6,2,0)
    myMaze.addCoordinate(7,2,0)
    myMaze.addCoordinate(4,3,0)
    myMaze.addCoordinate(7,3,0)
    myMaze.addCoordinate(4,4,0)
    myMaze.addCoordinate(7,4,0)
    myMaze.addCoordinate(3,5,0)
    myMaze.addCoordinate(4,5,0)
    myMaze.addCoordinate(7,5,0)
    myMaze.addCoordinate(1,6,0)
    myMaze.addCoordinate(2,6,0)
    myMaze.addCoordinate(3,6,0)
    myMaze.addCoordinate(4,6,0)
    myMaze.addCoordinate(5,6,0)
    myMaze.addCoordinate(6,6,0)
    myMaze.addCoordinate(7,6,0)
    myMaze.addCoordinate(5,7,0)

    myMaze.printMaze()
    print myMaze.findRoute(1,0,5,7)

morseCodeTest()
partialMorseCodeTest()
mazeTest()
