#ifndef CARD_READER_H
#define CARD_READER_H
#include <stdbool.h>

typedef struct {
    int cardNumber;
    int access; // Change this line
    char timeAddedStr[26];
} Card;

typedef struct {
    Card *cards;
    int count;
    int capacity;
} CardsList;

typedef enum {
    LAMP_OFF,
    LAMP_GREEN,
    LAMP_RED
} LampStatus;

int waitForInputWithTimeout(int milliseconds);

void printLampStatus(LampStatus status);
//void readCardList(CardsList *cardsList);
void readCardList(CardsList *cardsList, const char *filename);
void initCardsList(CardsList *cardsList);
void freeCardsList(CardsList *cardsList);
void addCard(Card *card, CardsList *cardsList);
//void addCardToFile(Card *card);
void addCardToFile(Card *card, const char *filename);
void listAllCards(CardsList *cardsList);
void printCardDetails(Card *card);
Card *findCard(int cardNum, CardsList *cardsList);
void updateCardInFile(Card *card);
void delay(int seconds);

#endif // CARD_READER_H

