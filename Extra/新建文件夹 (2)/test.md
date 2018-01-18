1
(a) line "ec1 = ExamClass()" define instance of the ExamClass class

(b) ExamClass have 4 method, the signatures of those method are:
    __init__()
    __str__()
    f(num)
    g(str) of g(int)
    
(c) Attributes of ExamClass:
    a - int
    b - str

(d) The screen will displayed:
teacup7
6
teacup7
teacup4
1
teacup4
teacupskicup
teacup4


2
(a) 1. multiline comment
   2. docstring for a method or a class

(b) 1. class is static, instance is dynamic.
   2. There could be many instances with different attribute values of a same class. But for this class, there are only one class in the program  .

(c) 1. Encapsulation makes the program clearer 
   2.  Encapsulation makes the program more convenient for management


3
(a) These are built-in immutable sequence types:
    tuple
    string
    int

(b) These are built-in mutable sequence types:
    dict
    list
    
(c) q could be:
    tuple
    string
    dict
    list
    
(d) 1.the sort() method of list:
    l = [2,3,1,5]
    l.sort()
    
    2.the insert() method of list:
    l = [2,3,1,5]
    l.insert(4)
    
    3.the pop() method of list:
    l = [2,3,1,5]
    l.pop()
    
(f) i. These functions have side effects, because all these functions change the object l.
    1.the sort() method of list:
    l = [2,3,1,5]
    l.sort()
    
    2.the insert() method of list:
    l = [2,3,1,5]
    l.insert(2,3)
    
    3.the pop() method of list:
    l = [2,3,1,5]
    l.pop()
    
    4.the remove() method of list:
    l = [2,3,1,5]
    l.remove(5)
    
ii. These functions have no side effects, because all these functions doesn't change the object l.
    1.the count() method of list:
    l = [2,3,1,5]
    l.count(2)
    
    2.the index() method of list:
    l = [2,3,1,5]
    l.index(2)
    
    3.the __str__() method of list:
    l = [2,3,1,5]
    print(str(l))
    
    4.the __repr__() method of list:
    l = [2,3,1,5]
    print(repr(l))
    

4

(a)Returns a boolean value True
(b)Returns a string "timemachine"
(c)name of p1 is changed from "TimeMachine" to "Slowest"
(d)Returns a new list [3]
(e)"y":True of d1 is deleted
(f)Value 4 of l1 is deleted
(g)Returns a tuple ("c", 0.0) 
(h)Returns a float number 0.5
(i)Raise an TypeError: 'tuple' object does not support item assignment 

5.It will print the content below on the screen:
1
They dined on mince, and slices of quince,

2
Which they ate a runcible spoon.

3
And hand in hand, on the edge of the sand.
They danced by the light of the moon, the moon, the moon,
They danced by the light of the moon.

6.
(a)def r(x): is the header of this function.
(b)x==1 is the base case in the definition.
(c)0 and every negative integers will cause this function raise an error.
(d)Command r(5) will return string "2345".

7.
(a)
numbers.append(5)
numbers.append(10)
(b)
for i in range(3):
    my_items.pop()
(c)
copy_list = list3[10:]
(d)
while 3 in scores:
    scores.remove(3)
(e)
num_words = {"1":"one","2":"two","3":"three"}
(f)
adictionary["age"] = 200
(g)
def func(scrabble):
    if "K"  in scrabble:
        return scrabble["K"]
    else:
        return 0
        


sd
8
(a)1.the sort() method of list:
    l = [2,3,1,5]
    l.sort()
    
    2.the insert() method of list:
    l = [2,3,1,5]
    l.insert(2,3)
    
    3.the pop() method of list:
    l = [2,3,1,5]
    l.pop()
(b)1.the count() method:
    l = [2,3,1,5]
    l.count(2)
   2. len() method
   3. clear() method
   
(c)1.the sort() method of list:
    l = [2,3,1,5]
    l.sort()
    
    2.the insert() method of list:
    l = [2,3,1,5]
    l.insert(2,3)
    
    3.the pop() method of list:
    l = [2,3,1,5]
    l.pop()
    
asdf

(a)float number
(b)integer
(c)boolean
(d)Car object
(e)string
(f)integer
(g)tuple of booleans
(h)error
(i)None
(j)file object
(k)boolean
(l)float number
(m)dict
(n)boolean


(a)
def func1(my_list):
    while "Q" in my_list:
        my_list.remove("Q")
(b)
def func2(my_dict):
    my_list = [i for i in my_dict]
    return my_list
(c)
def func3(my_dict):
    high = None
    high_index = None
    for i,v in my_dict:
        if hign != None and v > high
        high = v
        high_index = i
    if hign != None:
        del my_dict[high_index]
(d)
def func3(my_dict):
    my_list = [v for i,v in my_dict]
    return my_list
(e)
def func4(number):
    return number % 1 
(f)
def func6(my_str):
    for i in range(10):
        if str(i) in my_str:
            return my_str.strip(str(i))
    