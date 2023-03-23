#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "card_reader.h"

void printCardDetails(Card *card) {
    printf("Card number: %04d\n", card->cardNumber);
    printf("Access: %s\n", card->access ? "Yes" : "No");
    printf("Added to system: %s\n", card->timeAddedStr);
}

Card *findCard(int cardNum, CardsList *cardsList) {
    for (int i = 0; i < cardsList->count; i++) {
        if (cardNum == cardsList->cards[i].cardNumber) {
            return &cardsList->cards[i];
        }
    }
    return NULL;
}

void addCardToFile(Card *card) {
    FILE *file = fopen("cards.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%04d %d %s\n", card->cardNumber, card->access, card->timeAddedStr);
    fclose(file);
}

void updateCardInFile(Card *card) {
    FILE *file = fopen("cards.txt", "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    int cardNum;
    bool access;
    char timeAddedStr[26];
    while (fscanf(file, "%d %d %s", &cardNum, &access, timeAddedStr) != EOF) {
        if (cardNum == card->cardNumber) {
            fseek(file, -26, SEEK_CUR);
            fprintf(file, "%04d %d %s", card->cardNumber, card->access, card->timeAddedStr);
            break;
        }
    }
    fclose(file);
}

void readCardList(CardsList *cardsList) {
    FILE *file = fopen("cards.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    Card card;
    while (fscanf(file, "%d %d %s", &card.cardNumber, &card.access, card.timeAddedStr) != EOF) {
        if (cardsList->count == cardsList->capacity) {
            cardsList->capacity *= 2;
            cardsList->cards = realloc(cardsList->cards, sizeof(Card) * cardsList->capacity);
        }
        cardsList->cards[cardsList->count] = card;
        cardsList->count++;
    }
    fclose(file);
}

void initCardsList(CardsList *cardsList) {
    cardsList->count = 0;
    cardsList->capacity = 10;
    cardsList->cards = malloc(sizeof(Card) * cardsList->capacity);
}

// ... (rest of the code remains the same)

void delay(int milliseconds) {
    // Add the implementation for the delay function
}

void listAllCards(CardsList *cardsList) {
    // Add the implementation for the listAllCards function
}

void addCard(Card *card, CardsList *cardsList) {
    // Add the implementation for the addCard function
}

void freeCardsList(CardsList *cardsList) {
    // The freeCardsList function is not necessary as the CardsList struct doesn't use dynamic memory allocation
    // You can remove references to this function from the rest of the code
}

