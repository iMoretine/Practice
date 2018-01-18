# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

from turtle import *


def sierpinski(length):
    if length < 7:
        forward(length)
        left(120)
        forward(length)
        left(120)
        forward(length)
        left(120)
    else:
        sierpinski(length/2)
        forward(length/2)

        sierpinski(length/2)
        left(120)
        forward(length/2)
        right(120)

        sierpinski(length/2)
        right(120)
        forward(length/2)
        left(120)

# main program
speed(0)
penup()
setpos(-300, -300)
pendown()
sierpinski(600)
done()
