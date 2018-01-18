# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

import turtle

# global variables

gWindow = turtle.Screen()
gPencil = turtle.Turtle()


# histogram data

def string_to_hist(string):
    """
    :param string: str, include contents
    :return: dict, letter frequencies in string
    """
    data = dict()
    for i in string:
        if i in data:
            data[i] += 1
        else:
            data[i] = 1
    return data

#

def drawBlock(pTurtle, pWidth, pHeight):
    """
    :param pTurtle:
    :param pWidth:
    :param pHeight:
    :return:
    """
    # Draw block
    gPencil.down()
    gPencil.setheading(90)
    gPencil.forward(pHeight)
    gPencil.setheading(0)
    gPencil.forward(pWidth)
    gPencil.setheading(-90)
    gPencil.forward(pHeight)
    gPencil.setheading(180)
    gPencil.forward(pWidth)
    gPencil.up()
    pass

# main

s = "I have never seen a purple cow, And I never hope to see one. " \
    "But I can tell you anyhow, I'd rather see than be one."
data = string_to_hist(s)

gPencil.speed("fastest")
gPencil.up()
gPencil.goto(-100, -50)

for i in data:
    drawBlock(gPencil, 5, data[i]*10)
    gPencil.up()
    gPencil.setheading(0)
    gPencil.forward(7)

turtle.done()
