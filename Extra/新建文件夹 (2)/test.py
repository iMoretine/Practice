# class EC:
#     def __init__(self):
#         self.a = 0
#         self.b = ""
#
#     def __str__(self):
#         return self.a + str(self.b)
#
#     def f(self, x):
#         self.b = self.b - x
#
#     def g(self, x):
#         if isinstance(x, str):
#             return self.a + x
#         else:
#             return self.b - x
#
# ec1 = EC()
# ec1.a = "teacup"
# ec1.b = 7
# print(ec1)
# print(ec1.b - 1)
# print(ec1)
# ec1.f(3)
# print(ec1)
# ec1.g(3)
# print(ec1.g(3))
# print(ec1)
# print(ec1.g("skicup"))
# print(ec1)

class Car:
    def __init__(self,n,m):
        self.name = n
        self.mileage = m

car1 = Car("TimeMachine", 200)
dict1 = {"x":True, "y":True, "z":False}
l1 = [5,4,3,2,2]
l2 = [("a",1.5),("b",0.5),("c",0.0)]
#
# print(True and not False)
# print(p1.name.lower())
# p1.name = "Slowest"
# print(l1[2:3])
# del d1["y"]
# l1.remove(4)
# print(l1)
# l2[0][0]= "x"

# file = open("test.txt")
# print('1')
# print(file.readline())
# print('2')
# print(file.readline())
# print('3')
# print(file.read())

# def r(x):
#     if x==1:
#         return ""
#     else:
#         return r(x-1)+str(x)
#
# print(r(5))

print(dict1.copy())