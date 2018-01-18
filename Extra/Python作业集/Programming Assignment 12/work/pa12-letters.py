# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

import turtle
import math

# global variables

gWindow = turtle.Screen()
gPencil = turtle.Turtle()


# draw letters

def drawLetterA(pTurtle, pSize):
    """
    Draw letter A, which has 3 strokes.
    :param pTurtle: the turtlegraphics turtle
    :param pSize: int, letter height
    :return: None
    """
    gPencil.up()

    # Letter A has 3 strokes
    stroke1_length = pSize / math.cos(math.pi / 6)
    stroke2_length = stroke1_length
    stroke3_length = stroke1_length / 2

    # Draw stroke 1
    gPencil.setheading(60)
    gPencil.forward(stroke1_length)
    gPencil.down()
    gPencil.setheading(-120)
    gPencil.forward(stroke1_length)
    gPencil.up()

    # Draw stroke 2
    gPencil.setheading(60)
    gPencil.forward(stroke1_length)
    gPencil.down()
    gPencil.setheading(-60)
    gPencil.forward(stroke2_length)
    gPencil.up()

    # Draw stroke 3
    gPencil.setheading(180)
    gPencil.forward(stroke1_length * 3 / 4)
    gPencil.setheading(90)
    gPencil.forward(pSize / 2)
    gPencil.down()
    gPencil.setheading(0)
    gPencil.forward(stroke3_length)
    gPencil.up()
    pass


def drawLetterE(pTurtle, pSize):
    """
    Draw letter E, which has 4 strokes.
    :param pTurtle: the turtlegraphics turtle
    :param pSize: int, letter height
    :return: None
    """
    gPencil.up()

    # Letter E has 4 strokes
    stroke1_length = pSize
    stroke2_length = pSize
    stroke3_length = pSize / 2
    stroke4_length = pSize

    # Draw stroke 1
    gPencil.setheading(90)
    gPencil.forward(pSize)
    gPencil.down()
    gPencil.setheading(-90)
    gPencil.forward(stroke1_length)
    gPencil.up()

    # Draw stroke 2
    gPencil.setheading(90)
    gPencil.forward(pSize)
    gPencil.down()
    gPencil.setheading(0)
    gPencil.forward(stroke2_length)
    gPencil.up()

    # Draw stroke 3
    gPencil.setheading(180)
    gPencil.forward(pSize)
    gPencil.setheading(-90)
    gPencil.forward(pSize/2)
    gPencil.down()
    gPencil.setheading(0)
    gPencil.forward(stroke3_length)
    gPencil.up()

    # Draw stroke 4
    gPencil.setheading(180)
    gPencil.forward(pSize / 2)
    gPencil.setheading(-90)
    gPencil.forward(pSize / 2)
    gPencil.down()
    gPencil.setheading(0)
    gPencil.forward(stroke4_length)
    gPencil.up()
    pass


def drawLetterI(pTurtle, pSize):
    """
    Draw letter I, which has only 1 stroke.
    :param pTurtle: the turtlegraphics turtle
    :param pSize: int, letter height
    :return: None
    """
    gPencil.up()

    # Letter I has only 1 stroke
    stroke_length = pSize

    # Draw stroke 1
    gPencil.setheading(90)
    gPencil.forward(pSize)
    gPencil.down()
    gPencil.setheading(-90)
    gPencil.forward(stroke_length)
    gPencil.up()
    pass

# main

pSize = 100

gPencil.up()
gPencil.goto(-200, 0)
drawLetterA(gPencil, pSize)

gPencil.up()
gPencil.goto(-50, 0)
drawLetterE(gPencil, 100)

gPencil.up()
gPencil.goto(100, 0)
drawLetterI(gPencil, 100)

# underline

gPencil.up()
gPencil.goto(-200, -20)
gPencil.down()

gPencil.setheading(0)
gPencil.forward(300)

turtle.done()
