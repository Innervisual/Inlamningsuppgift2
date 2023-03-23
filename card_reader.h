#ifndef CARD_READER_H
#define CARD_READER_H
#include <stdbool.h>

typedef struct {
    int cardNumber;
    bool access;
    char timeAddedStr[26];
} Card;

typedef struct {
    Card *cards;
    int count;
    int capacity;
} CardsList;

int waitForInputWithTimeout(int milliseconds);

void readCardList(CardsList *cardsList);
void initCardsList(CardsList *cardsList);
void freeCardsList(CardsList *cardsList);
void addCard(Card *card, CardsList *cardsList);
void addCardToFile(Card *card);
void listAllCards(CardsList *cardsList);
void printCardDetails(Card *card);
Card *findCard(int cardNum, CardsList *cardsList);
void updateCardInFile(Card *card);
void delay(int seconds);

#endif // CARD_READER_H

