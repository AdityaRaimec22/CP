import random

class Cards:

    def __init__(self,suit,value):
        self.suit = suit
        self.value = value
        
    def __str__(self):
        return f"{self.value} of {self.suit}" 

class Deck:

    def __init__(self):
        self.cards = []
        for suit in ["Hearts", "Diamonds", "Clubs", "Spades"]:
            for value in ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]:
                card = Cards(suit,value)
                self.cards.append(card)
        self.shuffle()

    def shuffle(self):
        random.shuffle(self.cards)

    def deal(self):
        if len(self.cards) == 0:
            return None
        return self.cards.pop()
    
    def __str__(self):
        return f"number of cards remaining in the deck are - {len(self.cards)}"
    
deck = Deck()
print(deck)  # Deck of 52 cards

card = deck.deal()
print(card)  # 7 of Spades

print(deck)  # Deck of 51 cards

deck.shuffle()

card = deck.deal()
print(card)  # Q of Clubs

print(deck)  # Deck of 50 cards
