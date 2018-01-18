# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

from math import sqrt
from turtle import *

penup()
hideturtle()


# Definition for class Point
class Point:
    """
    Representing a point on a 2D surface,
    include x- and y- coordinates and color
    """
    def __init__(self, x=0, y=0, color="black"):
        """
        constructor method
        :param x: int, x-coordinates
        :param y: int, y-coordinates
        :param color: str, color
        """
        self.x = x
        self.y = y
        self.color = color
        pass

    def __repr__(self):
        """
        A string to represent this Point
        :return: str
        """
        return "Point(%d, %d, '%s')" % (self.x, self.y, self.color)

    def horizontal_move(self, increment):
        """
        Move this point vertically
        :param increment: distance
        :return: None
        """
        self.x += increment
        pass

    def vertical_move(self, increment):
        """
        Move this point horizontally
        :param increment: distance
        :return: None
        """
        self.y += increment
        pass

    def distant_from(self, point):
        """
        Compute the distance between this point and a given point.
        :param point: Point
        :return: float, distance between this point and a given point.
        """
        return sqrt(abs(point.x-self.x)**2 + abs(point.y-self.y)**2)

    def draw(self):
        """
        Draws this point with the coordinates and a default 4-pixel diameter.
        :return: None
        """
        goto(self.x, self.y)
        dot(4, self.color)


# main program

print("Instantiating a Point object, in a variable named point1, "
      "at coordinates (10,20) with color black")
point1 = Point(10, 20, "black")
print("point1 has now become: " + repr(point1))

print("Instantiating a Point object, in a variable named point1, "
      "at coordinates (40,30) with color purple")
point2 = Point(40, 30, "purple")
print("point2 has now become: " + repr(point2))

print("The point1 is being moved by 15 units to the top")
point1.vertical_move(15)
print("point1 has now become: " + repr(point1))

print("The point2 is being moved by 25 units to the right")
point2.horizontal_move(25)
print("point2 has now become: " + repr(point2))

print("The point1 is being changed color to blue")
point1.color = "blue"
print("point1 has now become: " + repr(point1))

print("Compute the distance between point1 and point2")
print("The distance between point1 and point2 is %.2f"
      % point1.distant_from(point2))
print("point1 has now become: " + repr(point1))
print("point2 has now become: " + repr(point2))

print("Draw point1 and point2.")
point1.draw()
point2.draw()
print("point1 has now become: " + repr(point1))
print("point2 has now become: " + repr(point2))

done()
