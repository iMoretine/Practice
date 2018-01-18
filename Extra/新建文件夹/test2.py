import random


class Card:
    """
    :__point: the value of card
    :__suit: the suit of card
    """
    # suit:
    # Snakes - s
    # Hamsters - h
    # Cats - c
    # Weasels - w

    # card:
    # 2 - 0 - 2
    # 4 - 0 - 4
    # 5 - 0 - 5
    # 6 - 0 - 6
    # 7 - 0 - 7
    # Pawn - 2 - P
    # King - 3 - K
    # Queen - 4 - Q
    # Fortress - 10 - E
    # Ace - 11 - A

    def __init__(self, value, suit):
        value = str(value)
        self.__value = value[0].lower()
        self.__points = 0
        if value[0].lower() == "2":
            self.__points = 0
        if value[0].lower() == "4":
            self.__points = 0
        if value[0].lower() == "5":
            self.__points = 0
        if value[0].lower() == "6":
            self.__points = 0
        if value[0].lower() == "7":
            self.__points = 0
        if value[0].lower() == "p":
            self.__points = 2
        if value[0].lower() == "k":
            self.__points = 3
        if value[0].lower() == "q":
            self.__points = 4
        if value[0].lower() == "f":
            self.__points = 10
        if value[0].lower() == "a":
            self.__points = 11

        # suits
        self.suit = 's'
        if suit[0].lower() == "s":
            self.suit = 's'
        if suit[0].lower() == "h":
            self.suit = 'h'
        if suit[0].lower() == "c":
            self.suit = 'c'
        if suit[0].lower() == "w":
            self.suit = 'w'
        pass

    def __str__(self):
        """
        :return: str, representation of card
        """
        return "Card(%s, %s)" % (self.__value, self.suit)

    def greater(self, other):
        """
        Compare with another card.
        :param other: another card
        :return: bool, greater of not
        """
        if self.__points > other.__points:
            return True
        return False

# deck of cards
myDeck = [Card("Pawn", "Snakes"),
          Card("King", "Snakes"),
          Card("Queen", "Hamsters"),
          Card("4", "Cats"),
          Card("Ace", "Cats"),
          Card("7", "Snakes")]


def deckString(pDeck):
    """
    return a str representation of a deck of card
    :param pDeck: a list ot card
    :return: str, representation of a deck of card
    """
    cards_str = ""
    for card in pDeck:
        cards_str += card.__str__() + "\n"
    return cards_str


def deckShuffle(pDeck):
    """
    return a shuffle deck of cards
    :param pDeck: list, a deck of cards
    :return: list, a shuffle deck of cards
    """
    random.shuffle(pDeck)
    return pDeck


def dealCard(pDeck):
    """
    Extrack the first card from a deck of cards.
    :param pDeck: list, a deck of cards
    :return: Card, the first card
    """
    if len(pDeck) != 0:
        card = pDeck[-1]
    else:
        return
    pDeck.pop()
    return card

# main program

print('*** welcome to the cards "battle" game *** ')
print()
print("I'm going to get a new deck of cards, here it is:")
print(deckString(myDeck))
deckShuffle(myDeck)
print("Now I've shuffled the deck of cards, it is now:")
print(deckString(myDeck))
print("And now I'm going to deal a card to select the 'super' suit:")
firstcard = dealCard(myDeck)
super = firstcard.suit
print("The card is %s, the super suit is :%s" % (firstcard, super))

playercard = dealCard(myDeck)
dealercard = dealCard(myDeck)
print(len(myDeck))
print()
print("Let's deal cards for the two players.")
print("The player's card is %s " % playercard.__str__())
print("The dealer's card is %s " % dealercard.__str__())

if playercard.suit == super and dealercard.suit != super:
    print("Player Win!")
elif playercard.suit != super and dealercard.suit == super:
    print("Player Lose!")
else:
    if playercard.greater(dealercard):
        print("Player Win!")
    else:
        print("Player Lose!")
