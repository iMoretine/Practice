# problem 5
def converts(centi):
    inch = 0.393700
    feet = 0.032808
    yard = 0.009144
    return (centi*inch, centi*feet, centi*yard)

lis = [i*100 for i in range(10,21)]
for i in lis:
    resulttup = converts(i)
    print(str(i) + " centimeters are equal to: "
          + str(round(resulttup[0],4)) + " inches, "
          + str(round(resulttup[1],4)) + " feets, "
          + str(round(resulttup[2],4)) + " yards.")
