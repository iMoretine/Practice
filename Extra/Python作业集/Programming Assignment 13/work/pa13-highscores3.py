# A201 / Fall 2017
# Programming Assignment 12
# Name :
# IU account :

# High Scores 2.0
# Demonstrates nested sequences

scores = []
# read scores from file
try:
    for line in open("scores.txt", mode='r'):
        name = line.split()[0]
        score = int(line.split()[1])
        scores.append((score, name))
except FileNotFoundError as e:
    print("File not found:", e)

choice = None
while choice != "0":

    print("""
    High Scores 2.0
    
    0 - Quit
    1 - List Scores
    2 - Add a Score
    """)

    choice = input("Choice: ")
    print()

    # exit
    if choice == "0":
        print("Good-bye.")

    # display high-score table
    elif choice == "1":
        print("High Scores\n")
        print("NAME\tSCORE")
        for entry in scores:
            score, name = entry
            print(name, "\t", score)

    # add a score
    elif choice == "2":
        name = input("What is the player's name?: ")
        score = int(input("What score did the player get?: "))
        entry = (score, name)
        scores.append(entry)
        scores.sort(reverse=True)
        scores = scores[:5]     # keep only top 5 scores

    # some unknown choice
    else:
        print("Sorry, but", choice, "isn't a valid choice.")

# save scores into file
try:
    with open("scores.txt", mode='w') as file:
        for i in scores:
            file.write(str(i[1]) + " " + str(i[0]) + "\n")
except:
    print("Cannot create file.")

input("\n\nPress the enter key to exit.")
